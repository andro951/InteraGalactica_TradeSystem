/*
Author - Isaac Richards
Date - 29AUG23
Description - Logging.h contains functions for logging messages to the console.
*/
#include "Logging.h"
#include <iostream>
#include <map>
#include <Windows.h>

std::map<MessageID, std::string> messages = {
	{ MessageID::GameStart, "Starting the game." },
	{ MessageID::GameSetup, "Starting game setup." },
	{ MessageID::GameSetupComplete, "Completed game setup." },
	{ MessageID::GameLoad, "Starting game loading." },
	{ MessageID::GameLoadComplete, "Completed game loading." },
	{ MessageID::GameSave, "Starting game saving." },
	{ MessageID::GameSaveComplete, "Completed game saving." },
	{ MessageID::GameRun, "The game is now running." },
	{ MessageID::GameStop, "Stopping the game." },
	{ MessageID::GameCleanup, "Cleaning up from the game." },
	{ MessageID::GameCleanupComplete, "Completed cleanup of the game." },
	//{ MessageID::, "" },
};

bool DebuggerIsAttatched = IsDebuggerPresent() != 0;

//Bools manually set by the programmer to enable/disable logging troubleshooting messages.
bool logTradeOffers = true;
bool logGameMessages = true;

bool LogTradeOffers() {
	return DebuggerIsAttatched && logTradeOffers;
}

bool LogGameMessages() {
	return DebuggerIsAttatched && logGameMessages;
}

void Log(const std::string& s, bool newLine) {
	std::cout << s;
	if (newLine)
		std::cout << std::endl;
}

void LogString(const std::string s, bool newLine) {
	Log(s, newLine);
}

void LogMessage(MessageID messageID, bool newLine) {
	if (!LogGameMessages())
		return;

	Log(messages[messageID], newLine);
}