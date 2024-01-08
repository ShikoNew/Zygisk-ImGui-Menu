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
        // Setup Dear ImGui context
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    io.DisplaySize = ImVec2((float)glWidth, (float)glHeight);

    // Setup Dear ImGui style
    // Setup Platform/Renderer backends
    ImGui_ImplOpenGL3_Init("#version 100");
        ImFontConfig font_cfg2;
        font_cfg2.SizePixels = 30.f; 
        font_cfg2.GlyphRanges = io.Fonts->GetGlyphRangesCyrillic();
        io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 30.f,&font_cfg2);
        ImFontConfig font_cfg;
        font_cfg.MergeMode = true;
        static const ImWchar icon_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0x0};
        io.Fonts->AddFontFromMemoryCompressedBase85TTF(FontAwesome6_compressed_data_base85, 33.0f, &font_cfg, icon_ranges);
        SetBlackGoldTheme();
        
        //        io.SetBlackGoldTheme->AddFontFromMemoryCompressedBase85TTF(FontAwesome6_compressed_data_base85, 30.f, &font_cfg, icon_ranges);
           /*/ImFontConfig font_cfg4;
        font_cfg4.SizePixels = 36;
        font_cfg4.GlyphRanges = io.Fonts->GetGlyphRangesCyrillic();
        Func = io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 3/6,&font_cfg4);/*/
        
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
