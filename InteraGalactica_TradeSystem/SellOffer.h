/*
Author - Isaac Richards
Date - 29AUG23
Description - Buy Offer is the class storing all trade offers which are used by the TradeSystem.
*/
#pragma once

#include "TradeOffer.h"

class SellOffer : public TradeOffer {
public:
	SellOffer();
	SellOffer(ItemID ItemType, int Value, int Quantity = 1);

	TradeContextID Context() const override;
	int TradeDuration() const override;
	virtual void Save(nlohmann::json& Data);
	virtual void Load(nlohmann::json& Data);
	std::string ToString() const override;

private:
	/// <summary>
	/// 1 Week in minutes.
	/// </summary>
	int TRADE_DURATION = TimeSystem::MINUTES_PER_WEEK;
};