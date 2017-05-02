#include "MainHeader.h"
#include <chrono>

#pragma once
namespace Timer
{
	class Timer
	{
		std::chrono::steady_clock::time_point mStart, mLast, mCur;
		std::chrono::steady_clock mClock;
	public:
		Timer(void);
		~Timer();

		void Tick(void);
		float GetDeltaTime(void);
		float GetFullTime(void);
	};
}

