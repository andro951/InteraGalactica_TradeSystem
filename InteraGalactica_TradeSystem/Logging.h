/*
Author - Isaac Richards
Date - 29AUG23
Description - Logging.h contains functions for logging messages to the console.
*/
#pragma once

#include <string>

/// <summary>
/// Used with the messages map in Logging.cpp to print messages to the console.
/// </summary>
enum class MessageID {
	GameStart,
	GameSetup,
	GameSetupComplete,
	GameLoad,
	GameLoadComplete,
	GameSave,
	GameSaveComplete,
	GameRun,
	GameStop,
	GameCleanup,
	GameCleanupComplete,
};

/// <summary>
/// True if using an IDE debugger to run the program.
/// Used to determine if the program should print troubleshooting logs to the console.
/// </summary>
extern bool DebuggerIsAttatched;

/// <summary>
/// Check this prior to logging trade offer messages to the console.
/// </summary>
bool LogTradeOffers();

/// <summary>
/// Check this prior to logging game messages to the console.
/// </summary>
bool LogGameMessages();

/// <summary>
/// Prints the string to the console by reference.
/// </summary>
void Log(const std::string& s, bool newLine = true);

/// <summary>
/// Prints the string literal to the console using Log().
/// </summary>
void LogString(const std::string s, bool newLine = true);

/// <summary>
/// Logs the message associated with messageID.
/// </summary>
void LogMessage(MessageID messageID, bool newLine = true);