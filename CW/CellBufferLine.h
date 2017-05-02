#include "MainHeader.h"
#include "ShaderDrawCell.h"

#pragma once
namespace Battleship
{
	class CellBufferLine
	{
		Shader::ShaderDrawCell *mShader;

		float mWidth;
		glm::vec4 mColor;
		void Init(void);
	public:
		CellBufferLine(Shader::ShaderDrawCell *mShader, float mWidth, glm::vec4 mColor);
		~CellBufferLine();

		void Draw(glm::vec2 mStart, glm::vec2 mEnd);
	};
}
