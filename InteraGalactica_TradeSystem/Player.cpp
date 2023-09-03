/*
Author - Isaac Richards
Date - 03SEP23
Description - Player is the class for players and their data.  The main instance of Player is the local player.
	Other players can be created by the client/server to interact with other players.
*/

#include "Player.h"

Player::Player() {}

bool Player::newTradeOffers = false;

Player& Player::LocalPlayer() {
    static Player localPlayer;
	return localPlayer;
}

void Player::SetupLocalPlyaer() {
	Player& localPlayer = LocalPlayer();
	localPlayer.Load();
	newTradeOffers = localPlayer.tradeOffers.size() > 0;
}

bool Player::LocalPlayerHasNewTradeOffers() {
	return newTradeOffers;
}

void Player::CreateTradeOffersForTesting() {
	tradeOffers.push_back(std::make_shared<BuyOffer>(ItemID::IronOre, 220, 1000));
	tradeOffers.push_back(std::make_shared<SellOffer>(ItemID::IronOre, 250, 1000));
}

void Player::Save() {
	//TODO:
}

void Player::Load() {
	CreateTradeOffersForTesting();
	//TODO:
}
