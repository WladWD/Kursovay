#include "DrawPole.h"


Battleship::DrawPole::DrawPole(Shader::ShaderDrawCell *mShader, const Dimension * mDim, glm::vec2 gMainPos, float mWidth, glm::vec4 mColor) : mDim(mDim)
{
	mTop = gMainPos * 2.0f - glm::vec2(1.0f, 1.0f);// mDim->GetPosByScale(gMainPos);// * 2.0f -  glm::vec2(1.0f, 1.0f);
	mStep = mDim->GetCellDimension();

	mDrawGrid = new CellBufferLine(mShader, mWidth, mColor);
}

Battleship::DrawPole::~DrawPole()
{
	delete mDrawGrid;
}

void Battleship::DrawPole::DrawGrid(void)
{
	for (register int32_t i = 0; i <= 10; ++i) 
	{
		mDrawGrid->Draw(mTop + glm::vec2(mStep.x * i, 0.0f), mTop + glm::vec2(mStep.x * i, -mStep.y * 10));
		mDrawGrid->Draw(mTop + glm::vec2(0.0f, -mStep.y * i), mTop + glm::vec2(mStep.x * 10, -mStep.y * i));
	}
}

void Battleship::DrawPole::DrawCell(void)
{
}
