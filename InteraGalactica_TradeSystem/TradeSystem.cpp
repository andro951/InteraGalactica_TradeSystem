#include "TradeSystem.h"

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

void TradeSystem::SaveTrades() {
	//TODO:
}

void TradeSystem::LoadTrades() {
	//TODO:
}
