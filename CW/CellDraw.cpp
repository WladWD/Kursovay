#include "CellDraw.h"

Battleship::CellDraw::CellDraw(Shader::ShaderDrawCell *mShader, CellBufferLine *mDrawLine, const Dimension *mDimC, bool full, glm::vec2 mTop) : mDrawLine(mDrawLine), used(true), 
full(full), mDimC(mDimC), mTop(mTop), pick(false)
{
	mDrawCell = new CellBufferPoly(mShader, glm::vec4(0.75f));
}

Battleship::CellDraw::~CellDraw()
{
	delete mDrawCell;
}

bool Battleship::CellDraw::IsPicked(void)
{
	return pick;
}

void Battleship::CellDraw::Pick(void)
{
	pick = true;
	used = false;//закрасить крестиком
}

void Battleship::CellDraw::Pick(bool full)
{
	pick = true;
	used = false;//закрасить крестиком
	this->full = full;
}

bool Battleship::CellDraw::GetStateUsed(void)
{
	return used;
}

bool Battleship::CellDraw::GetState(void)
{
	return full;
}

void Battleship::CellDraw::Draw(float dtMs, float gtMs)
{
	if(full)
		mDrawCell->Draw(mTop, mDimC->GetCellDimension());
	if (!used)
	{
		mDrawLine->Draw(mTop, mTop + mDimC->GetCellDimension() * glm::vec2(1.0f, -1.0f));
		mDrawLine->Draw(mTop + mDimC->GetCellDimension() * glm::vec2(1.0f, 0.0f), mTop + mDimC->GetCellDimension() * glm::vec2(0.0f, -1.0f));
	}
}
