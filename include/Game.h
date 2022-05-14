#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Menu.h"
#include "Player.h"
#include "State.h"
#include "StateHandler.h"

using namespace std;

class Game
{
public:
    vector<Player*> players;
    Menu gameMenu;
    Deck deck;
    Deck discard;
    State state;
    bool paused;
    int turn;

    Game();

    virtual ~Game();
    /**
    * @brief starts a given game
    */
    void startGame();

    /**
    * @brief adds a player (bot) to the game
    */
    void addPlayer(Player* player);

    /**
    * @brief removes a player from the game
    */
    void removePlayer(string player);

    /**
    * @brief getter method to get the current player
    * @return player pointer
    */
    Player* getCurrentPlayer();

    /**
    * @brief sets the current player
    */
    void setCurrentPlayer(Player* player);

    /**
    * @brief saves the game state to a file
    */
    void save(string file);

    /**
    * @brief loads a previously saved game from a file
    */
    void load(string file);

    /**
    * @brief Initializes the Player variable and sets the player name
    */
    void createPlayer();

    /**
    * @brief Gives the player the available bots to choose from and returns the choice int.
    */
    void chooseOpponent();

    /**
    * @brief Prompts the player if they'd like to add more opponents to the game.
    */
    void getOpponents(int maxPlayers);

    /**
    * @brief Returns the type of game, this is primarily going to be used for gameFactory.
    **/
    int getGameType();

protected:
    StateHandler* handler;
    Player* currentPlayer;

    int gameType;

    /**
    * @brief Gets the the current state handler for the game.
    */
    StateHandler* getStateHandler();

    /**
    * @brief Sets the current state handler for the game.
    */
    void setStateHandler(StateHandler* stateHandler);

    /**
    * @brief used to update the state of the game.
    */
    virtual void update();

    /**
    * @brief deals cards to the players.
    */
    virtual void dealCards();

    /**
    * @brief makes the choices for the game.
    */
    virtual void makeChoices();

private:
};

#endif // GAME_H
