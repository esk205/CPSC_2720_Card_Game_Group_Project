#ifndef APPL_CONST_H
#define APPL_CONST_H

#include <iostream>

class AppConstants
{
public:
    static const std::string WELCOME_MESSAGE;
    static const std::string TEAM_NAME;
    static const std::string TEAM_MEMBERS;
    static const std::string VERSION;
    static const std::string BLACK_JACK;
    static const std::string CRAZY_EIGHTS;
    static const std::string GO_FISH;
    static const std::string ROCK_PAPER_SCISSORS;
    static const std::string PHASE_TEN;
    static const std::string WAR;
    static const std::string STANDARD_SUIT_SPADES;
    static const std::string STANDARD_SUIT_CLUBS;
    static const std::string STANDARD_SUIT_DIAMONDS;
    static const std::string STANDARD_SUIT_HEARTS;
    static const int STANDARD_SUIT_CLUBS_RANK;
    static const int STANDARD_SUIT_SPADES_RANK;
    static const int STANDARD_SUIT_DIAMONDS_RANK;
    static const int STANDARD_SUIT_HEARTS_RANK;
    static const int STANDARD_PIP_ACE_VALUE;
    static const int STANDARD_PIP_TWO_VALUE;
    static const int STANDARD_PIP_THREE_VALUE;
    static const int STANDARD_PIP_FOUR_VALUE;
    static const int STANDARD_PIP_FIVE_VALUE;
    static const int STANDARD_PIP_SIX_VALUE;
    static const int STANDARD_PIP_SEVEN_VALUE;
    static const int STANDARD_PIP_EIGHT_VALUE;
    static const int STANDARD_PIP_NINE_VALUE;
    static const int STANDARD_PIP_TEN_VALUE;
    static const int STANDARD_PIP_JACK_VALUE;
    static const int STANDARD_PIP_QUEEN_VALUE;
    static const int STANDARD_PIP_KING_VALUE;
    static const int STANDARD_PIP_JOKER_VALUE;
    static const int PHASETEN_PIP_ELEVEN_VALUE;
    static const int PHASETEN_PIP_TWELVE_VALUE;
    static const int PHASETEN_PIP_WILD_VALUE;
    static const int PHASETEN_PIP_SKIP_VALUE;
    static const std::string STANDARD_PIP_ACE;
    static const std::string STANDARD_PIP_TWO;
    static const std::string STANDARD_PIP_THREE;
    static const std::string STANDARD_PIP_FOUR;
    static const std::string STANDARD_PIP_FIVE;
    static const std::string STANDARD_PIP_SIX;
    static const std::string STANDARD_PIP_SEVEN;
    static const std::string STANDARD_PIP_EIGHT;
    static const std::string STANDARD_PIP_NINE;
    static const std::string STANDARD_PIP_TEN;
    static const std::string STANDARD_PIP_JACK;
    static const std::string STANDARD_PIP_QUEEN;
    static const std::string STANDARD_PIP_KING;
    static const std::string STANDARD_PIP_JOKER;
    static const std::string STANDARD_PIP_DECK[14];
    static const std::string STANDARD_SUIT_DECK[4];
    static const std::string PHASETEN_SUIT_BLUE;
    static const std::string PHASETEN_SUIT_GREEN;
    static const std::string PHASETEN_SUIT_RED;
    static const std::string PHASETEN_SUIT_YELLOW;
    static const std::string PHASETEN_PIP_ONE;
    static const std::string PHASETEN_PIP_ELEVEN;
    static const std::string PHASETEN_PIP_TWELVE;
    static const std::string PHASETEN_PIP_WILD;
    static const std::string PHASETEN_SKIP;
    static const std::string RPS_SUIT_ROCK;
    static const std::string RPS_SUIT_PAPER;
    static const std::string RPS_SUIT_SCISSORS;
    static const std::string RPS_PIP_ROCK;
    static const std::string RPS_PIP_PAPER;
    static const std::string RPS_PIP_SCISSORS;
    static const std::string RPS_SUIT_DECK[3];
    static const std::string RPS_PIP_DECK[18];
    static const std::string DUMB_BOT_PLAYER;
    static const std::string RANDOM_BOT_PLAYER;
    static const std::string SMART_BOT_PLAYER;
    static const std::string HUMAN;
    static const std::string MESSAGE_INVALID_SELECTION;
    static const std::string MESSAGE_SELECT_OPTION;
    static const std::string MESSAGE_SELECT_GAME;
    static const std::string MESSAGE_ENTER_NAME;
    static const std::string MESSAGE_SELECT_PLAYER;
    static const std::string PROMPT;
    static const std::string UNKNOWN_PLAYER;
    static const std::string CHOOSE_BOT_PLAYER;
    static const std::string PROMPT_GAME_CHOICE;
    static const std::string RUN_TESTS;
    static const std::string QUIT;
    static const std::string PAUSE;
    static const int GO_FISH_MAX_PLAYERS;
    static const int CRAZY_EIGHTS_MAX_PLAYERS;
    static const int WAR_MAX_PLAYERS;
    static const int RPS_MAX_PLAYERS;
    static const std::string WELCOME_WAR;
    static const std::string MESSAGE_WAR;
    static const std::string MESSAGE_VICTORY;
    static const std::string WELCOME_RPS;
    static const std::string MESSAGE_DRAW;
    static const std::string WELCOME_GO_FISH;
    static const int GO_FISH_MAX_PILES;
    static const std::string WELCOME_BJ;
    static const std::string GAME_OVER;
    static const std::string PRESS_ENTER;
    static const int GO_FISH_TYPE;
    static const int BLACKJACK_TYPE;
    static const int CRAZY_EIGHTS_TYPE;
    static const int RPS_TYPE;
    static const int WAR_TYPE;

    static const std::string HELP;

    static const std::string HELP_OBJECTIVE;
    static const std::string GO_FISH_OBJECTIVE;
    static const std::string BLACKJACK_OBJECTIVE;
    static const std::string CRAZY_EIGHTS_OBJECTIVE;
    static const std::string RPS_OBJECTIVE;
    static const std::string WAR_OBJECTIVE;

    static const std::string HELP_CARDS_DEALT;
    static const std::string GO_FISH_CARDS_DEALT;
    static const std::string BLACKJACK_CARDS_DEALT;
    static const std::string CRAZY_EIGHTS_CARDS_DEALT;
    static const std::string RPS_CARDS_DEALT;
    static const std::string WAR_CARDS_DEALT;

    static const std::string HELP_HOW_TO;
    static const std::string GO_FISH_HELP;
    static const std::string BLACKJACK_HELP;
    static const std::string CRAZY_EIGHTS_HELP;
    static const std::string RPS_HELP;
    static const std::string WAR_HELP;
    static const std::string BASIC_HELP;

};

#endif // APPL_CONST_H
