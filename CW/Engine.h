#include "GameClient.h"
#include "Timer.h"
#include "DrawPole.h"


#pragma once
namespace Battleship
{
	class Engine
	{
		HWND hwnd;
		bool ok;
		bool my_turn, tx;

		Shader::ShaderDrawCell *mShader;
		Timer::Timer *mTimer;
		Dimension *mDim;
		DrawPole *mDrawPole1, *mDrawPole2;
		GameClient *mClient;
		////////////////////////////////////////////////////////////
		void Tick(void);
		////////////////////////////////////////////////////////////
		void Init(void);
		void Pick2(int32_t x, int32_t y, bool full);
	public:
		Engine(HWND hwnd);
		~Engine();
		////////////////////////////////////////////////////////////
		void Pick(int32_t x, int32_t y);
		bool CloseGame(void);
		void Resize(uint32_t mX, uint32_t mY);
		void Draw(void);
		////////////////////////////////////////////////////////////
	};
}
