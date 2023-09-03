/*
Author - Isaac Richards
Date - 29AUG23
Description - Game is a "static" class that runs everything in the game.
	To run the game, access the static instance with Game::Instance() then call Start().
*/

#pragma once

class Game {
private:
	Game();
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game();

public:
	/// <returns>The static Game object or creates and returns it if not previously called.</returns>
	static Game& Instance();

	/// <summary>
	/// Sets up and begins the game.
	/// </summary>
	void Start();

	/// <summary>
	/// Causes the game to stop at the end of the current game tick.
	/// </summary>
	void Stop();

private:
	bool running = false;

	void Setup();
	void Load();
	void Cleanup();

	void Run();
	void Tick();
};