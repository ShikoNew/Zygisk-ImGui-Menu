#pragma once
#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H
using namespace ImGui;
#define ICON_FA_USER "\xef\x80\x87"
bool svaston;
static int page = 1;
void DrawMenu()
{
    

	const ImVec2 window_size = ImVec2(1000, 900);
    const char* window_title = "Nazi - Menu [x64_x32]";
	
//wtff
	
	///wtff
		
    const char* name = "Nazi Menu";
    const char* version = "v1.0";
    
    // Begin the main menu window
   ImGui::SetNextWindowSize(window_size);
   if (ImGui::Begin(window_title, nullptr))

	
    ImGui::SetNextWindowSize(window_size);
    if (ImGui::Begin(window_title, nullptr)) 
		    {
        ImGui::TextColored(ImVec4(1, 1, 1, 1), "Menu : %s",name);
        ImGui::TextColored(ImVec4(1, 1, 1, 1), "Version : %s",version);
        Text("Made by NiggerDestroyer")
    
		
        
        
        ImVec2 cursor_pos = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddLine(cursor_pos,
        ImVec2(cursor_pos.x + ImGui::GetContentRegionAvail().x, cursor_pos.y),
        ImGui::GetColorU32(ImGuiCol_Text));
        ImGui::Spacing();
    }
    
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
        if(ImGui::CollapsingHeader("Player"))
			{Checkbox(OBFUSCATE("anti close"), &bypass);
                Checkbox(OBFUSCATE("No kick"), &nokick);
                TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                SliderInt(OBFUSCATE("Speed"), &damageMultiplie, 1, 1000, OBFUSCATE("%d"), 0); // min = 1, max = 100
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
}
        if(ImGui::CollapsingHeader("View"))
			{}
		
    } else if (page == 2) {
page = 2;
    if(ImGui::CollapsingHeader("Speed"))
	
    {Checkbox(OBFUSCATE("God Mode"), &godmode);} // min = 1, max = 100}
	if(ImGui::CollapsingHeader("Sandbox"))
			{}
    } else if (page == 3) {
       page = 3; 
	   if(ImGui::CollapsingHeader("menu size"))
			{}
			if(ImGui::CollapsingHeader("random"))
			{}
	   } else if (page == 4) {
		page = 4;
    if (ImGui::CollapsingHeader("Configs")) {
	
		}
		if (ImGui::CollapsingHeader("Menu Settings")) {
		 //ImGui::Checkbox(OBFUSCATE("watermark"), &watermark);
	    
        
		ImGui::Checkbox(OBFUSCATE("custom crosshair"), &test);
		  }
    }
        Pointers();
        Hooks();
        Patches();
        End();
    
}

void SetupImgui() {
    IMGUI_CHECKVERSION();
    CreateContext();
    ImGuiIO &io = GetIO();
    io.DisplaySize = ImVec2((float) glWidth, (float) glHeight);
    ImGui_ImplOpenGL3_Init("#version 100");
    StyleColorsClassic();
    GetStyle().ScaleAllSizes(4.0f);
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

#endif
