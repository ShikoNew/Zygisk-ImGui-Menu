//
// Created by lbert on 4/15/2023.
//
#pragma once
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


void DrawMenu(){ styl();
	
  

	const ImVec2 window_size = ImVec2(900, 800);
    const char* window_title = "Nazi - Menu [x64_x32]";
	
//wtff
	
	///wtff
		
    const char* name = "Shiden x Nigga";
    const char* version = "v1.0";
    
    // Begin the main menu window
   ImGui::SetNextWindowSize(window_size);
   if (ImGui::Begin(window_title, nullptr))

	
    ImGui::SetNextWindowSize(window_size);
    if (ImGui::Begin(window_title, nullptr)) 
		    {
        ImGui::TextColored(ImVec4(1, 1, 1, 1), "Creator : %s",name);
        ImGui::TextColored(ImVec4(1, 1, 1, 1), "Version : %s",version);
        ImGui::Text("FPS : %.3f ms (%.1f)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    
		
        
        
        ImVec2 cursor_pos = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddLine(cursor_pos,
        ImVec2(cursor_pos.x + ImGui::GetContentRegionAvail().x, cursor_pos.y),
        ImGui::GetColorU32(ImGuiCol_Text));
        
        // Early out if the window is collapsed, as an optimization.
        

    // Menu Bar
	
	ImGui::Spacing();
    
    
        if (ImGui::Button(ICON_FA_USER" Visuals",ImVec2(50,100)))
        {
            page = 1;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_CODE" Skins",ImVec2(50,100)))
        {
            page = 2;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_EYE" Legit",ImVec2(50,100)))
        {
            page = 3;
        }
		ImGui::SameLine();
        if (ImGui::Button(ICON_FA_CIRCLE_NOTCH" Configs",ImVec2(50,100)))
        {
            page = 4;
        }
        
		ImGui::Spacing();
    


    if (page == 1) {
page = 1;
        
        	    SliderFloat(OBFUSCATE("Speed"), &speedplayer, 0.1, 0.5);
                Checkbox(OBFUSCATE("anti close"), &bypass);
                Checkbox(OBFUSCATE("No kick"), &nokick);
                TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                //SliderInt(OBFUSCATE("Damage Multiplier"), &damageMultiplier, 1, 100, OBFUSCATE("%d"), 0); // min = 1, max = 100
                Checkbox(OBFUSCATE("God Mode"), &isGodMode);
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
		
    } else if (page == 2) {
page = 2;
    
	TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                SliderInt(OBFUSCATE("Damage Multiplier"), &damageM, 1, 100, OBFUSCATE("%d"), 0); // min = 1, max = 100
                Checkbox(OBFUSCATE("God Mode"), &isGod);
                // here menu stuff, remove test btw
                // ImGui::Checkbox(OBFUSCATE("This is a checkbox"), &test);
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
	    Patches();
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
