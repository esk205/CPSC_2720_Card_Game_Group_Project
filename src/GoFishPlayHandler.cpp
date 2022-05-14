#include "GoFishPlayHandler.h"

GoFishPlayHandler::GoFishPlayHandler(Game* game)
{
    this->game = game;

    // create piles for all the players in the game.
    // all players should already be in game at this point.
    for (int i = 0; i < this->game->players.size(); i++)
    {
        Player* p = this->game->players[i];
        piles.insert(pair<string, int>(p->getName(), 0));
    }
}

GoFishPlayHandler::~GoFishPlayHandler()
{
    this->game = nullptr;
    piles.clear();
    lastMessage.clear();
    winner.clear();
}

void GoFishPlayHandler::handle()
{
    nextPlayer();
    promptPlayer();
}

void GoFishPlayHandler::promptPlayer()
{
    if (winCondition()){
        this->game->state = State::END;
    }

    drawGame();
    string opts[] = {
        "Ask for card",
        "Pause",
        "Help",
        "Save",
        "Quit"
    };

    Choices c = Choices(opts, 5);
    int selection = this->game->getCurrentPlayer()->play(AppConstants::MESSAGE_SELECT_OPTION, c);
    if (selection == 1) {
        Player* p = selectOpponentToFish();
        askOpponentForCards(p);
    } else if (selection == 3) {
        game->gameMenu.gameHelp(AppConstants::GO_FISH_TYPE);
        game->gameMenu.say(AppConstants::PRESS_ENTER);
        cin.get(); cin.get();

        promptPlayer();
    } else if (selection == 4) {
        SaveHandler s = SaveHandler(game, "gofish.txt");
        s.handle();
        game->gameMenu.say("Saved to -> gofish.txt");
        game->gameMenu.say(AppConstants::PRESS_ENTER);
        cin.get(); cin.get();

        promptPlayer();
    }
}

void GoFishPlayHandler::askOpponentForCards(Player* opponent)
{
    drawGame();
    Player* currentPlayer = this->game->getCurrentPlayer();
    vector<Card> cardsInHand = currentPlayer->getHand()->getCards();
    vector<string> pipToAskFor;
    for (int i = 0; i < cardsInHand.size(); i++) {
        bool found = (find(pipToAskFor.begin(), pipToAskFor.end(), cardsInHand[i].getPip()) != pipToAskFor.end());
        if (!found)
        {
            pipToAskFor.push_back(cardsInHand[i].getPip());
        }
    }

    Choices c = Choices(&pipToAskFor[0], pipToAskFor.size());
    int selection = game->getCurrentPlayer()->play(AppConstants::MESSAGE_SELECT_OPTION, c);
    string pip = pipToAskFor[selection - 1];
    lastMessage = "Asking " + opponent->getName() + " for " + pip + "'s";
    handleFish(opponent, pip);
}

void GoFishPlayHandler::handleFish(Player* opponent, string pip)
{
    drawGame();
    this->game->gameMenu.say("Asking " + opponent->getName() + " for any " + pip + "'s");
    int taken = takeCards(opponent, pip);
    if (taken > 0) {
        lastMessage = "Got " + to_string(taken) + " cards from " + opponent->getName();
        promptPlayer();
    } else {
        lastMessage = "Turn was passed";
        passTurn();
    }
}

int GoFishPlayHandler::takeCards(Player* opponent, string pip)
{
    int result = 0;
    int cardsRemaining = opponent->getHand()->getCards().size();
    for (int i = cardsRemaining - 1; i >= 0; i--) {
        if (opponent->getHand()->getCard(i).getPip() == pip){
            Card pick = opponent->getHand()->removeCard(i);
            this->game->getCurrentPlayer()->getHand()->addCard(pick);
            result += 1;
        }
    }
    checkForPile(pip);
    return result;
}

