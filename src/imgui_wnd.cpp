/**
  ******************************************************************************
  * @file           : imgui_wnd.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/8/22
  ******************************************************************************
  */



#include "imgui_wnd.h"

#include <iostream>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

ImGuiWindowImplGlfw::ImGuiWindowImplGlfw() {

}

ImGuiWindowImplGlfw::~ImGuiWindowImplGlfw() {

}
