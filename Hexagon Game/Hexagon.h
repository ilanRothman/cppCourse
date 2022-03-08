//
// Created by iroth on 11/25/2021.
//

#ifndef HEX_HEXAGON_H
#define HEX_HEXAGON_H

#include "Place.h"

class Hexagon{
    //Big three implementations:
    //Destructor - no dynamically allocations so no need to create a distructor.
    // Copy Constructer - had no need for one so relied on the default one.
    // Operator = - again, had no need for one.
    private:
    Place board[11][11];
    int moveCount; // used for checking who's turn
    enum GameState {B_win,R_win,Unfinished, QUIT};
    enum Turn {Blue,Red};
    GameState gameState;

    public:
    Hexagon(){gameState = Unfinished,moveCount = 0;};
    void printBoard(); // printing the board.
    bool makeMove(); // places the letter on the board if legal move.
    GameState getGameState(){return gameState;}
    void setGameState(GameState newGameState){
        gameState = newGameState;
    }
    void stateOfGame(); //checks if game over or not.
    void startGame(); // runs the game.
    void checkWin(const string& turn,int i,int j,bool start,bool end); //checking if game is won.
    void setUnvisited();//sets all places to unvisited.
};

#endif //HEX_HEXAGON_H
