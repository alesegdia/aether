ALLEGRO_SRC_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/allegro.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap_draw.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap_io.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap_lock.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap_pixel.c"),
    path.join(AETHER_DIR, "module/allegro/src/bitmap_type.c"),
    path.join(AETHER_DIR, "module/allegro/src/blenders.c"),
    path.join(AETHER_DIR, "module/allegro/src/clipboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/config.c"),
    path.join(AETHER_DIR, "module/allegro/src/convert.c"),
    path.join(AETHER_DIR, "module/allegro/src/cpu.c"),
    path.join(AETHER_DIR, "module/allegro/src/debug.c"),
    path.join(AETHER_DIR, "module/allegro/src/display.c"),
    path.join(AETHER_DIR, "module/allegro/src/display_settings.c"),
    path.join(AETHER_DIR, "module/allegro/src/drawing.c"),
    path.join(AETHER_DIR, "module/allegro/src/dtor.c"),
    path.join(AETHER_DIR, "module/allegro/src/events.c"),
    path.join(AETHER_DIR, "module/allegro/src/evtsrc.c"),
    path.join(AETHER_DIR, "module/allegro/src/exitfunc.c"),
    path.join(AETHER_DIR, "module/allegro/src/file.c"),
    path.join(AETHER_DIR, "module/allegro/src/file_slice.c"),
    path.join(AETHER_DIR, "module/allegro/src/file_stdio.c"),
    path.join(AETHER_DIR, "module/allegro/src/fshook.c"),
    path.join(AETHER_DIR, "module/allegro/src/fshook_stdio.c"),
    path.join(AETHER_DIR, "module/allegro/src/fullscreen_mode.c"),
    path.join(AETHER_DIR, "module/allegro/src/haptic.c"),
    path.join(AETHER_DIR, "module/allegro/src/inline.c"),
    path.join(AETHER_DIR, "module/allegro/src/joynu.c"),
    path.join(AETHER_DIR, "module/allegro/src/keybdnu.c"),
    path.join(AETHER_DIR, "module/allegro/src/libc.c"),
    path.join(AETHER_DIR, "module/allegro/src/math.c"),
    path.join(AETHER_DIR, "module/allegro/src/memblit.c"),
    path.join(AETHER_DIR, "module/allegro/src/memdraw.c"),
    path.join(AETHER_DIR, "module/allegro/src/memory.c"),
    path.join(AETHER_DIR, "module/allegro/src/monitor.c"),
    path.join(AETHER_DIR, "module/allegro/src/mousenu.c"),
    path.join(AETHER_DIR, "module/allegro/src/mouse_cursor.c"),
    path.join(AETHER_DIR, "module/allegro/src/path.c"),
    path.join(AETHER_DIR, "module/allegro/src/pixels.c"),
    path.join(AETHER_DIR, "module/allegro/src/shader.c"),
    path.join(AETHER_DIR, "module/allegro/src/system.c"),
    path.join(AETHER_DIR, "module/allegro/src/threads.c"),
    path.join(AETHER_DIR, "module/allegro/src/timernu.c"),
    path.join(AETHER_DIR, "module/allegro/src/tls.c"),
    path.join(AETHER_DIR, "module/allegro/src/touch_input.c"),
    path.join(AETHER_DIR, "module/allegro/src/transformations.c"),
    path.join(AETHER_DIR, "module/allegro/src/tri_soft.c"),
    path.join(AETHER_DIR, "module/allegro/src/utf8.c"),
    path.join(AETHER_DIR, "module/allegro/src/misc/aatree.c"),
    path.join(AETHER_DIR, "module/allegro/src/misc/bstrlib.c"),
    path.join(AETHER_DIR, "module/allegro/src/misc/list.c"),
    path.join(AETHER_DIR, "module/allegro/src/misc/vector.c"),
}

ALLEGRO_SRC_WIN_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/win/wclipboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/whapall.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/whapdrv.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/whaptic.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/whapxi.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wjoyall.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wjoydrv.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wjoydxnu.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/wjoyxi.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wkeyboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wmcursor.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wmouse.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wsystem.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wthread.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wtime.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wtouch_input.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wunicode.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wwindow.c"),
    path.join(AETHER_DIR, "module/allegro/src/win/wxthread.c"),
}

