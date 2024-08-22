#include "glad/glad.h"

#include "imgui.h"
#include "imgui_wnd.h"
#include "imgui_pixel_renderer.h"



int main() {
    ImGuiWindowImplGlfw renderWnd;

    renderWnd.Init();

    renderWnd.RenderLoop([](){
        ImGui::Begin("Test Wnd");

        ImGui::End();
    });

    renderWnd.Close();
}