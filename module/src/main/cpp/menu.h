//
// Created by lbert on 4/15/2023.
//

#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H

using namespace ImGui;
#include "Icon.h"
#include "Iconcpp.h"

void styl() {
	ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    style.Colors[ImGuiCol_WindowBg] = ImColor(0, 2, 13);
    style.Colors[ImGuiCol_TitleBg] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_Button] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(130, 0, 177);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(130, 0, 177);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(111, 123, 247);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(130,0,177);
    style.Colors[ImGuiCol_ResizeGripActive] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_ResizeGrip] = ImColor(13, 118, 220);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(114, 2, 149);
	style.Colors[ImGuiCol_CheckMark] = ImColor(114, 2, 149);
	style.Colors[ImGuiCol_SliderGrab] = ImColor(114, 2, 149);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(130,0,177);
	style.Colors[ImGuiCol_HeaderActive] = ImColor(130,0,177);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(114, 2, 149);
    style.Colors[ImGuiCol_Header] = ImColor(114, 2, 149);
	style.Colors[ImGuiCol_FrameBg] = ImColor(130,0,177);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(130,0,177);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(130,0,177);
	style.Colors[ImGuiCol_Button] = ImColor(130,0,177);
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(150,0,205);
	style.Colors[ImGuiCol_ButtonActive] = ImColor(150,0,205);
	style.Colors[ImGuiCol_ScrollbarBg] = ImColor(0, 2, 13);

	style.Colors[ImGuiCol_PopupBg] = ImColor(0, 2, 13);
	

    style.WindowTitleAlign = ImVec2(0.5, 0.5);
    style.FramePadding = ImVec2(10, 10);
    style.FrameRounding = 2.5;
    style.WindowRounding = 5.f;
    style.WindowBorderSize = 4.f;
    }


void DrawMenu()
{ styl();
 const ImVec2 window_size = ImVec2(900, 800);
    static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    {  
        Begin(OBFUSCATE("Test Nigga"));
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_FittingPolicyResizeDown;
        if (BeginTabBar("Menu", tab_bar_flags)) {
                
           
            if (BeginTabItem(OBFUSCATE("Player"))) {
		   // SliderFloat(OBFUSCATE("Speed"), &damageMultiplier, 0.1, 0.15);
                Checkbox(OBFUSCATE("anti close"), &bypass);
                Checkbox(OBFUSCATE("No kick"), &nokick);
                TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                SliderInt(OBFUSCATE("Speed"), &damageMultiplie, 1, 100, OBFUSCATE("%d"), 0); // min = 1, max = 100
                Checkbox(OBFUSCATE("God Mode"), &isGod);
                // here menu stuff, remove test btw
                // ImGui::Checkbox(OBFUSCATE("This is a checkbox"), &test);
                if (Button(OBFUSCATE("Add Currency"))) {
                    // code for button action
                    addCurrency = true;
                }
                TextUnformatted(OBFUSCATE("Adds 1000 gems"));
                if (Button(OBFUSCATE("Add Skins"))) {
                    // code for button action
                    addSkins = true;
                }
                Checkbox(OBFUSCATE("Everything unlocked"), &everythingUnlocked);
                Checkbox(OBFUSCATE("Free Items"), &freeItems);
                Checkbox(OBFUSCATE("Show Items"), &showAllItems);
                EndTabItem();
	    }
	
		//new


if (BeginTabItem(OBFUSCATE("Player"))) {
                TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                SliderInt(OBFUSCATE("Damage Multiplier"), &damageMultiplie, 1, 100, OBFUSCATE("%d"), 0); // min = 1, max = 100
                Checkbox(OBFUSCATE("God Mode"), &isGod);
                // here menu stuff, remove test btw
                // ImGui::Checkbox(OBFUSCATE("This is a checkbox"), &test);
               
                EndTabItem();
            }


		//new
            EndTabBar();
        }
        Patches();
        End();
    }
}

void SetupImgui() {
    IMGUI_CHECKVERSION();
    CreateContext();
    ImGuiIO &io = GetIO();
    io.DisplaySize = ImVec2((float) glWidth, (float) glHeight);
    ImGui_ImplOpenGL3_Init("#version 100");
    StyleColorsDark();
    GetStyle().ScaleAllSizes(7.0f);
    io.Fonts->AddFontFromMemoryTTF(Roboto_Regular, 30, 30.0f);
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

#endif //ZYGISK_MENU_TEMPLATE_MENU_H
