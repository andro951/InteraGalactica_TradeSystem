/*
Author - Isaac Richards
Date - 29AUG23
Description - Item is the base class for all items in the game.
*/
#pragma once

#include "ItemID.h"

class Item {
public:
	Item();
	Item(ItemID Type, int Quantity);

	ItemID GetType() const;
	int GetQuantity() const;

private:
	ItemID type;
	int quantity;
	const int DEFAULT_QUANTITY = 0;
};