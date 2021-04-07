#pragma once
#include "Header.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

// Add message for the logging file, for future reference when playing.
std::string rollMessage() {
	std::string message;
	std::cout << "Game Message: ";
	std::cin.ignore();
	std::getline(std::cin, message);
	return message;
}

// Get the current date and time
std::string curTime() {
	time_t result = time(nullptr);
	char date_str [26];
	ctime_s(date_str, sizeof date_str, &result);
	std::string time_to_return = date_str;
	return time_to_return;
}

// Used for writing the current date/time, roll information and roll message to dnd_log_file.txt
void::writeToFile(int die_number, int number_of_die, int number_rolled, std::string file_path) {
	std::ofstream dndFile;
	std::ifstream checkFile;
	driverc::CharacterStats stats;

	checkFile.open(file_path);
	if (checkFile) {
		checkFile.close();
		std::cout << "++ File exists" << std::endl;
		std::cout << "++ Writing to file" << std::endl;
		dndFile.open(file_path, std::ios_base::app);
		dndFile << "---------------------------------------" << std::endl;
		dndFile << curTime() << "Die num: " << die_number << ", Num of Die: " << number_of_die << ", Num rolled: " << number_rolled << std::endl;
		dndFile << "Roll Message: " << rollMessage() << std::endl;
		dndFile << "Current Health: " << stats.currentHealth() << std::endl;
		dndFile << "Current Level: " << stats.currentLevel() << std::endl;
	}
	else {
		checkFile.close();
		std::cout << "++ File does not exist." << std::endl;
		std::cout << "++ Creating dnd file needed, and writing to it." << std::endl;
		dndFile.open(file_path, std::ios::out);
		dndFile << "---------------------------------------" << std::endl;
		dndFile << curTime() << "Die num: " << die_number << ", Num of Die: " << number_of_die << ", Num rolled: " << number_rolled << std::endl;
		dndFile << "Roll Message: " << rollMessage() << std::endl;
		dndFile << "Current Health: " << stats.currentHealth() << std::endl;
		dndFile << "Current Level: " << stats.currentLevel() << std::endl;

	}
	dndFile.close();

}

