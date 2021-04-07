#pragma once
#include <random>
#include <ctime>

namespace driverc {

	// Class for the character stats.
	class CharacterStats {
		public:
			int currentHealth();
			int currentLevel();
	};

	// Class for the diceroll arithmetic.
	class DiceRoll {
		public:
			void rollDice() const;
	};

	// Class for game logger.
	class GameLogger {
		public:
			void writeToFile(int die_number, int number_of_die, int number_rolled, std::string file_path);
	};
};


