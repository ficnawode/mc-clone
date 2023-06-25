set(NAME gfx)

add_library(${NAME} STATIC)

target_link_libraries(${NAME} 
PUBLIC
    Microsoft.GSL::GSL
    GLEW 
    OpenGL
    glm
    glfw
    stb
    camera
)

target_include_directories(${NAME}
PUBLIC
    include/
)

target_sources(${NAME}
PRIVATE
    include/gfx/gfx.hpp
    include/gfx/Shader.hpp
    include/gfx/Texture.hpp
    include/gfx/RGBAImage.hpp
    include/gfx/Atlas.hpp
    include/gfx/Vao.hpp
    include/gfx/Vbo.hpp
    include/gfx/controls.hpp
    include/gfx/AABB.hpp

    src/gfx.cpp
    src/Texture.cpp
    src/RGBAImage.cpp
    src/Atlas.cpp
    src/Vao.cpp
    src/Vbo.cpp
    src/controls.cpp
    src/Shader.cpp

)