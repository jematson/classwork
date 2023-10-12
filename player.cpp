// player.cpp
// Jenae Matson
// 2023-9-12
// Source for Player class

#include "player.hpp"
#include <iostream> //for ostream and string
#include <cassert>	//for assert
#include <string>	//for toString function

// *********************************************
// Class Player: Definiton of member functions
// *********************************************

// Player::getRealName
std::string Player::getRealName() const {
	return _realname;
}

// Player::getUsername
std::string Player::getUsername() const {
	return _username;
}

// Player::getGames
int Player::getGames() const {
	return _gamesPlayed;
}

// Player::setRealName
void Player::setRealName(std::string name) {
	_realname = name;
}

// Player::setUsername
void Player::setUsername(std::string name) {
	_username = name;
}

// Player::setGames
void Player::setGames(int games) {
	assert(games >= 0);
	
	_gamesPlayed = games;
}

// Player::inactive
bool Player::inactive() const {
	return _gamesPlayed == 0;
}

// Player::toString
std::string Player::toString()  const {
	return _realname + " (" + _username + "): " + std::to_string(_gamesPlayed);
}


// *******************************************************
// Class Player: Definiton of associated global operators
// *******************************************************

// Stream insertion operator <<
std::ostream& operator<<(std::ostream& out, const Player& p) {
	out << p.toString();
	return out;
}

// Equality operator ==
bool operator==(const Player& p1, const Player& p2) {
	return (p1.getRealName() == p2.getRealName() &&
		p1.getUsername() == p2.getUsername() &&
		p1.getGames() == p2.getGames());
}

// Inequality operator !=
bool operator!=(const Player& p1, const Player& p2) {
	return (p1.getRealName() != p2.getRealName() ||
		p1.getUsername() != p2.getUsername() ||
		p1.getGames() != p2.getGames());
}

