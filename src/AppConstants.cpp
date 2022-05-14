#include "AppConstants.h"

const std::string AppConstants::STANDARD_SUIT_CLUBS = "clubs";
const std::string AppConstants::STANDARD_SUIT_SPADES = "spades";
const std::string AppConstants::STANDARD_SUIT_DIAMONDS = "diamonds";
const std::string AppConstants::STANDARD_SUIT_HEARTS = "hearts";

/// Same order as the PhaseTen Suit Ranks
const int AppConstants::STANDARD_SUIT_CLUBS_RANK = 1;
const int AppConstants::STANDARD_SUIT_SPADES_RANK = 2;
const int AppConstants::STANDARD_SUIT_DIAMONDS_RANK = 3;
const int AppConstants::STANDARD_SUIT_HEARTS_RANK = 4;

const int AppConstants::STANDARD_PIP_ACE_VALUE = 14;
const int AppConstants::STANDARD_PIP_TWO_VALUE = 2;
const int AppConstants::STANDARD_PIP_THREE_VALUE = 3;
const int AppConstants::STANDARD_PIP_FOUR_VALUE = 4;
const int AppConstants::STANDARD_PIP_FIVE_VALUE = 5;
const int AppConstants::STANDARD_PIP_SIX_VALUE = 6;
const int AppConstants::STANDARD_PIP_SEVEN_VALUE = 7;
const int AppConstants::STANDARD_PIP_EIGHT_VALUE = 8;
const int AppConstants::STANDARD_PIP_NINE_VALUE = 9;
const int AppConstants::STANDARD_PIP_TEN_VALUE = 10;
const int AppConstants::STANDARD_PIP_JACK_VALUE = 10;
const int AppConstants::STANDARD_PIP_QUEEN_VALUE = 10;
const int AppConstants::STANDARD_PIP_KING_VALUE = 10;
const int AppConstants::STANDARD_PIP_JOKER_VALUE = 10;
const int AppConstants::PHASETEN_PIP_ELEVEN_VALUE = 11;
const int AppConstants::PHASETEN_PIP_TWELVE_VALUE = 12;
const int AppConstants::PHASETEN_PIP_WILD_VALUE = 13;
const int AppConstants::PHASETEN_PIP_SKIP_VALUE = 0;
const std::string AppConstants::STANDARD_PIP_ACE = "ace";
const std::string AppConstants::STANDARD_PIP_TWO = "two";
const std::string AppConstants::STANDARD_PIP_THREE = "three";
const std::string AppConstants::STANDARD_PIP_FOUR = "four";
const std::string AppConstants::STANDARD_PIP_FIVE = "five";
const std::string AppConstants::STANDARD_PIP_SIX = "six";
const std::string AppConstants::STANDARD_PIP_SEVEN = "seven";
const std::string AppConstants::STANDARD_PIP_EIGHT = "eight";
const std::string AppConstants::STANDARD_PIP_NINE = "nine";
const std::string AppConstants::STANDARD_PIP_TEN = "ten";
const std::string AppConstants::STANDARD_PIP_JACK = "jack";
const std::string AppConstants::STANDARD_PIP_QUEEN = "queen";
const std::string AppConstants::STANDARD_PIP_KING = "king";
const std::string AppConstants::STANDARD_PIP_JOKER = "joker";

/// Collection of decks so it doesn't need to be remade. Can be used decks in loops easily.
const std::string AppConstants::STANDARD_PIP_DECK[] =
{
    AppConstants::STANDARD_PIP_ACE,
    AppConstants::STANDARD_PIP_TWO,
    AppConstants::STANDARD_PIP_THREE,
    AppConstants::STANDARD_PIP_FOUR,
    AppConstants::STANDARD_PIP_FIVE,
    AppConstants::STANDARD_PIP_SIX,
    AppConstants::STANDARD_PIP_SEVEN,
    AppConstants::STANDARD_PIP_EIGHT,
    AppConstants::STANDARD_PIP_NINE,
    AppConstants::STANDARD_PIP_TEN,
    AppConstants::STANDARD_PIP_JACK,
    AppConstants::STANDARD_PIP_QUEEN,
    AppConstants::STANDARD_PIP_KING,
    AppConstants::STANDARD_PIP_JOKER
};

const std::string AppConstants::STANDARD_SUIT_DECK[] =
{
    AppConstants::STANDARD_SUIT_CLUBS,
    AppConstants::STANDARD_SUIT_SPADES,
    AppConstants::STANDARD_SUIT_DIAMONDS,
    AppConstants::STANDARD_SUIT_HEARTS
};

/** Phase Ten Constants **/
const std::string AppConstants::PHASETEN_SUIT_BLUE = "blue";
const std::string AppConstants::PHASETEN_SUIT_GREEN = "green";
const std::string AppConstants::PHASETEN_SUIT_RED = "red";
const std::string AppConstants::PHASETEN_SUIT_YELLOW = "yellow";

