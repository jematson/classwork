// player.h
// Jenae Matson
// 2023-9-12
// Header for Player class

#pragma once
#include <iostream>
#include <cassert>	// for assert

// *********************************
// Class Player - class definition
// *********************************

class Player {

// ******* Player: Constructors, destructors, copy/move, etc. *******
public:
	// Default constructor
	// Set real name and username to "UNKNOWN" and # of games to 0
	Player() 
		: _realname("UNKNOWN"), _username("UNKNOWN"), _gamesPlayed(0)
	{}

	// Constructor from 2 strings and a number
	// Set real name and user name to given strings, and games played to given int
	Player(std::string rName, std::string uName, int games)
		: _realname(rName), _username(uName), _gamesPlayed(games)
	{
		assert(games >= 0);
	}

	// Destructor and copy/move operators are automatically generated

// ******* Player: General public operators ******

	// pre ++ operator
	// Increase games played by 1
	Player& operator++() {
		assert(_gamesPlayed >= 0);
		
		++_gamesPlayed;
		return *this;
	}

	// post ++ operator
	// Increase games played by 1
	Player operator++([[maybe_unused]] int dummy) {
		assert(_gamesPlayed >= 0);
		
		auto save = *this;
		++(*this);
		return save;
	}

	// pre -- operator
	// Decrease games played by 1
	Player& operator--() {
		assert(_gamesPlayed >= 0);

		--_gamesPlayed;
		if (_gamesPlayed < 0)
			_gamesPlayed = 0;
		return *this;
	}

	// post -- operator
	// Decrease games played by 1
	Player operator--([[maybe_unused]] int dummy) {
		assert(_gamesPlayed >= 0);
		
		auto save = *this;
		--(*this);
		if (_gamesPlayed < 0)
			_gamesPlayed = 0;
		return save;
	}


// ******* Player: Member function declarations *******

	// getRealName
	// Return the player's real name
	std::string getRealName() const;

	// getUsername
	// Return the player's username
	std::string getUsername() const;

	// getGames
	// Return the number of games the player has played
	int getGames() const;

	// setRealName
	// Set the player's real name to that given
	void setRealName(std::string name);

	// setUsername
	// Set the player's username to that given
	void setUsername(std::string name);

	// setGames
	// Set the number of games played to that given
	void setGames(int games);

	// inactive
	// Returns true if games played is 0, and false otherwise
	bool inactive() const;

	// toString
	// Returns a string representation of the player
	std::string toString()  const;


// ******* Player: Data members *******
private:

	std::string _realname;
	std::string _username;
	int _gamesPlayed;

};	//End of Player class


// ******* Player: Global operator declarations *******

// Stream insertion operator <<
// Prints a Player object as defined in the toString function
std::ostream& operator<<(std::ostream& out, const Player& p);

// Equality operator ==
// Returns true if realName, username, and  games played are equal
bool operator==(const Player& p1, const Player& p2);

// Inequality operator !=
// Returns true if realName, username, and games played are all unequal
bool operator!=(const Player& p1, const Player& p2);