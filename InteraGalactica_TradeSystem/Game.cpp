/*
Author - Isaac Richards
Date - 29AUG23
Description - Game is a "static" class that runs everything in the game.
    To run the game, access the static instance with Game::Instance() then call Start().
*/

#include "Game.h"
#include "TradeSystem.h"
#include <string>
#include "Logging.h"
#include "TimeSystem.h"
#include "Player.h"

Game::Game() {}

Game::~Game() {
    Cleanup();
}

Game& Game::Instance() {
    static Game instance;
    return instance;
}

void Game::Start() {
    LogMessage(MessageID::GameStart);
    Setup();
    Run();
}

void Game::Stop() {
    LogMessage(MessageID::GameStop);
    running = false;
}

void Game::Setup() {
    LogMessage(MessageID::GameSetup);

    TimeSystem::Setup();
    Load();
    Player::SetupLocalPlyaer();

    LogMessage(MessageID::GameSetupComplete);
}

void Game::Load() {
    LogMessage(MessageID::GameLoad);

    TradeSystem::Instance().Load();

    LogMessage(MessageID::GameLoadComplete);
}

void Game::Cleanup() {
    LogMessage(MessageID::GameCleanup);



    LogMessage(MessageID::GameCleanupComplete);
}

void Game::Run() {
    LogMessage(MessageID::GameRun);
    running = true;
    while (running) {
        Tick();
    }
}

void Game::Tick() {
    TimeSystem::UpdateTime();
    int time = TimeSystem::GetNow();

    TradeSystem::Instance().Tick(time);
    Stop();//Temporary for testing.
}