#pragma once
#include "Header.h";
#include <iostream>;

void::driverc::DiceRoll::rollDice() const {
	GameLogger gl;
	int die_number;
	int number_of_die;

	std::cout << "This is a dice program meant for playing dnd..." << std::endl;
	std::cout << "Enter the corresponding die (die type: 4,6,8,10,12,20): ";
	std::cin >> die_number;
	std::cout << "Enter the number of die you wish to roll: ";
	std::cin >> number_of_die;

	int maximum_roll = die_number * number_of_die;
	int minimum_roll = number_of_die;

	std::default_random_engine random_generator(time(nullptr));
	std::uniform_int_distribution<int> die_roll(minimum_roll, maximum_roll);
	int number_rolled = die_roll(random_generator);

	if (number_rolled == 21) {
		std::cout << "CRIT! You rolled a 21." << std::endl;
	}
	else {
		std::cout << "You rolled " << number_rolled << std::endl;
	}
	gl.writeToFile(die_number, number_of_die, number_rolled, /*Your dnd file*/);
}

