/*
Author - Isaac Richards
Date - 29AUG23
Description - Trade Offer is the base class for SellOffer and BuyOffer which are used by the TradeSystem.
	Trade offers have a duration to prevent some items from being suffocated by large long term offers.
*/
#pragma once

#include "json_nlohmann.h"
#include "ItemID.h"
#include <string>
#include "TimeSystem.h"

/// <summary>
/// Used to indicate the type of trade such as created by a player or NPC.
/// </summary>
enum class TradeContextID {
	None,
	Player,
	NPC
};

class TradeOffer {
public:
	TradeOffer();
	TradeOffer(ItemID ItemType, int Value, int Quantity = 1);

private:
	ItemID itemType;
	int value;

	/// <summary>
	/// Default value of "TradeOffer.value"
	/// </summary>
	const int DEFAULT_VALUE = -1;

	int quantity;

	/// <summary>
	/// Default value of "TradeOffer.quantity"
	/// </summary>
	const int DEFAULT_QUANTITY = 0;

	int timeCreated;

	/// <summary>
	/// Default value for TradeOffer.timeCreated.
	/// </summary>
	const int DEFAULT_TIME_CREATED = -1;

	/// <summary>
	/// Default value for TradeOffer.TradeDuration.
	/// </summary>
	const int DEFAULT_TRADE_DURATION = 0;

	/// <summary>
	/// Value of TradeOffer.tradeDuration that indicates unlimited duration.
	/// </summary>
	const int UNLIMITED_DURATION = -1;

	/// <summary>
	/// Value of TimeRemaining() returned when timeDuration == UNLIMITED_DURATION.
	/// </summary>
	const int UNLIMITED_TIME_REMAINING = TimeSystem::MINUTES_PER_YEAR;//1 Year

	const std::string ITEM_TYPE_NAME = "itemType";
	const std::string VALUE_NAME = "value";
	const std::string QUANTITY_NAME = "quantity";

protected:
	virtual int TimeRemaining() const;

public:
	#pragma region Get

	virtual ItemID GetItemType() const;
	virtual int GetValue() const;
	virtual int GetQuantity() const;
	virtual int GetTimeCreated() const;

	#pragma endregion

	#pragma region Set

	virtual void SetItemType(ItemID newType);
	virtual void SetValue(int newValue);
	virtual void SetQuantity(int newQuantity);

	#pragma endregion

	/// <returns>True if the duration of the trade has expired and the trade can be deleted from the Trade System.</returns>
	virtual bool Expired() const;
	virtual TradeContextID Context() const = 0;

	/// <returns>The duration the trade is allowed to exist before expiring and being deleted from the Trade System.</returns>
	virtual int TradeDuration() const = 0;
	virtual std::string ToString() const;
	virtual void Save(nlohmann::json& Data);
	virtual void Load(nlohmann::json& Data);

	/// <summary>
	/// Checks if the trade is valid such as having a valid item type, value, quantity, and time created.
	/// </summary>
	virtual bool IsValid() const;

	bool operator==(const TradeOffer& other) const;
};