#include "Item.h"

Item::Item() {
	type = ItemID::None;
	quantity = DEFAULT_QUANTITY;
}

Item::Item(ItemID Type, int Quantity) : type(Type), quantity(Quantity) {}

ItemID Item::GetType() {
	return type;
}

int Item::GetQuantity() {
	return quantity;
}