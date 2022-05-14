#include "CrazyEightsPlayHandler.h"
#include "stdlib.h"

CrazyEightsPlayHandler::CrazyEightsPlayHandler(Game* game) {
    this->game = game;
    setMatchCard(game->deck.drawCard());
    /// @todo fix exit game option. Fixed for now.
    /// @todo Implement bot logic properly. Needs fixing.
}
CrazyEightsPlayHandler::~CrazyEightsPlayHandler() {
    delete game;
    game = nullptr;
    resultMessage.clear();
}
void CrazyEightsPlayHandler::handle() {
    playRound();
}
int CrazyEightsPlayHandler::calculateScore(int index) {
    int score = 0;
    int cardsLeft = game->players[index]->getHand()->cardsRemaining();
    for(int j = 0; j < cardsLeft; j++) {
        Card sc = game->players[index]->getHand()->getCard(j);
        cout << "Card name: " << sc.getName() << endl;
        // Each eight = 50 points
        if(sc.getRankingValue() == 8) {
            //cout << "Adding 50 points to score" << endl;
            score += 50;
        }
        // Each K, Q, J or 10 = 10 points
        else if(sc.getRankingValue() == 10 || sc.getRankingValue() == 11 ||
                sc.getRankingValue() == 12 || sc.getRankingValue() == 13) {
            //cout << "Adding 10 points to score" << endl;
            score += 10;
        }
        // Each ace = 1 point
        else if(sc.getRankingValue() == 1){
            //cout << "Adding 1 point to score" << endl;
            score += 1;
        }
        //  Each other card is the pip value
        else {
            score += sc.getSuitRanking();
        }
    }
    return score;
}
void CrazyEightsPlayHandler::displayScores(){
    int playerScore = 0;
    for (unsigned int index = 0; index < game->players.size(); ++index) {
        playerScore = calculateScore(index);
    }
    cout << "Player " << game->getCurrentPlayer()->getName() << " has managed to score "
                     << playerScore << " points" << endl << endl;
}
void CrazyEightsPlayHandler::playRound() {
    string opts[] = {
        "Draw Card",
        "Surrender",
        "Help",
        "Exit Game"
    };
    gameMenu.clearScreen();
    Choices c = Choices(opts, 4);
    unsigned int intChoice = 0, index = 0;

    for (index = 0; index < game->players.size(); ++index) {
        /// Prompt the player what they would like to do.

        intChoice = game->players[index]->play(AppConstants::MESSAGE_SELECT_OPTION, c);
        nextCardToMatchIs();
        /// Handle the choice made by the player or bot.
        if (intChoice == 1) {
            string currentPlayer = game->getCurrentPlayer()->getName();

            // Checks to see if anyone won and skips a players turn if deck is empty
            checkDeckAndHand(index);

            // Display cards in hand and prompt player to choose one
            displayCardsInHand();
            unsigned int cardSelected = selectingCard(index);
            playedCard = game->getCurrentPlayer()->getHand()->removeCard(cardSelected);

            // Checks for valid matchCard replacement and changes playedCard if necessary
            checkPlayedCard(index, cardSelected);

            // Displays the card the player played and how many cards are left in their hand
            displayGameStatus();

            // Move on to the next player
            nextPlayer(index);
        }
        else if (intChoice == 2) {
            game->gameMenu.clearScreen();
            resultMessage = "SURRENDING!";
            displayScores();
            gameMenu.say(game->getCurrentPlayer()->getName() + " is " + resultMessage);
            exit (EXIT_SUCCESS);
        }
        else if(intChoice == 3){
            game->gameMenu.gameHelp(AppConstants::CRAZY_EIGHTS_TYPE);
            game->gameMenu.say(AppConstants::PRESS_ENTER);
            cin.get(); cin.get();
            game->gameMenu.clearScreen();
            playRound();
        }
        else if (intChoice == 4) {
            resultMessage = "\n\nGoodbye " + game->getCurrentPlayer()->getName();
            gameMenu.say(resultMessage);
            exit (EXIT_SUCCESS);
        }
    } // End loop
    playRound(); // Nobody won yet
}
void CrazyEightsPlayHandler::checkDeckAndHand(unsigned int index){
     int cardsLeftInPlayerHand = game->getCurrentPlayer()->getHand()->cardsRemaining();
     if(cardsLeftInPlayerHand == 0) {
        if(game->deck.cardsRemaining() == 0)
            nextPlayer(index); // Skip the current players turn
        else
            gameMenu.say("\n" + game->getCurrentPlayer()->getName()
                            + " is out of cards! WINNER!\n");
            displayScores();
            exit (EXIT_SUCCESS);
      }
}
void CrazyEightsPlayHandler::nextPlayer(unsigned int currentPlayerIndex) {
    Player* current = this->game->getCurrentPlayer();
    int currentIndex = -1;
    for (unsigned int i = 0; i < this->game->players.size(); i++) {
        if (this->game->players[i]->getName() == current->getName()) {
            currentIndex = i + 1;
            break;
        }
    }
    if (currentIndex >= this->game->players.size())
        this->game->setCurrentPlayer(this->game->players[0]);
    else
        this->game->setCurrentPlayer(this->game->players[currentIndex]);
}
void CrazyEightsPlayHandler::pickSuit(){
    unsigned int suitSelection = 0;
    gameMenu.clearScreen();

    cout << "\n*********************************************\n\n";
    cout << "1 - Clubs \n";
    cout << "2 - Spades \n";
    cout << "3 - Diamonds \n";
    cout << "4 - Hearts \n";
    cout << "\n*********************************************";

    cout << "\nThe pip of the card that was just played is " << playedCard.getPip() << endl;
    cout << "\nYou have an eights card! Select a suit for the next player to match: ";
    cin >> suitSelection;

    switch(suitSelection){
    case 1: playedCard = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_EIGHT); break;
    case 2: playedCard = StandardCard(AppConstants::STANDARD_SUIT_SPADES, AppConstants::STANDARD_PIP_EIGHT); break;
    case 3: playedCard = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_EIGHT); break;
    case 4: playedCard = StandardCard(AppConstants::STANDARD_SUIT_HEARTS, AppConstants::STANDARD_PIP_EIGHT); break;
    default: cout << "\nError, invalid number. Selecting clubs instead.";
    StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_EIGHT); break;
    }
    setMatchCard(playedCard);
}
unsigned int CrazyEightsPlayHandler::selectingCard(unsigned int i) {
    unsigned int flag = 1, cardsLeft = 0, cardSelection = 0;
    do{
        cardSelection = 0;
        cardsLeft = game->getCurrentPlayer()->getHand()->cardsRemaining();
        cout << endl << "Select a card to use: ";
        cin >> cardSelection;
        if(cardSelection < cardsLeft)
            flag = 0;
        else if(cardSelection >= cardsLeft)
            if(game->deck.cardsRemaining() == 0)
                nextPlayer(i);
            else
                drawCardFromDeck(); // add card to players deck
                cardsLeft = game->getCurrentPlayer()->getHand()->cardsRemaining();
                gameMenu.clearScreen(); // clear screen
                nextCardToMatchIs(); // display what the matchCard is
                displayCardsInHand(); // display the cards in hand
    }while(flag != 0);
    return cardSelection;
}
void CrazyEightsPlayHandler::displayCardsInHand() {
    int cardsLeft     = game->getCurrentPlayer()->getHand()->cardsRemaining();
    string playerName = game->getCurrentPlayer()->getName();
    string cardName   = game->getCurrentPlayer()->getHand()->to_stringOnce(0);

    cout <<"\nDisplaying " << cardsLeft -1 << " cards in " << playerName << "'s hand.\n";
    cout << "Enter a number (0-" << cardsLeft-1 << "), ";
    cout << "to draw a card from your hand ";
    cout << "\n*Any other number will draw a card from deck* \n\n";

    for(int j = 0; j < cardsLeft; j++){
        cardName = game->getCurrentPlayer()->getHand()->to_stringOnce(j);
        cout << "Card " << "(" << j << "): " << cardName << endl;
    }
}
void CrazyEightsPlayHandler::nextCardToMatchIs(){
    game->gameMenu.clearScreen();
    game->gameMenu.say("********************************************************************");
    game->gameMenu.say("\n " + game->getCurrentPlayer()->getName()
                       + " has to match the card: " + matchCard.getName() );
    game->gameMenu.say("\n********************************************************************");
}
void CrazyEightsPlayHandler::drawCardFromDeck(){
    Card sc = game->deck.drawCard(); // draw card from discard pile
    game->getCurrentPlayer()->getHand()->addCard(sc); // add card to players hand
}
void CrazyEightsPlayHandler::setMatchCard(Card match) {
    matchCard = match;
}
void CrazyEightsPlayHandler::checkPlayedCard(unsigned int i, unsigned int cardSelected){
    // An eight can be used to specify a particular suit but not a number
    if(playedCard.getRankingValue() == 8) {
        pickSuit(); // changes matchCard suit
        setMatchCard(playedCard);
    }
    // Match the card with either suit or rank
    else if(matchesSuitOrRank() == true || matchesSuitAndRank() == true) {
        gameMenu.say("\nPlayer has matched the card! \n");
        matchCard = StandardCard(playedCard.getSuit(), playedCard.getPip());
        setMatchCard(matchCard);
        nextCardToMatchIs();
    }
    else {
        badMatch(i, cardSelected);
    }
}
void CrazyEightsPlayHandler::badMatch(unsigned int i, unsigned int cardSelected){
        // Give play their card back
        game->getCurrentPlayer()->getHand()->addCard(playedCard);
        // Show the matchCard again
        nextCardToMatchIs();

        gameMenu.say("Error, invalid card selected. Select another one");

        // display cards in hand
        displayCardsInHand();

        // Get the location/index of the new playedCard
        int newCardSelected = selectingCard(i);
        cout << "Current playedCard is " << playedCard.getName() << endl;

        // Check if the deck has cards in it
        if(game->deck.cardsRemaining() == 0){
            cout << "Moving to the next player, there are no cards left in the deck \n";
            nextPlayer(i);
        }
        // Draw the playedCard and display what it is
        else if(game->deck.cardsRemaining() != 0) {
            playedCard = game->getCurrentPlayer()->getHand()->removeCard(newCardSelected);
            cout << "New playedCard is " << playedCard.getName() << endl;

        }
        if(matchesSuitOrRank() == true || matchesSuitAndRank() == true) {
            cout << "Card has been matched!" << endl;
        }
        else{
            cout << "Another bad match!" << endl;
            badMatch(i, cardSelected);
        }
}
void CrazyEightsPlayHandler::displayGameStatus(){
    game->gameMenu.say(game->getCurrentPlayer()->getName() + " drew a " + playedCard.getName());
    game->gameMenu.say(game->getCurrentPlayer()->getName() + " has " +
                to_string(game->getCurrentPlayer()->getHand()->cardsRemaining()) + " cards remaining\n");
}
bool CrazyEightsPlayHandler::matchesSuitOrRank(){
    if(matchCard.getSuitRanking() == playedCard.getSuitRanking()
            || matchCard.getRankingValue() == playedCard.getRankingValue()
            || matchCard.getSuitRanking() == playedCard.getSuitRanking())
    {
        return true;
    }
    return false;
}
bool CrazyEightsPlayHandler::matchesSuitAndRank(){
    if(matchCard.getSuitRanking() == playedCard.getSuitRanking()
            && matchCard.getRankingValue() == playedCard.getRankingValue()
            && matchCard.getSuitRanking() == playedCard.getSuitRanking())
    {
        return true;
    }
    return false;
}
Card* CrazyEightsPlayHandler::getMatchCard(){
    return &matchCard;
}
