/*
Author - Isaac Richards
Date - 29AUG23
Description - TradeSystem is a "static" class that manages all trading in the game.
*/
#pragma once

class TradeSystem {
private:
	TradeSystem();
	TradeSystem(const TradeSystem& other) = delete;
	TradeSystem& operator=(const TradeSystem& other) = delete;
	~TradeSystem();

public:
	static TradeSystem& Instance();

	void Save();
	void Load();

private:
	void SaveTrades();
	void LoadTrades();
};