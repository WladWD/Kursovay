#include "MainHeader.h"

#pragma once
namespace Battleship
{
	class CellDraw
	{
		bool full;
		glm::vec2 mTop, mDim;
	public:
		CellDraw(bool used);
		~CellDraw();

		void Pick(void);
		bool GetState(void);
		void Draw(float dtMs, float gtMs);
	};
}

