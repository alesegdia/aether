#include "gl_application.h"
#include "sdl_keycode.h"
#include "aether/core/logger.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_video.h>
#include <SDL_opengl.h>

namespace aether::core {

        void GLAPIENTRY
            MessageCallback(GLenum source, GLenum type, GLuint id,
                GLenum severity, GLsizei length,
                const GLchar* msg, const void* data)
        {
            const char* _source;
            const char* _type;
            const char* _severity;

            switch (source) {
            case GL_DEBUG_SOURCE_API:
                _source = "API";
                break;

            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                _source = "WINDOW SYSTEM";
                break;

            case GL_DEBUG_SOURCE_SHADER_COMPILER:
                _source = "SHADER COMPILER";
                break;

            case GL_DEBUG_SOURCE_THIRD_PARTY:
                _source = "THIRD PARTY";
                break;

            case GL_DEBUG_SOURCE_APPLICATION:
                _source = "APPLICATION";
                break;

            case GL_DEBUG_SOURCE_OTHER:
                _source = "UNKNOWN";
                break;

            default:
                _source = "UNKNOWN";
                break;
            }

            switch (type) {
            case GL_DEBUG_TYPE_ERROR:
                _type = "ERROR";
                break;

            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                _type = "DEPRECATED BEHAVIOR";
                break;

            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                _type = "UDEFINED BEHAVIOR";
                break;

            case GL_DEBUG_TYPE_PORTABILITY:
                _type = "PORTABILITY";
                break;

            case GL_DEBUG_TYPE_PERFORMANCE:
                _type = "PERFORMANCE";
                break;

            case GL_DEBUG_TYPE_OTHER:
                _type = "OTHER";
                break;

            case GL_DEBUG_TYPE_MARKER:
                _type = "MARKER";
                break;

            default:
                _type = "UNKNOWN";
                break;
            }

            switch (severity) {
            case GL_DEBUG_SEVERITY_HIGH:
                _severity = "HIGH";
                break;

            case GL_DEBUG_SEVERITY_MEDIUM:
                _severity = "MEDIUM";
                break;

            case GL_DEBUG_SEVERITY_LOW:
                _severity = "LOW";
                break;

            case GL_DEBUG_SEVERITY_NOTIFICATION:
                _severity = "NOTIFICATION";
                break;

            default:
                _severity = "UNKNOWN";
                break;
            }

            printf("[%d]: %s of %s severity, raised from %s: %s\n",
                id, _type, _severity, _source, msg);
        }



        GLApplication::GLApplication(int sw, int sh)
            : ApplicationBase(sw, sh)
        {

        }

        int GLApplication::Init(const CommandLineArguments& args)
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                Logger::LogError("Failed to initialize SDL video.");
                return -1;
            }
            else
            {
                Logger::LogMsg("SDL video initialized successfully.");
            }


            //SDL_GL_LoadLibrary(nullptr);

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

            m_window = SDL_CreateWindow("WindowName",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                GetApplicationWindowScreenWidth(),
                GetApplicationWindowScreenHeight(),
                SDL_WINDOW_OPENGL);

            if (!m_window) {
                fprintf(stderr, "failed to create display! %s\n", SDL_GetError());
                return -1;
            }

            glContext = SDL_GL_CreateContext(m_window);
            
            int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
            gladInstallGLDebug();

            printf("GLAD GL Version: %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

            if (glContext == NULL)
            {
                fprintf(stderr, "failed to create GL context! %s\n", SDL_GetError());
                return -1;
            }

            printf("Vendor:   %s\n", glGetString(GL_VENDOR));
            printf("Renderer: %s\n", glGetString(GL_RENDERER));
            printf("Version:  %s\n", glGetString(GL_VERSION));

            // Use v-sync
            // SDL_GL_SetSwapInterval(1);

            // Disable depth test and face culling.
            // glDisable(GL_DEPTH_TEST);
            // glDisable(GL_CULL_FACE);

            glEnable(GL_DEBUG_OUTPUT);
            glDebugMessageCallback(MessageCallback, 0);

            /*
            int w, h;
            SDL_GetWindowSize(m_window, &w, &h);
            glViewport(0, 0, w, h);
            glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
            */

            // initialize input
            //Input::Initialize();

            return 0;
        }

        void GLApplication::PreRender()
        {

        }

        void GLApplication::PostRender()
        {
            SDL_GL_SwapWindow(m_window);
        }

        void GLApplication::Deinit()
        {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
        }

        void GLApplication::PreUpdate()
        {
            SDL_Event ev;
            while (SDL_PollEvent(&ev))
            {
                if (ev.type == SDL_QUIT)
                {
                    Close();
                }
                else if (ev.type == SDL_KEYDOWN)
                {
                    _notify_key_down((KeyCode)ev.key.keysym.scancode);
                }
                else if (ev.type == SDL_KEYUP)
                {
                    _notify_key_up((KeyCode)ev.key.keysym.scancode);
                }
                else if (ev.type == SDL_MOUSEBUTTONDOWN)
                {
                    _notify_mouse_button_down((MouseButton)ev.button.button);
                }
            }

            // setup mouse state
            int x, y;
            auto buttons = SDL_GetMouseState(&x, &y);
            MouseState& aether_mouse_state = _get_mouse_state();
            aether_mouse_state.x = x;
            aether_mouse_state.y = y;
            aether_mouse_state.buttons = buttons;
        }

        void GLApplication::PostUpdate()
        {
            _input_post_update();
        }

        void GLApplication::GrabMouse()
        {
            SDL_SetWindowGrab(m_window, SDL_TRUE);
        }

}
