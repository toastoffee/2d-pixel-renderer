/**
  ******************************************************************************
  * @file           : imgui_wnd.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/8/22
  ******************************************************************************
  */



#ifndef INC_2D_PIXEL_RENDERER_IMGUI_WND_H
#define INC_2D_PIXEL_RENDERER_IMGUI_WND_H

#include "glad/glad.h"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "GLFW/glfw3.h"

class ImGuiWindowImplGlfw {
private:
    GLFWwindow *_wnd;
    ImVec4 _clearColor;

public:
    ImGuiWindowImplGlfw();
    ~ImGuiWindowImplGlfw();

    bool Init();
    void Close();
    void RenderLoop(void (*renderFunc)());

};


#endif //INC_2D_PIXEL_RENDERER_IMGUI_WND_H
