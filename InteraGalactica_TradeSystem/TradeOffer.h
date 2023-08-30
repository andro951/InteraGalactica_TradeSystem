#pragma once

#include "json_nlohmann.h"
#include "ItemID.h"
#include <string>

class TradeOffer {
public:
	TradeOffer();

	TradeOffer(ItemID ItemType, int Value, int Quantity = 1);

private:
	ItemID itemType;
	int value;
	int quantity;
	const int DEFAULT_VALUE = -1;
	const int DEFAULT_QUANTITY = 0;

	const std::string ITEM_TYPE_NAME = "itemType";
	const std::string VALUE_NAME = "value";
	const std::string QUANTITY_NAME = "quantity";

public:
	#pragma region Get

	virtual ItemID GetItemType();
	virtual int GetValue();
	virtual int GetQuantity();

	#pragma endregion

	#pragma region Set

	virtual void SetItemType(ItemID newType);
	virtual void SetValue(int newValue);
	virtual void SetQuantity(int newQuantity);

	#pragma endregion

	virtual int GetContext() const = 0;
	virtual void Save(nlohmann::json& Data);
	virtual void Load(nlohmann::json& Data);
	virtual bool IsValid() const;
};