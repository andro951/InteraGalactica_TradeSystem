/*
Author - Isaac Richards
Date - 29AUG23
Description - Buy Offer is the class storing all trade offers which are used by the TradeSystem.
*/
#include "SellOffer.h"

SellOffer::SellOffer() : TradeOffer() {}

SellOffer::SellOffer(ItemID ItemType, int Value, int Quantity) : TradeOffer(ItemType, Value, Quantity) {}

TradeContextID SellOffer::Context() const {
    return TradeContextID::Player;
}

int SellOffer::TradeDuration() const {
    return TRADE_DURATION;
}

void SellOffer::Save(nlohmann::json& Data) {
    TradeOffer::Save(Data);
}

void SellOffer::Load(nlohmann::json& Data) {
    TradeOffer::Load(Data);
}

std::string SellOffer::ToString() const {
    return "S: " + TradeOffer::ToString();
}
