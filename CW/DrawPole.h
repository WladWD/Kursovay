#include "Dimension.h"
#include "CellBufferLine.h"
#include "CellDraw.h"
#include <string>

#pragma once
namespace Battleship
{
	class DrawPole
	{
		CellBufferLine *mDrawGrid;
		//bool norm[10][10];
		CellDraw *mGridCell[10][10];
		glm::vec2 mTop, mStep;
		bool my_turn;

		const Dimension *mDim;
	public:
		DrawPole(Shader::ShaderDrawCell *mShader, const Dimension *mDim, glm::vec2 gMainPos, float mWidth, glm::vec4 mColor, bool pole2 = false);
		~DrawPole();

		bool ItsOver(void);
		bool Pick1(glm::vec2 mPos, int32_t &x, int32_t &y, bool &full, bool test = false);
		void Pick2(uint32_t i, uint32_t j, bool full);
		bool Pick3(uint32_t i, uint32_t j);
		void DrawGrid(void);
		void DrawCell(float mDtMs, float mGtMs);
	};
}

