#include "MainHeader.h"
#include "CellBufferPoly.h"
#include "CellBufferLine.h"
#include "Dimension.h"

#pragma once
namespace Battleship
{
	class CellDraw
	{
		CellBufferPoly *mDrawCell;
		CellBufferLine *mDrawLine;
		const Dimension *mDimC;

		bool full, used;
		glm::vec2 mTop;
	public:
		CellDraw(Shader::ShaderDrawCell *mShader, CellBufferLine *mDrawLine, const Dimension *mDim, bool full, glm::vec2 mTop);
		~CellDraw();

		void Pick(void);
		void Pick(bool full);
		bool GetState(void);
		void Draw(float dtMs, float gtMs);
	};
}

