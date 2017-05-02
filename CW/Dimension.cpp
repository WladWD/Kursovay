#include "Dimension.h"


Battleship::Dimension::Dimension(float mDimX, float mDimY) : mDimX(mDimX), mDimY(mDimY)//mc_X(mX), mc_Y(mY)
{
	//float mViewport[4];
	//glGetFloatv(GL_VIEWPORT, mViewport);

	//mSizeX = mViewport[2];
	//mSizeY = mViewport[3];

	//mDimX = mViewport[2] / mX;
	//mDimY = mViewport[3] / mY;
}

Battleship::Dimension::~Dimension()
{
}

//glm::vec2 Battleship::Dimension::GetPosByScale(glm::vec2 mV) const
//{
//	return (mV / mDim) * 2.0f + glm::vec2(-1.0f, -1.0f);//((mV.x * mc_X) * mDimX) / mSizeX, ((mV.y * mc_Y) * mDimY) / mSizeY);
//}

glm::vec2 Battleship::Dimension::GetCellDimension(void) const
{
	return glm::vec2(mDimX, mDimY); //mDimX / mSizeX, mDimY / mSizeY);
}
