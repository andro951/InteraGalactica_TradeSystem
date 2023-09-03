/*
Author - Isaac Richards
Date - 29AUG23
Description - Item is the base class for all items in the game.
*/
#include "Item.h"

Item::Item() {
	type = ItemID::None;
	quantity = DEFAULT_QUANTITY;
}

Item::Item(ItemID Type, int Quantity) : type(Type), quantity(Quantity) {}

ItemID Item::GetType() const {
	return type;
}

int Item::GetQuantity() const {
	return quantity;
}