/*
Author - Isaac Richards
Date - 29AUG23
Description - TimeSystem tracks the game time and provides a place to store time related constants.
    The game time is based on real time, but is rounded to minutes and stored as an integer.  The game is meant to be a real time multi-player game.
*/
#include "TimeSystem.h"
#include <chrono>

int TimeSystem::now;

void TimeSystem::Setup() {
    UpdateTime();
}

void TimeSystem::UpdateTime() {
    now = Now();
}

int TimeSystem::GetNow() {
    return now;
}

int TimeSystem::Now() {
    std::chrono::system_clock::time_point nowTimePoint = std::chrono::system_clock::now();
    std::chrono::minutes minutesSinceEpoch = std::chrono::duration_cast<std::chrono::minutes>(nowTimePoint.time_since_epoch());
    int nowInMinutes = static_cast<int>(minutesSinceEpoch.count());

    return nowInMinutes;
}