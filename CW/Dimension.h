#include "MainHeader.h"
#include "CellBufferLine.h"

#pragma once
namespace Battleship
{
	class Dimension
	{
		//float mDimX, mDimY;
		//float mSizeX, mSizeY;
		//uint32_t mc_X, mc_Y;
		float mDimX, mDimY;
	public:
		Dimension(float mDimX, float mDimY);
		~Dimension();

		//glm::vec2 GetPosByScale(glm::vec2 mV) const ;
		glm::vec2 GetCellDimension(void) const;
	};
}