const std::string AppConstants::PHASETEN_PIP_ONE = "one";
const std::string AppConstants::PHASETEN_PIP_ELEVEN = "eleven";
const std::string AppConstants::PHASETEN_PIP_TWELVE = "twelve";
const std::string AppConstants::PHASETEN_PIP_WILD = "wild";

const std::string AppConstants::PHASETEN_SKIP = "skip";

/** Rock Paper Scissors Constants**/
const std::string AppConstants::RPS_SUIT_ROCK = "rock";
const std::string AppConstants::RPS_SUIT_PAPER = "paper";
const std::string AppConstants::RPS_SUIT_SCISSORS = "scissors";

const std::string AppConstants::RPS_PIP_ROCK = "1";
const std::string AppConstants::RPS_PIP_PAPER = "2";
const std::string AppConstants::RPS_PIP_SCISSORS = "3";

const std::string AppConstants::RPS_SUIT_DECK[] =
{
    AppConstants::RPS_SUIT_ROCK,
    AppConstants::RPS_SUIT_PAPER,
    AppConstants::RPS_SUIT_SCISSORS
};

const std::string AppConstants::RPS_PIP_DECK[] =
{
    AppConstants::RPS_PIP_ROCK,
    AppConstants::RPS_PIP_PAPER,
    AppConstants::RPS_PIP_SCISSORS
};

/** Bot Types **/
const std::string AppConstants::DUMB_BOT_PLAYER = "Dumb Bot Player";
const std::string AppConstants::RANDOM_BOT_PLAYER = "Random Bot Player";
const std::string AppConstants::SMART_BOT_PLAYER = "Smart Bot Player";
const std::string AppConstants::HUMAN = "Human";

const std::string AppConstants::WELCOME_MESSAGE = "*** CARD GAMES ***";
const std::string AppConstants::TEAM_NAME = "*** TEAM FILTHY CASUAL ***";
const std::string AppConstants::TEAM_MEMBERS = "Brad Lindsay\nBrett Regnier\nMichael Wynnychuk\nDaylend De Grasse";
const std::string AppConstants::VERSION = "Version: 0.0.1";
const std::string AppConstants::MESSAGE_INVALID_SELECTION = "That is an invalid selection.";
const std::string AppConstants::MESSAGE_SELECT_GAME = "Please select a game.";
const std::string AppConstants::MESSAGE_SELECT_OPTION = "Please select an option.";
const std::string AppConstants::MESSAGE_ENTER_NAME = "Enter your name.";
const std::string AppConstants::MESSAGE_SELECT_PLAYER = "Please select a player.";
const std::string AppConstants::PROMPT = "Selection: ";
const std::string AppConstants::UNKNOWN_PLAYER = "Unknown Player";
const std::string AppConstants::CHOOSE_BOT_PLAYER = "Choose your opponent";
const std::string AppConstants::PROMPT_GAME_CHOICE = "What would you like to do, ";
const std::string AppConstants::RUN_TESTS = "Run Tests";
const std::string AppConstants::QUIT = "Quit";
const std::string AppConstants::PAUSE = "Pause";

const std::string AppConstants::BLACK_JACK = "Black Jack";
const std::string AppConstants::CRAZY_EIGHTS = "Crazy Eights";
const std::string AppConstants::GO_FISH = "Go Fish";
const std::string AppConstants::ROCK_PAPER_SCISSORS = "Rock Paper Scissors";
const std::string AppConstants::PHASE_TEN = "Phase Ten"; // Slowly being removed delete later.
const std::string AppConstants::WAR = "War";

const int AppConstants::GO_FISH_MAX_PLAYERS = 5;
const int AppConstants::CRAZY_EIGHTS_MAX_PLAYERS = 5;
const int AppConstants::WAR_MAX_PLAYERS = 2;
const int AppConstants::RPS_MAX_PLAYERS = 2;

/** War Messages **/
const std::string AppConstants::WELCOME_WAR = "Welcome to War!";
const std::string AppConstants::MESSAGE_WAR = "WAR!!";
const std::string AppConstants::MESSAGE_VICTORY = "won";

/** Rock Paper Scissors Messages **/
const std::string AppConstants::WELCOME_RPS = "Welcome To Rock Paper Scissors";
const std::string AppConstants::MESSAGE_DRAW = "Draw!";

/** Go Fish Messages **/
const std::string AppConstants::WELCOME_GO_FISH = "Welcome to Go Fish";
const int AppConstants::GO_FISH_MAX_PILES = 13;

/** Blackjack Messages */
const std::string AppConstants::WELCOME_BJ = "Welcome to Blackjack";

