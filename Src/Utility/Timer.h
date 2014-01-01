//=======================================================================================================================|
// Created 2013.12.21 by Daniel L. Watkins
//
// Copyright (C) 2013-2014 Daniel L. Watkins
// This file is licensed under the MIT License.
//=======================================================================================================================|

#ifndef _glz_TIMER_H
#define _glz_TIMER_H

#include "../Main.h"

namespace glz
{
	/**
	 * Represents a high-precision timer.
	 */
	class Timer
	{
	private:
		Int64 mCurrentTime, mLastTime, mLastTimeInTimeElapsed;
		Int64 mNextTime, mStartTime, mFrameTime, mPerfCountFrequency;
		Double mTimeElapsed, mLastTimeElapsed;
		Double mTimeScale;
		Double mNormalFPS, mSlowFPS;
		Bool mStarted, mSmoothUpdates;


	public:
		Timer();
		Timer(Double fps);

		void start();
		Bool readyForNextFrame();
		
		Double getTimeElapsed();
		Double getCurrentTime();
		Bool getStarted() { return mStarted; }
		void setSmoothUpdates(Bool smoothUpdates) { mSmoothUpdates = smoothUpdates; }
	};
};


#endif

