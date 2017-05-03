#include "MainHeader.h"
#include "Timer.h"
#include "DrawPole.h"

#pragma once
namespace Battleship
{
	class Engine
	{
		bool my_turn;

		Shader::ShaderDrawCell *mShader;
		Timer::Timer *mTimer;
		Dimension *mDim;
		DrawPole *mDrawPole1, *mDrawPole2;
		////////////////////////////////////////////////////////////
		void Tick(void);
		////////////////////////////////////////////////////////////
		void Init(void);
		void Pick2(int32_t x, int32_t y, bool full);
	public:
		Engine();
		~Engine();
		////////////////////////////////////////////////////////////
		void Pick(int32_t x, int32_t y);
		bool CloseGame(void);
		void Resize(uint32_t mX, uint32_t mY);
		void Draw(void);
		////////////////////////////////////////////////////////////
	};
}
