/*
Author - Isaac Richards
Date - 29AUG23
Description - TradeSystem is a "static" class that manages all trading in the game.
*/
#include "TradeSystem.h"
#include <vector>
#include <set>
#include "Logging.h"
#include "multimap.h"
#include "Player.h"

#pragma optimize("", off)

TradeSystem::TradeSystem() {}

TradeSystem::~TradeSystem() {}

TradeSystem& TradeSystem::Instance() {
	static TradeSystem instance;
	return instance;
}

void TradeSystem::Save() {
	SaveTrades();
}

void TradeSystem::Load() {
	LoadTrades();
}

void TradeSystem::Tick(int time) {
	AddTradeOffers_ForTesting();
	SyncLocalPlayerTradeOffers();
	CheckRemoveAllTradeOffers();
}

void TradeSystem::SaveTrades() {
	//TODO:
}

void TradeSystem::LoadTrades() {
	//TODO:
}

void TradeSystem::CheckRemoveAllTradeOffers() {
	std::vector<std::multimap<int, SellOffer>::iterator> sellOfferIterators;
	std::set<int> keys = multimap::GetUniqueKeys(sellOffers);
	for (const auto& i : keys) {
		auto range = sellOffers.equal_range(i);
		for (auto it = range.first; it != range.second; ++it) {
			SellOffer& sellOffer = it->second;
			if (ShouldRemoveTradeOffer(sellOffer) || it->first <= 0)// || it->first <= 0 for testing only.  TODO: delete this
				sellOfferIterators.push_back(it);
		}
	}

	for (auto it : sellOfferIterators) {
		if (LogTradeOffers()) {
			Log("Removed from Sell Offers:" + it->second.ToString());
		}

		sellOffers.erase(it);
	}

	std::vector<std::multimap<int, BuyOffer>::iterator> buyOfferIterators;
	keys = multimap::GetUniqueKeys(buyOffers);
	for (const auto& i : keys) {
		auto range = buyOffers.equal_range(i);
		for (auto it = range.first; it != range.second; ++it) {
			BuyOffer& buyOffer = it->second;
			if (ShouldRemoveTradeOffer(buyOffer) || it->first <= 0)// || it->first <= 0 for testing only.  TODO: delete this
				buyOfferIterators.push_back(it);
		}
	}

	for (auto it : buyOfferIterators) {
		if (LogTradeOffers()) {
			Log("Removed from Buy Offers:" + it->second.ToString());
		}

		buyOffers.erase(it);
	}
}

void TradeSystem::SyncLocalPlayerTradeOffers() {
	if (!Player::LocalPlayerHasNewTradeOffers())
		return;

	std::vector<std::shared_ptr<TradeOffer>> localPlayerTradeOffers = Player::LocalPlayer().GetTradeOffers();
	for (const auto& tradeOffer : localPlayerTradeOffers) {
		bool addedNewOffer = false;
		if (std::shared_ptr<SellOffer> sellOfferPtr = std::dynamic_pointer_cast<SellOffer>(tradeOffer)) {
			//SellOffer
			SellOffer sellOffer = *sellOfferPtr;
			if (IsNewSellOffer(sellOffer) && !ShouldRemoveTradeOffer(sellOffer)) {
				//Add if new and not expired
				sellOffers.insert(std::make_pair(sellOffer.GetTimeCreated(), sellOffer));
				addedNewOffer = true;
			}
		}
		else if (std::shared_ptr<BuyOffer> buyOfferPtr = std::dynamic_pointer_cast<BuyOffer>(tradeOffer)) {
			//BuyOffer
			BuyOffer buyOffer = *buyOfferPtr;
			if (IsNewBuyOffer(buyOffer) && !ShouldRemoveTradeOffer(buyOffer)) {
				//Add if new and not expired
				buyOffers.insert(std::make_pair(buyOffer.GetTimeCreated(), buyOffer));
				addedNewOffer = true;
			}
		}

		if (addedNewOffer && LogTradeOffers()) {
			Log("Added new trade offer: " + tradeOffer->ToString());
		}
	}
}

bool TradeSystem::IsNewSellOffer(const SellOffer& sellOffer) {
	for (const auto& existingOffer : sellOffers) {
		if (existingOffer.second == sellOffer)
			return false;
	}

	return true;
}

bool TradeSystem::IsNewBuyOffer(const BuyOffer& buyOffer) {
	for (const auto& existingOffer : buyOffers) {
		if (existingOffer.second == buyOffer)
			return false;
	}

	return true;
}

bool TradeSystem::ShouldRemoveTradeOffer(const TradeOffer& tradeOffer) const {
	return !tradeOffer.IsValid() || tradeOffer.Expired();
}




void TradeSystem::AddTradeOffers_ForTesting() {
	sellOffers = {
		{ 15, SellOffer(ItemID::IronOre, 251, 7)},
		{ 0, SellOffer(ItemID::IronMetal, 584, 2)},
		{ 200, SellOffer(ItemID::None, 100000, 99999)},
		{ 0, SellOffer(ItemID::GoldOre, 4871, 1)},
		{ 500, SellOffer(ItemID::GoldMetal, 6123, 50)}
	};

	buyOffers = {
		{ 0, BuyOffer(ItemID::IronOre, 240, 47)},
		{ 7, BuyOffer(ItemID::IronMetal, 583, 15)},
		{ 1, BuyOffer(ItemID::GoldMetal, 6200, 10)},
		{ 5000, BuyOffer(ItemID::None, 200000, 100000)},
		{ 0, BuyOffer(ItemID::GoldOre, 4700, 100)}
	};


	if (LogTradeOffers()) {
		LogString("Sell Offers:");
		for (auto it = sellOffers.begin(); it != sellOffers.end(); ++it) {
			Log(it->second.ToString());
		}

		LogString("Buy Offers:");
		for (auto it = buyOffers.begin(); it != buyOffers.end(); ++it) {
			Log(it->second.ToString()); 
		}
	}
}