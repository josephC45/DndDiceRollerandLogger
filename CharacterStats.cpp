#pragma once
#include <iostream>
#include "Header.h";

// Allows recording of current health.
int currentHealth() {
	int health;
	std::cout << "Current Health: ";
	std::cin >> health;
	std::cin.ignore();
	return health;
}

int currentCharacterLevel() {
	int level;
	std::cout << "Curent Level: ";
	std::cin >> level;
	return level;
}