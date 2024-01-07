//
// Created by lbert on 4/15/2023.
//

#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H

using namespace ImGui;
#include "Icon.h"
#include "Iconcpp.h"
static int page = 1;
bool svaston;
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


void DrawMenu(){
	
  

	ImGui::Begin("Bonikken Cheats | 0.23.1 f1 APK", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

    const auto& CurrentWindowPosi = ImGui::GetWindowPos();
        // Early out if the window is collapsed, as an optimization.
        

    // Menu Bar
	
	ImGui::Spacing();
    
    
        if (ImGui::Button(ICON_FA_USER" Visuals",ImVec2(190,50)))
        {
            page = 1;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_CODE" Skins",ImVec2(190,50)))
        {
            page = 2;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_EYE" Legit",ImVec2(190,50)))
        {
            page = 3;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_CIRCLE_NOTCH" Configs",ImVec2(190,50)))
        {
            page = 4;
        }
        
		ImGui::Spacing();
    


    if (page == 1) {
page = 1;
        
        
		
    } else if (page == 2) {
page = 2;
    
	
    } else if (page == 3) {
       page = 3; 
	   } else if (page == 4) {
		page = 4;
    if (ImGui::CollapsingHeader("Configs")) {
	
		}
		if (ImGui::CollapsingHeader("Menu Settings")) {
		 //ImGui::Checkbox(OBFUSCATE("watermark"), &watermark);
	    
        
		ImGui::Checkbox(OBFUSCATE("custom crosshair"), &svaston);
		  }
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
