#include "gfx/gfx.hpp"

#include "camera/OrthoCamera.hpp"
#include "camera/PerspectiveCamera.hpp"
#include "camera/types.hpp"

#include "gfx/Texture.hpp"
#include "gfx/gfx.hpp"

namespace gfx
{
    struct VertexAttr
    {
        GLuint index;
        const GLchar* name;
    };

    struct Shader
    {
    public:
        Shader(std::string vertexShaderPath, std::string fragmentShaderPath, gsl::span<const VertexAttr> attributes);
        Shader() = delete;
        ~Shader();

        void Bind();
        void Uniform(std::string name, glm::mat4 m);
        void Uniform(glm::mat4 view, glm::mat4 proj);
        void Uniform(std::string name, Texture texture, GLuint n);
        void Uniform(std::string name, float f);
        void Uniform(std::string name, glm::vec2 v);
        void Uniform(std::string name, glm::vec3 v);
        void Uniform(std::string name, glm::vec4 v);
        void Uniform(std::string name, int d);
        void Uniform(std::string name, unsigned int u);

    private:
        GLint Compile(std::string path, GLenum type);
        void LogAndFail(
            GLint handle,
            const char* adverb,
            const char* path,
            void (*getlog)(GLuint, GLsizei, GLsizei*, GLchar*),
            void (*getiv)(GLuint, GLenum, GLint*));

        GLint GetUniformLocation(std::string name);

        GLuint _handle;
        GLuint _vertexShaderHandle;
        GLuint _fragmentShaderHandle;
    };

}
