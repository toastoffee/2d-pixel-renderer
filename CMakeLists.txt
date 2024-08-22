cmake_minimum_required(VERSION 3.27)

# project name
project(2d_pixel_renderer)

set(CMAKE_CXX_STANDARD 11)

# include glad header files
include_directories(glad/include)

# 包含glfw头文件
include_directories(/opt/homebrew/Cellar/glfw/3.4/include)
# 链接glfw库
link_directories(/opt/homebrew/Cellar/glfw/3.4/lib)

include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src
                                    ${PROJECT_SOURCE_DIR}/third_party
                                    ${PROJECT_SOURCE_DIR}/third_party/imgui
                                    ${PROJECT_SOURCE_DIR}/third_party/stbi
)

add_executable(2d_pixel_renderer
                main.cpp

                glad/src/glad.c

                third_party/stbi/stb_image.cpp

                third_party/imgui/imgui.cpp
                third_party/imgui/imgui_draw.cpp
                third_party/imgui/imgui_tables.cpp
                third_party/imgui/imgui_widgets.cpp
                third_party/imgui/imgui_demo.cpp

                third_party/imgui/backends/imgui_impl_glfw.cpp
                third_party/imgui/backends/imgui_impl_opengl3.cpp

                src/imgui_wnd.cpp
                src/imgui_wnd.h
                src/imgui_pixel_renderer.cpp
                src/imgui_pixel_renderer.h
        src/file_helper.cpp
        src/file_helper.h
)

target_link_libraries(
        ${PROJECT_NAME}
        glfw
)