#pragma once

#include "aether/core/applicationbase.h"
#include "SDL.h"
#include <glad/gl.h>

#include "../input.h"

namespace aether {
    namespace core {


        class GLApplication : public ApplicationBase
        {
        public:
            GLApplication(int sw, int sh);
            virtual ~GLApplication()
            {

            }

            virtual void GrabMouse() final;
            virtual void UngrabMouse() final
            {

            }


        protected:
            int Init(const CommandLineArguments& args) final;

        private:
            SDL_Window* m_window = NULL;
            SDL_GLContext glContext;

        protected:
            void Deinit();
            void PreUpdate() final;
            void PostUpdate() final;
            void PreRender() final;
            void PostRender() final;


        };

        typedef GLApplication Application;


    }
}
