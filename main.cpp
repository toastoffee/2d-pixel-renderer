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

    // fake out output(2*2)
    char* fakeData;
    int width = 100, height = 100;
    fakeData = (char *)malloc(width * height * 4);

    for (int i = 0; i < width * height; ++i) {
        if(i % 17 == 0) {
            fakeData[i * 4 + 0] = (char)255;
            fakeData[i * 4 + 1] = (char)0;
            fakeData[i * 4 + 2] = (char)255;
            fakeData[i * 4 + 3] = (char)255;
        } else {
            fakeData[i * 4 + 0] = (char)0;
            fakeData[i * 4 + 1] = (char)0;
            fakeData[i * 4 + 2] = (char)0;
            fakeData[i * 4 + 3] = (char)255;
        }
    }

    ImGuiPixelRenderer pixelRenderer;
//    pixelRenderer.GeneTex((const unsigned char*)data, 128, 192, ColorMode::RGBA);
    pixelRenderer.GeneTex((const unsigned char*)fakeData, width, height, ColorMode::RGBA);
//    pixelRenderer.GeneTex("/Users/toastoffee/Documents/CLionProjects/2d-pixel-renderer/images/mario_doc.ppm");


//    renderWnd.RenderLoop([&pixelRenderer]() {
//        ImGui::Begin("pixel renderer");
//
//        pixelRenderer.Render();
//
//        ImGui::End();
//    });

    while(!renderWnd.IsWndShouldClose()) {
        renderWnd.BeginLoop();
        pixelRenderer.Render();
        renderWnd.EndLoop();
    }

    renderWnd.Close();
}