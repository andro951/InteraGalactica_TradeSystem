#pragma once

#include <string>

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
void LogMessage(MessageID messageID);