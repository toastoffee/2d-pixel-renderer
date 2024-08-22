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


#include "GLFW/glfw3.h"
#include "imgui.h"

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
