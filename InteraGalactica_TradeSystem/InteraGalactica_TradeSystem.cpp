/*
Author - Isaac Richards
Date - 29AUG23
Description - Trade system in development for use in InterraGalactic.  
The trade system will be able to allow any player to create and view buy/sell orders for every trade-able item in the game.

SDEV-345 Week 1 C++ Warm-up requirements:
    -driver class that utilized minimum code to drive the program.  Coding details shall be in appropriately-implemented classes
        -driver class: Game

    -At least three class modules, other than the driver class, one class shall be abstract and an associated derived class.
        -abstract: TradeOffer
        -derived: SellOffer, BuyOffer

    -At least one example of an overloaded constructor.
        -TradeOffer

    -At least one polymorphic method
        -

    -At least one pointer and one reference
        -reference: Logging.cpp, Log()
        -pointer: 

    -Demonstrate correct use of public, private and protected keywords
        -TradeOffer, SellOffer, BuyOffer
*/

#include <iostream>
#include "Game.h"

int main() {
    Game::Instance().Start();
}