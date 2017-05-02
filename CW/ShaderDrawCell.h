#include "ShaderBase.h"

#pragma once
namespace Shader
{
#define DPROGRAM_COUNT 1
	class ShaderDrawCell : public ShaderBase
	{
		////////////////////////////////////////////////////////////////////////////////////////////////
		GLint mWorld[DPROGRAM_COUNT];
		////////////////////////////////////////////////////////////////////////////////////////////////
		void InitVariable(GLuint program);
		////////////////////////////////////////////////////////////////////////////////////////////////
	public:
		ShaderDrawCell(Resource::ResourceBase *resourceLoad);
		~ShaderDrawCell();
		////////////////////////////////////////////////////////////////////////////////////////////////
		GLint GetProgram(void);
		////////////////////////////////////////////////////////////////////////////////////////////////
		void SetWorld(glm::mat4 mWorld);
		////////////////////////////////////////////////////////////////////////////////////////////////
	};
#undef DPROGRAM_COUNT
}
