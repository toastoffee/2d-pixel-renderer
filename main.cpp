#include "glad/glad.h"

#include "imgui.h"
#include "imgui_wnd.h"
#include "imgui_pixel_renderer.h"
#include "file_helper.h"


int main() {
    ImGuiWindowImplGlfw renderWnd;

    renderWnd.Init();

    void *data = nullptr;
    LoadFile("/Users/toastoffee/Documents/CLionProjects/2d-pixel-renderer/images/mario_doc.bin", data);

    ImGuiPixelRenderer pixelRenderer;
    pixelRenderer.GeneTex((const unsigned char*)data, 128, 192, ColorMode::RGBA);
//    pixelRenderer.GeneTex("/Users/toastoffee/Documents/CLionProjects/2d-pixel-renderer/images/mario_doc.ppm");


    renderWnd.RenderLoop([&pixelRenderer]() {
        ImGui::Begin("pixel renderer");

        pixelRenderer.Render();

        ImGui::End();
    });

    renderWnd.Close();
}