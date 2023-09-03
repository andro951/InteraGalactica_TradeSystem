/*
Author - Isaac Richards
Date - 29AUG23
Description - TradeSystem is a "static" class that manages all trading in the game.
*/
#pragma once

#include <map>
#include "TradeOffer.h"
#include "SellOffer.h"
#include "BuyOffer.h"

class TradeSystem {
private:
	TradeSystem();
	TradeSystem(const TradeSystem& other) = delete;
	TradeSystem& operator=(const TradeSystem& other) = delete;
	~TradeSystem();

public:
	/// <returns>The static instance of TradsSystem</returns>
	static TradeSystem& Instance();

	void Save();
	void Load();

	void Tick(int time);

private:
	std::multimap<int, SellOffer> sellOffers;
	std::multimap<int, BuyOffer> buyOffers;

	void SaveTrades();
	void LoadTrades();

	void CheckRemoveAllTradeOffers();

	/// <summary>
	/// Checks all of the local player trade offers and copies new, non-expired offers to the TradeSystem.
	/// Only runs if the player has created new trade offers or loaded new trade offers from file.
	/// </summary>
	void SyncLocalPlayerTradeOffers();
	bool IsNewSellOffer(const SellOffer& sellOffer);
	bool IsNewBuyOffer(const BuyOffer& buyOffer);
	bool ShouldRemoveTradeOffer(const TradeOffer& tradeOffer) const;

	void AddTradeOffers_ForTesting();
};