ALLEGRO_SRC_D3D_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_bmp.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_disp.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_display_formats.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_render_state.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_shader.cpp"),
    path.join(AETHER_DIR, "module/allegro/src/win/d3d_d3dx9.cpp"),
}

ALLEGRO_SRC_OPENGL_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/opengl/extensions.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_bitmap.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_display.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_draw.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_fbo.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_lock.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_lock_es.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_render_state.c"),
    path.join(AETHER_DIR, "module/allegro/src/opengl/ogl_shader.c"),
}

ALLEGRO_SRC_WGL_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/win/wgl_disp.c"),
}

ALLEGRO_SRC_UNIX_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/unix/udrvlist.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/ufdwatch.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/ugfxdrv.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/uhapdrv.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/ujoydrv.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/ukeybd.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/umouse.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/upath.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/utime.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/uxthread.c"),
}

ALLEGRO_SRC_X_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/x/xclipboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xcursor.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xdisplay.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xevents.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xfullscreen.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xglx_config.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xkeyboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xmousenu.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xrandr.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xsystem.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xtouch.c"),
    path.join(AETHER_DIR, "module/allegro/src/x/xwindow.c"),
    path.join(AETHER_DIR, "module/allegro/src/linux/lhaptic.c"),
    path.join(AETHER_DIR, "module/allegro/src/linux/ljoynu.c"),
}

ALLEGRO_SRC_MACOSX_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/macosx/hidjoy.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/hidjoy-10.4.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/hidman.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/keybd.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/qzmouse.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/system.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/osxclipboard.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/osxgl.m"),
    path.join(AETHER_DIR, "module/allegro/src/macosx/osx_app_delegate.m"),
    path.join(AETHER_DIR, "module/allegro/src/unix/utime.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/uxthread.c"),
}

ALLEGRO_SRC_IPHONE_FILES = {
    path.join(AETHER_DIR, "module/allegro/src/iphone/allegroAppDelegate.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/EAGLView.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/ViewController.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_clipboard.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_display.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_joystick.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_keyboard.c"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_main.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_mouse.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_path.m"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_system.c"),
    path.join(AETHER_DIR, "module/allegro/src/iphone/iphone_touch_input.m"),
    path.join(AETHER_DIR, "module/allegro/src/unix/utime.c"),
    path.join(AETHER_DIR, "module/allegro/src/unix/uxthread.c"),
}

ALLEGRO_SRC_ANDROID_FILES = {
 path.join(AETHER_DIR, "module/allegro/src/unix/ufdwatch.c"),
 path.join(AETHER_DIR, "module/allegro/src/unix/utime.c"),
 path.join(AETHER_DIR, "module/allegro/src/unix/uxthread.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_apk_file.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_clipboard.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_display.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_image.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_input_stream.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_joystick.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_keyboard.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_mouse.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_sensors.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_system.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_touch.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/jni_helpers.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/ljoynu.c"),
 path.join(AETHER_DIR, "module/allegro/src/android/android_apk_fs.c"),
}

ALLEGRO_SRC_RASPBERRYPI_FILES = {
 path.join(AETHER_DIR, "module/allegro/src/unix/utime.c"),
 path.join(AETHER_DIR, "module/allegro/src/unix/uxthread.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/lkeybdnu.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/lmseev.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/lmsedrv.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/lhaptic.c"),
 path.join(AETHER_DIR, "module/allegro/src/linux/ljoynu.c"),
 path.join(AETHER_DIR, "module/allegro/src/x/xevents.c"),
 path.join(AETHER_DIR, "module/allegro/src/x/xkeyboard.c"),
 path.join(AETHER_DIR, "module/allegro/src/x/xmousenu.c"),
 path.join(AETHER_DIR, "module/allegro/src/x/xwindow.c"),
 path.join(AETHER_DIR, "module/allegro/src/raspberrypi/pisystem.c"),
 path.join(AETHER_DIR, "module/allegro/src/raspberrypi/pidisplay.c"),
}

ALLEGRO_SRC_SDL_FILES = {
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_system.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_time.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_thread.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_display.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_keyboard.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_mouse.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_touch.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_joystick.c"),
 path.join(AETHER_DIR, "module/allegro/src/sdl/sdl_event_hack.c"),
}

