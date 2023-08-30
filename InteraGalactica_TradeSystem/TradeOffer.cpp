#include "TradeOffer.h"

TradeOffer::TradeOffer() {
	itemType = ItemID::None;
	value = DEFAULT_VALUE;
	quantity = DEFAULT_QUANTITY;
}

TradeOffer::TradeOffer(ItemID ItemType, int Value, int Quantity) : itemType(ItemType), value(Value), quantity(Quantity) {}

#pragma region Get

ItemID TradeOffer::GetItemType() {
	return itemType;
}

int TradeOffer::GetValue() {
	return value;
}

int TradeOffer::GetQuantity() {
	return quantity;
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
	return value > DEFAULT_VALUE && quantity > DEFAULT_QUANTITY;
}