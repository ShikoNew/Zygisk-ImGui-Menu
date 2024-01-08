#pragma once
#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H
using namespace ImGui;
bool tes1;
void DrawMenu()
{
    static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    {
        SetNextWindowSize(ImVec2(1270, 750), ImGuiCond_FirstUseEver);
        Begin(OBFUSCATE("B3ST SQU4D"));
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_FittingPolicyResizeDown;
        if (BeginTabBar("Menu", tab_bar_flags)) {
            if (BeginTabItem(OBFUSCATE("Main"))) {
                Checkbox(OBFUSCATE("Test"), &test);
                if (Button(OBFUSCATE(ICON_FA_EYE"Add Skins"))) {
                    // code for button action
                    tes1 = true;
                }
                EndTabItem();
            }
            EndTabBar();
        }
        Pointers();
        Hooks();
        Patches();
        End();
    }
}

void SetupImgui() {
    IMGUI_CHECKVERSION();
    CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(egl.width, egl.height);        
        ImGui_ImplOpenGL3_Init(OBFUSCATE("#version 300 es"));
        ImGui_ImplAndroid_Init(NULL);
       ImGui::StyleColorsClassic();
    io.ConfigWindowsMoveFromTitleBarOnly = true; 
        io.IniFilename = NULL;     
        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
        ImFontConfig icons_config;  
        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;

        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;
       
        io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 23.0f, &CustomFont);
        io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 25.0f, &icons_config, icons_ranges);
        
        ImFontConfig font_cfg;
        font_cfg.SizePixels = 19.0f;
        io.Fonts->AddFontDefault(&font_cfg);
		
        ImGui::GetStyle().ScaleAllSizes(3.0f);
}

EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (!setupimg)
    {
        SetupImgui();
        setupimg = true;
    }
    ImGuiIO &io = GetIO();
    ImGui_ImplOpenGL3_NewFrame();
    NewFrame();
    DrawMenu();
    EndFrame();
    Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return old_eglSwapBuffers(dpy, surface);
}

#endif
