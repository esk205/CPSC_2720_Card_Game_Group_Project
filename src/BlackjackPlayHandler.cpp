#include "BlackjackPlayHandler.h"

BlackjackPlayHandler::BlackjackPlayHandler(Game* game)
{
    this->game = game;
    currentPlayerIndex = 0;
}

BlackjackPlayHandler::~BlackjackPlayHandler()
{
    this->game = nullptr;
}

void BlackjackPlayHandler::handle()
{
    dealerHand.addCard(game->deck.drawCard());
    dealerHand.addCard(game->deck.drawCard());

    for(int i = 0; i < game->players.size();i++)
    {
        Player* cPlayer = game->getCurrentPlayer();

        string options[] = {"Hit","Stay","Help"};
        Choices choice = Choices(options, 3);
        Hand* curPlayerHand = cPlayer->getHand();

        game->gameMenu.say("It is " + cPlayer->getName() + "'s turn.");
        displayHand(curPlayerHand);

        int pChoice = cPlayer->play("Hit or Stay?", choice);

        // While the player wants to hit and hasn't hit 21
        while(countBestHand(curPlayerHand) < 21 && (pChoice==1 || pChoice==3))
        {
            if(pChoice==3)
            {
                game->gameMenu.gameHelp(AppConstants::BLACKJACK_TYPE);
                pChoice = cPlayer->play("Hit or Stay?", choice);
                continue;
            }

            Card c = game->deck.drawCard();
            game->gameMenu.say("\nYou drew a " + c.getPip() + " of " + c.getSuit());
            curPlayerHand->addCard(c);
            game->gameMenu.say("\nNew Score: " + std::to_string(countBestHand(curPlayerHand)) + "\n"); // DEBUG
            pChoice = cPlayer->play("Hit or Stay?", choice);
        }

        game->gameMenu.clearScreen();

        game->gameMenu.say(cPlayer->getName()+"'s final score was " + std::to_string(countBestHand(curPlayerHand)) + "\n");

        nextPlayer();
    }

    game->gameMenu.clearScreen();

    // Dealer logic
    game->gameMenu.say("The Dealer begins his turn.\n");
    displayHand(&dealerHand);

    dealerHandCount = countBestHand(&dealerHand);

    while(dealerHandCount < 17)
    {
        Card c = game->deck.drawCard();
        game->gameMenu.say("The Dealer drew a " + c.getPip() + " of " + c.getSuit());
        dealerHand.addCard(c);
        dealerHandCount = countBestHand(&dealerHand);
        game->gameMenu.say("New Score: " + std::to_string(dealerHandCount));

    }

    game->gameMenu.say("\nThe Dealer stopped with a final score of " + std::to_string(dealerHandCount));

    game->gameMenu.say("\n\n" + AppConstants::PRESS_ENTER);

    cin.get(); cin.get();

    game->gameMenu.clearScreen();

    game->gameMenu.decoratedSay("\nThe Dealer's final score is " + std::to_string(dealerHandCount));

    for(int i = 0; i < game->players.size(); i++)
    {
        Player* p = game->players[i];
        Hand* h = p->getHand();
        int pCount = countBestHand(h);

        if(pCount <= 21)
        {
            if(dealerHandCount <= 21)
            {
                int diff = dealerHandCount - pCount;
                if(diff==0)
                    game->gameMenu.say(p->getName() + "'s final score is " + std::to_string(pCount) + ". TIE!");
                else if(diff<0)
                    game->gameMenu.say(p->getName() + "'s final score is " + std::to_string(pCount) + ". WINNER!");
                else
                    game->gameMenu.say(p->getName() + "'s final score is " + std::to_string(pCount) + ". LOSER!");
            }
            else
            {
                game->gameMenu.say(p->getName() + "'s final score is " + std::to_string(pCount) + ". WINNER!");
            }
        }
        else
        {
            game->gameMenu.say(p->getName() + "'s final score is " + std::to_string(pCount) + ". BUST!");
        }
    }

    game->gameMenu.say("\n\n" + AppConstants::PRESS_ENTER);

    cin.get();
}

int BlackjackPlayHandler::countWorstHand(Hand* h)
{
    int sum = 0;

    for(int i = 0; i < h->cardsRemaining(); i++)
    {
        int cValue = h->getCard(i).getRankingValue();

        // Ace has a ranking value of 11
        if(cValue != 11)
            sum += cValue;
        else
            sum += 1;
    }

    return sum;
}

int BlackjackPlayHandler::countBestHand(Hand* h)
{
    int aceCount = 0;
    int lowestHand = countWorstHand(h);
    int bestHand = lowestHand;
    // Count aces
    for(int i = 0; i < h->cardsRemaining(); i++)
    {
        if(h->getCard(i).getRankingValue()==11)
            aceCount++;
    }

    for(int i = 1; i <= aceCount; i++)
    {
        int newHand = lowestHand + (i * 10);
        if(newHand==21)
        {
            bestHand = 21;
            break;
        }
        else if(newHand < 21)
        {
            bestHand = newHand;
        }
    }
    return bestHand;
}

void BlackjackPlayHandler::displayHand(Hand* h)
{
    string message = "";
    int cnt = 0;

    for(int i = 0; i < h->cardsRemaining();i++)
    {
        Card c = h->getCard(i);
        message += c.getPip() + " of " + c.getSuit() + "\n ";

        int cValue = c.getRankingValue();

        if(cValue != 11)
            cnt += cValue;
        else
            cnt += 1;
    }

    message += "\nScore: " + std::to_string(cnt) + "\n";

    game->gameMenu.decoratedSay(message);
}

void BlackjackPlayHandler::nextPlayer()
{
    if(currentPlayerIndex < game->players.size()-1)
        currentPlayerIndex++;
    else
        currentPlayerIndex = 0;
    game->setCurrentPlayer(game->players[currentPlayerIndex]);
}
