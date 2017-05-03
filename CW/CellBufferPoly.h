#include "MainHeader.h"
#include "ShaderDrawCell.h"

#pragma once
namespace Battleship
{
	class CellBufferPoly
	{
		glm::vec2 mvert[4] = {glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec2(0.0f, -1.0f), glm::vec2(1.0f, -1.0f) };
		Shader::ShaderDrawCell *mShader;

		glm::vec4 mColor;
		void Init(void);
	public:
		CellBufferPoly(Shader::ShaderDrawCell *mShader, glm::vec4 mColor);
		~CellBufferPoly();

		void Draw(glm::vec2 mPos, glm::vec2 mScale);
		void Draw(glm::vec2 mPos, glm::vec2 mScale, glm::vec4 mColor);
	};
}
