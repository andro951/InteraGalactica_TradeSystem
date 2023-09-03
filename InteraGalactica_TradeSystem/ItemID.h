/*
Author - Isaac Richards
Date - 29AUG23
Description - ItemID is the unique identifiers for each type of item (not each instance).
For example, 2 iron ore objects will have the same ItemID, but no other types of items in the game will share that ItemID.
*/
#pragma once

enum class ItemID {
	None,
	IronOre,
	GoldOre,
	IronMetal,
	GoldMetal,
};