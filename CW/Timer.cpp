#include "Timer.h"


Timer::Timer::Timer(void)
{
	mStart = mLast = mCur = std::chrono::steady_clock::now();
}

Timer::Timer::~Timer()
{
}

void Timer::Timer::Tick(void)
{
	mLast = mCur;
	mCur = std::chrono::steady_clock::now();
}

float Timer::Timer::GetDeltaTime(void)
{
	return std::chrono::duration_cast<std::chrono::microseconds>(mCur - mLast).count() * (1 / 1000.0f);
}

float Timer::Timer::GetFullTime(void)
{
	return std::chrono::duration_cast<std::chrono::microseconds>(mCur - mStart).count() * (1 / 1000.0f);
}
