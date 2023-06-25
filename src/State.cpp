#include "State.hpp"

#include <array>
#include <gsl/span>

State* State::_state = nullptr;

State& State::Instance()
{
    if(_state == nullptr)
        _state = new State();
    return *_state;
}

Window& State::GetWindow()
{
    return _window;
}
World& State::GetWorld()
{
    return _world;
}
gfx::Shader& State::GetShader()
{
    return *_shaderHandle;
}
gfx::Atlas& State::GetAtlas()
{
    return _atlas;
}
bool State::IsWireframe()
{
    return _wireframe;
}

void State::SetWireframe(bool wireframe)
{
    _wireframe = wireframe;
}

void init()
{
}

void destroy()
{
}
void tick()
{
}

void update()
{
}

void render()
{
}

State::State() :
    _atlas{"res/images/blocks.png", glm::vec2(32, 32)}, _window{}, _world{}

{
    _window.Create(init, destroy, tick, update, render);
    using VA = gfx::VertexAttr;
    static constexpr std::array attributes = {
        VA{0, "position"}, VA{1, "uv"}, VA{2, "color"}};
    _shaderHandle =
        new gfx::Shader("res/shaders/basic.vs", "res/shaders/basic.fs", attributes);
}

void State::Start()
{
    _window.StartLoop();
}