void GoFishPlayHandler::checkForPile(string pip)
{
    int cards = 0;
    Player* current = this->game->getCurrentPlayer();
    int cardsRemaining = current->getHand()->getCards().size();
    for (int i = cardsRemaining - 1; i >= 0; i--) {
        if (current->getHand()->getCard(i).getPip() == pip) {
            cards += 1;
        }
    }

    if (cards >= 4) {
        for (int i = cardsRemaining -1; i >= 0; i--) {
            if (current->getHand()->getCard(i).getPip() == pip) {
                current->getHand()->removeCard(i);
            }
        }
        lastMessage = current->getName() + " got a " + pip + " pile! ";
        piles[current->getName()] += 1;
    }
}

void GoFishPlayHandler::passTurn()
{
    Card c = this->game->deck.drawCard();
    this->game->getCurrentPlayer()->getHand()->addCard(c);
    nextPlayer();
    promptPlayer();
}

Player* GoFishPlayHandler::selectOpponentToFish()
{
    drawGame();
    int playerCount = this->game->players.size();
    vector<string> opts;
    vector<Player*> availablePlayers;

    for(int i = 0; i < playerCount; i ++)
    {
        Player* player = this->game->players[i];
        if (player->getName() != this->game->getCurrentPlayer()->getName())
        {
            opts.push_back(player->getName());
            availablePlayers.push_back(player);
        }
    }

    Choices c = Choices(&opts[0], opts.size());
    int selection = game->getCurrentPlayer()->play(AppConstants::MESSAGE_SELECT_PLAYER, c);
    Player* selected = availablePlayers[selection - 1]; // -1 to correct for index.
    return selected;
}

void GoFishPlayHandler::nextPlayer()
{
    // we need to iterate through the players here.
    Player* current = this->game->getCurrentPlayer();
    int currentIndex = -1;
    for (int i = 0; i < this->game->players.size(); i++)
    {
        if (this->game->players[i]->getName() == current->getName())
        {
            currentIndex = i + 1;
            break;
        }
    }

    if (currentIndex >= this->game->players.size())
        this->game->setCurrentPlayer(this->game->players[0]);
    else
        this->game->setCurrentPlayer(this->game->players[currentIndex]);

    lastMessage = "Play was passed to " + this->game->getCurrentPlayer()->getName();
}

void GoFishPlayHandler::showGameStats()
{
    this->game->gameMenu.say("----------------------");
    this->game->gameMenu.say(this->game->getCurrentPlayer()->getName() + "'s Turn:");
    this->game->gameMenu.say("----------------------");
    for (int i = 0; i < this->game->players.size(); i++)
    {
        Player* p = this->game->players[i];
        this->game->gameMenu.say(p->getName() + " has " + to_string(piles[p->getName()]) + " piles.");
    }
    this->game->gameMenu.say("----------------------");
    this->game->gameMenu.say(lastMessage);
    lastMessage = "";
}

void GoFishPlayHandler::showHand()
{
    this->game->gameMenu.say("");
    this->game->gameMenu.say("----------------------");
    this->game->gameMenu.say("Your Hand:");
    this->game->gameMenu.say("----------------------");
    Hand* hand = this->game->getCurrentPlayer()->getHand();
    this->game->gameMenu.say(hand->to_string());
    this->game->gameMenu.say("----------------------");
    this->game->gameMenu.say("");
}

bool GoFishPlayHandler::winCondition()
{
    int totalPiles = 0;
    int lastValue = 0;

    string winner = "";
    for (auto const& pile : piles)
    {
        int value = pile.second;
        totalPiles += pile.second;

        if (value > lastValue) {
            lastValue = value;
            winner = pile.first;
        }
    }

    if (totalPiles >= AppConstants::GO_FISH_MAX_PILES)
    {
        this->winner = winner;
        this->drawWinner();
        return true;
    }
    return false;
}

void GoFishPlayHandler::drawGame()
{
    this->game->gameMenu.clearScreen();
    this->game->getCurrentPlayer()->getHand()->sortByValue();
    showGameStats();
    showHand();
}

void GoFishPlayHandler::drawWinner()
{
    this->game->gameMenu.clearScreen();
    this->game->gameMenu.decoratedSay("The Winner Is: " + this->winner);
}
