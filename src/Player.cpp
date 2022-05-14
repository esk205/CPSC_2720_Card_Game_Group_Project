#include "Player.h"
#include "AppConstants.h"
#include "Menu.h"

Player::Player()
{
    name = AppConstants::UNKNOWN_PLAYER;
    score = 0;
}

Player::~Player()
{
    name.clear();
}

int Player::play(string message, Choices c)
{
    Menu playMenu = Menu();
    return playMenu.prompt(message, c);
}

string Player::getName()
{
    return name;
}

void Player::setName(string playerName)
{
    name = playerName;
}

double Player::getScore()
{
    return score;
}

void Player::setScore(double value)
{
    score = value;
}

Hand* Player::getHand()
{
    return &hand;
}

Deck* Player::getDiscard()
{
    return &discard;
}
