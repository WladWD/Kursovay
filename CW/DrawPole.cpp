#include "DrawPole.h"


Battleship::DrawPole::DrawPole(Shader::ShaderDrawCell *mShader, const Dimension * mDim, glm::vec2 gMainPos, float mWidth, glm::vec4 mColor, bool pole2) : mDim(mDim), my_turn(true)
{
	mTop = gMainPos * 2.0f - glm::vec2(1.0f, 1.0f);// mDim->GetPosByScale(gMainPos);// * 2.0f -  glm::vec2(1.0f, 1.0f);
	mStep = mDim->GetCellDimension();

	mDrawGrid = new CellBufferLine(mShader, mWidth, mColor);

	std::ifstream mf("resource\\ships.txt");
	for (register int i = 0; i < 10; ++i)
	{
		std::string mstrd;
		mf >> mstrd;
		for (register int j = 0; j < 10; ++j)
			mGridCell[j][i] = new CellDraw(mShader, mDrawGrid, mDim, !pole2 && (mstrd[j] != '*'), mTop + mStep * glm::vec2(j, -i));//(bool)((i*j) & 1)
	}

	mf.close();
}

Battleship::DrawPole::~DrawPole()
{
	delete mDrawGrid;
	for (register int i = 0; i < 10; ++i)
		for (register int j = 0; j < 10; ++j)
			delete mGridCell[i][j];
}

bool Battleship::DrawPole::ItsOver(void)
{
	bool ok = false;
	for (register int i = 0; i < 10; ++i)
		for (register int j = 0; j < 10; ++j)
			ok = ok  || (mGridCell[i][j]->GetState() && !mGridCell[i][j]->IsPicked());
	return !ok;
}

bool Battleship::DrawPole::Pick1(glm::vec2 mPos, int32_t &x, int32_t &y, bool &full, bool test)
{
	//if (!my_turn)
	//	return false;
	mPos = mPos * 2.0f - glm::vec2(1.0f, 1.0f);

	glm::vec2 mX = (mPos - mTop) / mStep;
	if (mX.x >= 0.0f && mX.x <= 10.0f &&
		mX.y <= 0.0f && mX.y >= -10.0f && mGridCell[static_cast<int32_t>(mX.x)][static_cast<int32_t>(-mX.y)]->GetStateUsed())
	{

		x = static_cast<int32_t>(mX.x);
		y = static_cast<int32_t>(-mX.y);
		full = mGridCell[x][y]->GetState();
		
		if (!test)
			mGridCell[x][y]->Pick();// static_cast<int32_t>(mX.x)][static_cast<int32_t>(-mX.y)

		return true;
	}
	return false;
}

void Battleship::DrawPole::Pick2(uint32_t i, uint32_t j, bool full)
{
	mGridCell[i][j]->Pick(full);
}

bool Battleship::DrawPole::Pick3(uint32_t i, uint32_t j)
{
	mGridCell[i][j]->Pick();
	return mGridCell[i][j]->GetState();
}

void Battleship::DrawPole::DrawGrid(void)
{
	for (register int32_t i = 0; i <= 10; ++i) 
	{
		mDrawGrid->Draw(mTop + glm::vec2(mStep.x * i, 0.0f), mTop + glm::vec2(mStep.x * i, -mStep.y * 10));
		mDrawGrid->Draw(mTop + glm::vec2(0.0f, -mStep.y * i), mTop + glm::vec2(mStep.x * 10, -mStep.y * i));
	}

}

void Battleship::DrawPole::DrawCell(float mDtMs, float mGtMs)
{
	for (register int i = 0; i < 10; ++i)
		for (register int j = 0; j < 10; ++j)
			mGridCell[i][j]->Draw(mDtMs, mGtMs);
}