ALLEGRO_INCLUDE_ALLEGRO_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro5.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/alcompat.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/altime.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/base.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/bitmap.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/bitmap_draw.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/bitmap_io.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/bitmap_lock.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/blender.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/clipboard.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/color.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/config.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/cpu.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/debug.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/display.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/drawing.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/error.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/events.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/file.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/fixed.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/fmaths.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/fshook.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/fullscreen_mode.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/haptic.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/joystick.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/keyboard.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/keycodes.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/memory.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/monitor.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/mouse.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/mouse_cursor.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/path.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/render_state.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/shader.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/system.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/threads.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/tls.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/touch_input.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/timer.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/transformations.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/utf8.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_direct3d.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_opengl.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_INLINE_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/inline/fmaths.inl"),
}

ALLEGRO_INCLUDE_ALLEGRO_INTERNAL_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/internal/alconfig.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_OPENGL_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/gl_ext.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_OPENGL_GLEXT_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/gl_ext_alias.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/gl_ext_defs.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/glx_ext_alias.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/glx_ext_defs.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/wgl_ext_alias.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/wgl_ext_defs.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/gl_ext_api.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/gl_ext_list.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/glx_ext_api.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/glx_ext_list.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/wgl_ext_api.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/opengl/GLext/wgl_ext_list.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_PLATFORM_FILES = {
    -- Only files which need to be installed.
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alandroid.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alandroidcfg.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/albcc32.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/aliphone.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/aliphonecfg.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/almngw32.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/almsvc.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alosx.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alosxcfg.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alraspberrypi.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alraspberrypicfg.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alucfg.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alunix.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alwatcom.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alwin.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/astdbool.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/astdint.h"),
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/allegro_sdl_config.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_WINDOWS_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_windows.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_MACOSX_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_osx.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_IPHONE_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_iphone.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_ANDROID_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_android.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_PLATFORM_FILES_GENERATED = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alplatf.h"),
}

ALLEGRO_INCLUDE_ALLEGRO_X_FILES = {
    path.join(AETHER_DIR, "module/allegro/include/allegro5/allegro_x.h"),
}

ALLEGRO_ADDON_AUDIO_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/acodec/acodec.c"),
    path.join(AETHER_DIR, "module/allegro/addons/acodec/wav.c"),
    path.join(AETHER_DIR, "module/allegro/addons/acodec/helper.c"),
    path.join(AETHER_DIR, "module/allegro/addons/acodec/voc.c"),

}

ALLEGRO_ADDON_FONT_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/font/font.c"),
    path.join(AETHER_DIR, "module/allegro/addons/font/fontbmp.c"),
    path.join(AETHER_DIR, "module/allegro/addons/font/stdfont.c"),
    path.join(AETHER_DIR, "module/allegro/addons/font/text.c"),
    path.join(AETHER_DIR, "module/allegro/addons/font/bmfont.c"),
    path.join(AETHER_DIR, "module/allegro/addons/font/xml.c"),
}

ALLEGRO_ADDON_FONT_INCLUDE = {
    path.join(AETHER_DIR, "module/allegro/addons/font"),
}

ALLEGRO_ADDON_TTF_INCLUDE = {
    path.join(AETHER_DIR, "module/allegro/addons/ttf"),
}

ALLEGRO_ADDON_IMAGE_INCLUDE = {
    path.join(AETHER_DIR, "module/allegro/addons/image"),
}

ALLEGRO_ADDON_IMAGE_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/image/bmp.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/iio.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/pcx.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/tga.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/dds.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/identify.c"),
    path.join(AETHER_DIR, "module/allegro/addons/image/png.c"),
}

ALLEGRO_ADDON_PRIMITIVE_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/primitives/high_primitives.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/line_soft.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/point_soft.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/polygon.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/polyline.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/prim_directx.cpp"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/prim_opengl.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/prim_soft.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/prim_util.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/primitives.c"),
    path.join(AETHER_DIR, "module/allegro/addons/primitives/triangulator.c"),
}

ALLEGRO_ADDON_PRIMITIVE_WINDOWS_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/primitives/directx_shaders.cpp"),
}

ALLEGRO_ADDON_TTF_FILES = {
    path.join(AETHER_DIR, "module/allegro/addons/ttf/ttf.c"),
}