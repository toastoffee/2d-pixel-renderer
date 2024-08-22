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
    _wnd        = nullptr;
    _clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

ImGuiWindowImplGlfw::~ImGuiWindowImplGlfw() {
    Close();
}

bool ImGuiWindowImplGlfw::Init() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return false;

    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only

#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#endif

    _wnd = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (_wnd == nullptr)
        return false;
    glfwMakeContextCurrent(_wnd);
    glfwSwapInterval(1); // Enable vsync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))                   // GLAD加载系统相关的OpenGL函数指针地址
    {
        std::cout << "ERROR::GLAD::INITIALIZATION_FAILED" << std::endl;        // GLAD加载失败报错
    }

    // set up ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // setup imGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(_wnd, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(window, "#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void ImGuiWindowImplGlfw::Close() {
    if(!_wnd) {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(_wnd);
        _wnd = nullptr;

        glfwTerminate();
    }
}