const std::string AppConstants::GAME_OVER = "Game Over";
const std::string AppConstants::PRESS_ENTER = "Press Enter to continue";

/** Game Type Value **/
const int AppConstants::GO_FISH_TYPE = 1;
const int AppConstants::BLACKJACK_TYPE = 2;
const int AppConstants::CRAZY_EIGHTS_TYPE = 3;
const int AppConstants::RPS_TYPE = 4;
const int AppConstants::WAR_TYPE = 5;

/** Help Message **/
const std::string AppConstants::HELP = "Help";

const std::string AppConstants::HELP_OBJECTIVE = "Objective:";
const std::string AppConstants::GO_FISH_OBJECTIVE = "Get the most piles.";
const std::string AppConstants::BLACKJACK_OBJECTIVE = "Get closer to 21 than the dealer, without going over";
const std::string AppConstants::CRAZY_EIGHTS_OBJECTIVE = "Use up all the cards in your hand.";
const std::string AppConstants::RPS_OBJECTIVE = "Win the most Cards.";
const std::string AppConstants::WAR_OBJECTIVE = "Win all of the Cards";

const std::string AppConstants::HELP_CARDS_DEALT = "How cards are dealt:";
const std::string AppConstants::GO_FISH_CARDS_DEALT = "The deck is dealt between all players in the game. If there are less that 3 players, each player gets 7 cards, otherwise each player gets 5 cards.";
const std::string AppConstants::BLACKJACK_CARDS_DEALT = "2 cards are dealt to each player, including the dealer. You can only see your hand";
const std::string AppConstants::CRAZY_EIGHTS_CARDS_DEALT = "Each player gets 5 cards that they draw from the deck.";
const std::string AppConstants::RPS_CARDS_DEALT = "3 Cards are dealt to both players.";
const std::string AppConstants::WAR_CARDS_DEALT = "The deck is dealt between both players. Each player cannot see their hand.";

const std::string AppConstants::HELP_HOW_TO = "How to play:";
const std::string AppConstants::GO_FISH_HELP = "Each player will be dealt their cards. The starting player will ask an opponent for a card by pip. If the opponent has that pip, they must turn over all cards of that pip. Once 4 cards of a specific pip are created, the cards are removed from the player’s hand and added to their ‘piles’. Once all the piles are accounted for, the player with the most piles is declared the winner.";
const std::string AppConstants::BLACKJACK_HELP = "Each card is worth the number printed on said card, except for face cards and ace. Ace is worth 1 or 11 points (the better of the two), and face cards are worth 10.\n\nYou start with two cards. Sum up the worth of your cards, and then decide whether or not you want the dealer to give you another card (hit).\n\nIf you decide to hit, the dealer will give you a new card and you will calculate the new sum of all cards. If that number is greater than 21, you lose (bust). If that number is less than 21, you may choose to hit again. If you do not wish to hit, select stay. Your turn is now over.\n\nOnce your turn is over, wait until the dealer takes his turn.\n\nIf your sum of cards is closer to 21 than the dealer’s cards, you win. If the dealer is closer to 21, you lose. If you both end up at the same value, it’s a tie game. This includes if you both end up at 21.";
const std::string AppConstants::CRAZY_EIGHTS_HELP = "Each player is dealt 5 cards. The player must match the displayed card \nwith one of the cards in their hand.";
const std::string AppConstants::RPS_HELP = "Both players will pick a card from their hand, then they will be compared in a combat triangle. After choosing a card from their hand each player will draw a card from the Game deck.\n\nEach card has an advantage over the other, such as Rock crushes Scissors, Paper covers Rock, and Scissors cuts Paper.\n\nIf both cards that are drawn are worth the same value. Ex. Rock and Rock then it's a Draw and each player must draw cards until someone wins, similar to war.\n\nAfter each round the player who won the exchange (including a draw) receives all of the Cards and places them into their discard pile.\n\nOnce the deck is out of cards, and both players run out of cards then the game is over and the amount of cards in each Player’s discard pile.";
const std::string AppConstants::WAR_HELP = "Each player will draw a card from their deck then the cards will be compared against each other based on their values.\n\nEach card is worth a different value, be that each numbered card is worth that value, and then the value after the 10 Card goes Jack, Queen, King, and Ace being the highest valued card.\n\nIf both cards that are drawn are worth the same value. Ex. Queen of Spades vs Queen of Hearts then WAR is declared and players must play Cards until someone wins the exchange.\n\nAfter each round the player who won the exchange (including War) receives all of the Cards and places them into their discard pile.\n\nOnce the player runs out of cards in their hand they pick up their discard pile and begin to play using those cards.\n\nThis repeats until one player receives the entire deck.";
const std::string AppConstants::BASIC_HELP = "This menu is easy, just select a number listed and you can start playing a game!";
