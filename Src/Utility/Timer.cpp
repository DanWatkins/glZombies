//=======================================================================================================================|
// Created 2013.12.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#include "Timer.h"

namespace glz
{
	Timer::Timer(): mNormalFPS(0.0),
                  mSlowFPS(1.0),
                  mTimeElapsed(0.0),
                  mFrameTime(0),
                  mLastTime(0),
                  mLastTimeInTimeElapsed(0),
                  mPerfCountFrequency(0),
                  mStarted(false),
                  mStartTime(0),
                  mLastTimeElapsed(0.0),
                  mSmoothUpdates(false)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*) &mPerfCountFrequency);
		mTimeScale = 1.0/mPerfCountFrequency;
	}


	Timer::Timer(Double fps): mNormalFPS(fps),
                  mSlowFPS(1.0),
                  mTimeElapsed(0.0),
                  mFrameTime(0),
                  mLastTime(0),
                  mLastTimeInTimeElapsed(0),
                  mPerfCountFrequency(0),
                  mStarted(false),
                  mStartTime(0),
                  mLastTimeElapsed(0.0),
                  mSmoothUpdates(false)
	{
		QueryPerformanceFrequency( (LARGE_INTEGER*) &mPerfCountFrequency);
		mTimeScale = 1.0/mPerfCountFrequency;

		mFrameTime = (LONGLONG)(mPerfCountFrequency / mNormalFPS);
	}


	void Timer::start()
	{
		mStarted = true;
		mTimeElapsed = 0.0;

		QueryPerformanceCounter((LARGE_INTEGER*) &mLastTime);

		mStartTime = mLastTimeInTimeElapsed = mLastTime;
		mNextTime = mLastTime + mFrameTime;
	}


	Bool Timer::readyForNextFrame()
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);

		if (mCurrentTime > mNextTime)
		{
			mTimeElapsed = (mCurrentTime-mLastTime) * mTimeScale;
			mLastTime = mCurrentTime;
			mNextTime = mCurrentTime + mFrameTime;

			return true;
		}

		return false;
	}
		

	Double Timer::getTimeElapsed()
	{
		mLastTimeElapsed = mTimeElapsed;
		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);

		mTimeElapsed = (mCurrentTime-mLastTimeInTimeElapsed)*mTimeScale;
		mLastTimeInTimeElapsed = mCurrentTime;

		const Double smoothness = 5.0;

		if (mSmoothUpdates)
		{
			if (mTimeElapsed < (mLastTimeElapsed*smoothness))
				return mTimeElapsed;

			return 0.0;
		}

		return mTimeElapsed;
	}


	Double Timer::getCurrentTime()
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);
		return (mCurrentTime-mStartTime) * mTimeScale;
	}
};