/*
Author - Isaac Richards
Date - 03SEP23
Description - Player is the class for players and their data.  The main instance of Player is the local player.
	Other players can be created by the client/server to interact with other players.
*/

#pragma once

#include <string>
#include <vector>
#include "TradeOffer.h"
#include "BuyOffer.h"
#include "SellOffer.h"
#include <memory>


class Player {
public:
	Player();

	/// <returns>Gets the static local player instance or creates it if it doesn't already exist.</returns>
	static Player& LocalPlayer();

	std::vector<std::shared_ptr<TradeOffer>> GetTradeOffers() const {
		return tradeOffers;
	}

	static void SetupLocalPlyaer();

	static bool LocalPlayerHasNewTradeOffers();

private:
	/// <summary>
	/// Set to true when new trade offers are created by the local player or loaded from file.
	/// </summary>
	static bool newTradeOffers;

	/// <summary>
	/// Contains All trade offers for this player.  Does not get removed when synced with the server or expired.
	/// Expired offers must be removed or refreshed by the player.
	/// </summary>
	std::vector<std::shared_ptr<TradeOffer>> tradeOffers;

	void CreateTradeOffersForTesting();

	#pragma region LocalPlayer

	void Save();
	void Load();

	#pragma endregion

	#pragma region NetPlayer



	#pragma endregion

};