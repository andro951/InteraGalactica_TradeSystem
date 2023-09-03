/*
Author - Isaac Richards
Date - 29AUG23
Description - Buy Offer is the class storing all trade offers which are used by the TradeSystem.
*/
#pragma once

#include "TradeOffer.h"

class BuyOffer : public TradeOffer {
public:
	BuyOffer();
	BuyOffer(ItemID ItemType, int Value, int Quantity = 1);

	/// <summary>
	/// Context() is used to determine what type of trade offer it is such as created by a player or npc.
	/// </summary>
	TradeContextID Context() const override;
	int TradeDuration() const override;
	virtual void Save(nlohmann::json& Data);
	virtual void Load(nlohmann::json& Data);
	std::string ToString() const override;

private:
	/// <summary>
	/// 2 Weeks in minutes.
	/// </summary>
	int TRADE_DURATION = TimeSystem::MINUTES_PER_WEEK * 2;
};