#pragma once

#include "ItemID.h"

class Item {
public:
	Item();
	Item(ItemID Type, int Quantity);

	ItemID GetType();
	int GetQuantity();

private:
	ItemID type;
	int quantity;
	const int DEFAULT_QUANTITY = 0;
};