#ifndef ZYGISK_MENU_TEMPLATE_MENU_H
#define ZYGISK_MENU_TEMPLATE_MENU_H
using namespace ImGui;

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
                EndTabItem();
            }
             if (BeginTabItem(OBFUSCATE("Player"))) {
///


Checkbox(OBFUSCATE("anti close"), &bypass);
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


///end
                EndTabItem();
            }
            
if (BeginTabItem(OBFUSCATE("Player2"))) {
	SliderFloat(OBFUSCATE("Jump Higher"), &jumpfloat, 0, 0.05f);
                TextUnformatted(OBFUSCATE("Damage Multiplier:")); // just plain text

                //SliderInt(OBFUSCATE("Damage Multiplier"), &damageMultiplie, 1, 100, OBFUSCATE("%d"), 0); // min = 1, max = 100
             //   Checkbox(OBFUSCATE("God Mode"), &isGod);
                // here menu stuff, remove test btw
                // ImGui::Checkbox(OBFUSCATE("This is a checkbox"), &test);
               
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
