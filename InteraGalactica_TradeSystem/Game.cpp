#include "Game.h"
#include "TradeSystem.h"
#include <string>
#include "Logging.h"

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

    Load();

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
    RunTesting();//Temporary for testing.
    Stop();//Temporary for testing.
}

void Game::RunTesting() {
    LogString("Starting Run Testing.");



    LogString("Completed Run Testing.");
}
