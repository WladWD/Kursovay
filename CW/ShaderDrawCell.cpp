#include "ShaderDrawCell.h"


Shader::ShaderDrawCell::ShaderDrawCell(Resource::ResourceBase *resourceLoad) : ShaderBase(1)
{
	const uint32_t shader_count = 2;
	GLuint compile_shader[shader_count];

	const char *sShaders[shader_count] =
	{
		"resource\\shader\\cell\\vert.glsl",
		"resource\\shader\\cell\\frag.glsl"
	};

	GLenum sTypes[shader_count] =
	{
		GL_VERTEX_SHADER,
		GL_FRAGMENT_SHADER
	};

	if (!BuildShader(resourceLoad, sShaders, sTypes, shader_count, compile_shader))
		throw std::runtime_error("Shader is not COMPILE !!!");;


	if (!LinkProgram(compile_shader[0], compile_shader[1], 0))
		throw std::runtime_error("Program is NOT LINKED !!!");

	for (register uint32_t i = 0; i < shader_count; i++) glDeleteShader(compile_shader[i]);

	MInitShaderVariable();

	program_mid = -1;
}

Shader::ShaderDrawCell::~ShaderDrawCell() { }

void Shader::ShaderDrawCell::InitVariable(GLuint program)
{
	correct_programm

	glBindAttribLocation(programs[program], 0, "gWorldPos");
	glBindAttribLocation(programs[program], 1, "glWorldColor");

	mWorld[program] = glGetUniformLocation(programs[program], to_shader_name(mWorld));
}

GLint Shader::ShaderDrawCell::GetProgram(void)
{
	program_mid = 0;
	return programs[0];
}

void Shader::ShaderDrawCell::SetWorld(glm::mat4 mWorld)
{
	glUniformMatrix4fv(this->mWorld[program_mid], 1, GL_FALSE, glm::value_ptr(mWorld));
}
