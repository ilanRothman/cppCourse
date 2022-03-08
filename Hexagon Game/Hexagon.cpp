//
// Created by iroth on 11/25/2021.
//

#include "Hexagon.h"
#include <iostream>
#include <sstream>

using namespace std;

//prints the current board game
void Hexagon::printBoard() {
    for(int i = 0; i< 11; i++){
        cout <<string(i,' ');
        for(int j = 0 ; j<11 ; j++){
            if(j == 10){
                cout  << board[i][j].getState()<<endl;
            }
            else{
                cout  << board[i][j].getState() <<" ";}}}
}

bool Hexagon::makeMove() {
    string input;
    char j, state, whoturn;
    int i = 0;
    if(Turn(moveCount % 2) == Blue){
        whoturn = 'B';
    }
    else{
        whoturn = 'R';
    }
    cout << whoturn << ":" <<endl;
    cin >> input;
    if(input == "QUIT"){
        cout <<whoturn <<": "<<"QUIT"<<endl;
        setGameState(QUIT);
        return false;

    }
    j = input[0];
    input.erase(0,1);
    stringstream ss(input);
    ss >> i;
    if(ss.rdbuf()->in_avail() !=0){ //incorrect input.
        cerr << "Invalid move; the game awaits a valid move.\n";
        return false;
    }
    if(i >= 1 && i < 12 && j >= 'A' && j <= 'K') {
        if (this->board[i - 1][j - 'A'].getState() == "O") {
            if (Turn(moveCount % 2) == Blue) { state = 'B'; }
            else { state = 'R'; }
            this->board[i - 1][j - 'A'].setState(state);
            moveCount++;
            return true;
        } else { //space already taken.
            cerr << "Invalid move; the game awaits a valid move.\n";
            return false;}}
    else{//wrong indexes.
        cerr << "Invalid move; the game awaits a valid move.\n";
        return false;}
}
//used for checking the state of the game. B win R win or continue game.
void Hexagon::stateOfGame() {
    string turn;
    if (Turn(moveCount % 2) == Blue) { // moveCount already incremented so opposite turn.
        turn = 'R';
    }
    else { turn = 'B'; }
    if(getGameState() == QUIT){
        printBoard();
        cout << turn << " wins the game.\n";
        return;
    }
    if( turn == "R"){ //checking for a red win.
        for(int j = 0; j<11;j++){
            if(board[0][j].getState() == turn){
                checkWin(turn,0,j, true,false); // only check if a place is on the first line.
                if(gameState != Unfinished){
                    break;}
                setUnvisited();}}}
    else{ //checking for blue win.
        for(int i = 0; i<11;i++){
            if(board[i][0].getState() == turn){
                checkWin(turn,i,0, true,false); // only check if a place is on the first line.
                if(gameState != Unfinished){
                    break;}
                    setUnvisited();}}}
    //if not unfinished means game is over.
    if(gameState != Unfinished){
        printBoard();
        cout << turn <<" wins the game.\n";
        return;}
}
//algorithm for checking if turn has won.
void Hexagon::checkWin(const string& turn,int i,int j,bool start,bool end) {
    if (board[i][j].isVisited() || turn != board[i][j].getState()){ //base case check if opponents place or visited already
        return;
    }
    if(!end){
        if(turn == "B"){
            if( j == 10){end=true;}}
        else{
            if( i ==10){end=true;}}}
    board[i][j].setVisited(true);

    if(end){
        if(turn == "B"){setGameState(B_win);}
        else{setGameState(R_win);}
        return;
    }
    //checking all neighbours.
    if(i>0){
        if(board[i-1][j].getState()== turn){
            checkWin(turn,i-1,j,start,end);}
    }
    if (i > 0 && j < 10) {
        if(board[i-1][j+1].getState()== turn) {
            checkWin(turn, i - 1, j + 1, start, end);}
    }
    if (j > 0) {
        if(board[i][j-1].getState()== turn) {
            checkWin(turn, i, j - 1, start, end);}
    }
    if(j < 10) {
        if (board[i][j + 1].getState() == turn) {
            checkWin(turn, i, j + 1, start, end);}
    }
    if(i<10) {
        if (board[i + 1][j].getState() == turn) {
            checkWin(turn, i + 1, j, start, end);}
    }
    if(i<10 && j>0) {
        if (board[i + 1][j - 1].getState() == turn) {
            checkWin(turn, i + 1, j - 1, start, end);}
    }
}


void Hexagon::startGame() {
    while(gameState == Unfinished){
        printBoard();
        makeMove();
        stateOfGame();}
}

void Hexagon::setUnvisited() {
    for(int i = 0; i<11;i++){
        for(int j = 0 ; j<11; j++){
            board[i][j].setVisited(false);}}
}

