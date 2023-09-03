/*
Author - Isaac Richards
Date - 29AUG23
Description - TimeSystem tracks the game time and provides a place to store time related constants.
	The game time is based on real time, but is rounded to minutes and stored as an integer.  The game is meant to be a real time multi-player game.
*/
#pragma once

class TimeSystem {
public:
	static const int TICKS_PER_SECOND = 60;
	static const int SECONDS_PER_MINUTE = 60;
	static const int MINUTES_PER_HOUR = 60;
	static const int HOURS_PER_DAY = 24;
	static const int DAYS_PER_WEEK = 7;
	static const int DAYS_PER_YEAR = 365;
	static const int MINUTES_PER_DAY = MINUTES_PER_HOUR * HOURS_PER_DAY;
	static const int MINUTES_PER_WEEK = MINUTES_PER_DAY * DAYS_PER_WEEK;
	static const int MINUTES_PER_YEAR = MINUTES_PER_DAY * DAYS_PER_YEAR;

	/// <summary>
	/// Performs setup for the TimeSystem such as setting the initial time.
	/// </summary>
	static void Setup();

	/// <summary>
	/// Calls Now() and stores the result in now to update the game time.  Meant to be called ever game tick.
	/// </summary>
	static void UpdateTime();
	static int GetNow();

private:
	static int now;

	/// <returns>The current time rounded to minutes and converted to an int.</returns>
	static int Now();
};