#include "Dimension.h"
#include "CellBufferLine.h"

#pragma once
namespace Battleship
{
	class DrawPole
	{
		CellBufferLine *mDrawGrid;
		//bool norm[10][10];
		glm::vec2 mTop, mStep;

		const Dimension *mDim;
	public:
		DrawPole(Shader::ShaderDrawCell *mShader, const Dimension *mDim, glm::vec2 gMainPos, float mWidth, glm::vec4 mColor);
		~DrawPole();

		void DrawGrid(void);
		void DrawCell(void);
	};
}

