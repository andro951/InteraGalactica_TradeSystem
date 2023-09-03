/*
Author - Isaac Richards
Date - 29AUG23
Description - Trade Offer is the base class for SellOffer and BuyOffer which are used by the TradeSystem.
*/
#include "TradeOffer.h"

TradeOffer::TradeOffer() {
	itemType = ItemID::None;
	value = DEFAULT_VALUE;
	quantity = DEFAULT_QUANTITY;
	timeCreated = DEFAULT_TIME_CREATED;
}

TradeOffer::TradeOffer(ItemID ItemType, int Value, int Quantity) : itemType(ItemType), value(Value), quantity(Quantity) {
	timeCreated = TimeSystem::GetNow();
}

#pragma region Get

int TradeOffer::TimeRemaining() const {
	int tradeDuration = TradeDuration();
	if (tradeDuration == UNLIMITED_DURATION)
		return UNLIMITED_TIME_REMAINING;

	return GetTimeCreated() + tradeDuration - TimeSystem::GetNow();
}

ItemID TradeOffer::GetItemType() const {
	return itemType;
}

int TradeOffer::GetValue() const {
	return value;
}

int TradeOffer::GetQuantity() const {
	return quantity;
}

int TradeOffer::GetTimeCreated() const {
	return timeCreated;
}

#pragma endregion

#pragma region Set

void TradeOffer::SetItemType(ItemID newType) {
	itemType = newType;
}

void TradeOffer::SetValue(int newValue) {
	value = newValue;
}

void TradeOffer::SetQuantity(int newQuantity) {
	quantity = newQuantity;
}

#pragma endregion

bool TradeOffer::Expired() const {
	return TimeRemaining() <= 0;
}

std::string TradeOffer::ToString() const {
	std::string s = "SellOffer { itemType: " + std::to_string(static_cast<int>(GetItemType())) + ", value: " + std::to_string(GetValue()) + ", quantity: " + std::to_string(GetQuantity()) + ", timeCreated: " + std::to_string(GetTimeCreated()) + " }";
	return s;
}

void TradeOffer::Save(nlohmann::json& Data) {
	Data[ITEM_TYPE_NAME] = itemType;
	Data[VALUE_NAME] = value;
	Data[QUANTITY_NAME] = quantity;
}

void TradeOffer::Load(nlohmann::json& Data) {
	itemType = Data[ITEM_TYPE_NAME];
	value = Data[VALUE_NAME];
	quantity = Data[QUANTITY_NAME];
}

bool TradeOffer::IsValid() const {
	return itemType > ItemID::None && value > DEFAULT_VALUE && quantity > DEFAULT_QUANTITY && timeCreated > DEFAULT_TIME_CREATED;
}

bool TradeOffer::operator==(const TradeOffer& other) const {
	return GetItemType() == other.GetItemType() && GetValue() == other.GetValue() && GetQuantity() == other.GetQuantity() && GetTimeCreated() == other.GetTimeCreated();
}