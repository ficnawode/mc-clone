#pragma once

#include "Window.hpp"
#include "World.hpp"
#include "gfx/Atlas.hpp"
#include "gfx/Shader.hpp"

#include "gfx/gfx.hpp"

// Global state class
class State
{
public:
    static State& Instance();
    void Start();

    Window& GetWindow();
    World& GetWorld();
    gfx::Shader& GetShader();
    gfx::Atlas& GetAtlas();
    bool IsWireframe();

    void SetWireframe(bool wireframe);

private:
    State();
    State(State& other) = delete;
    void operator=(const State&) = delete;

    Window _window;
    World _world;
    gfx::Atlas _atlas;
    gfx::Shader* _shaderHandle = nullptr;

    bool _wireframe;

    static State* _state;
};
