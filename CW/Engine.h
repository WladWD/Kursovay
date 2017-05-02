#include "MainHeader.h"
#include "Timer.h"
#include "DrawPole.h"

#pragma once
namespace Battleship
{
	class Engine
	{
		Shader::ShaderDrawCell *mShader;
		Timer::Timer *mTimer;
		Dimension *mDim;
		DrawPole *mDrawPole1, *mDrawPole2;
		////////////////////////////////////////////////////////////
		void Tick(void);
		////////////////////////////////////////////////////////////
		void Init(void);
	public:
		Engine();
		~Engine();
		////////////////////////////////////////////////////////////
		bool CloseGame(void);
		void Resize(uint32_t mX, uint32_t mY);
		void Draw(void);
		////////////////////////////////////////////////////////////
	};
}
