/*
Author - Isaac Richards
Date - 29AUG23
Description - Buy Offer is the class storing all trade offers which are used by the TradeSystem.
*/
#include "BuyOffer.h"

BuyOffer::BuyOffer() : TradeOffer() {}

BuyOffer::BuyOffer(ItemID ItemType, int Value, int Quantity) : TradeOffer(ItemType, Value, Quantity) {}

TradeContextID BuyOffer::Context() const {
    return TradeContextID::Player;
}

int BuyOffer::TradeDuration() const {
    return TRADE_DURATION;
}

void BuyOffer::Save(nlohmann::json& Data) {
    TradeOffer::Save(Data);
}

void BuyOffer::Load(nlohmann::json& Data) {
    TradeOffer::Load(Data);
}

std::string BuyOffer::ToString() const {
    return "B: " + TradeOffer::ToString();
}
