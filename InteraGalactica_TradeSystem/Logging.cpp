#include "Logging.h"
#include <iostream>
#include <map>

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

void Log(const std::string& s, bool newLine = true) {
	std::cout << s;
	if (newLine)
		std::cout << std::endl;
}

void LogString(const std::string s, bool newLine = true) {
	Log(s, newLine);
}

void LogMessage(MessageID messageID) {
	Log(messages[messageID]);
}