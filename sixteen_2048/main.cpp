/*
  Justin Bombay
  -- main.cpp --
  -- Coded in C++ --
  
*/

#include <cctype>
#include <cstdlib>
#include <iostream>
#include "sixteen.h"

using namespace std;

int main()
{
  // Variables
  char decision;
  sixteen game;
  int gameValue;

  // Outputs current gameboard
  game.output();

  // Prompts user to enter a direction to move
  do{
      cout << endl;
      cout << "Which direction would you like to move? (U, D, L , R): ";
      cin >> decision;
      decision = toupper(decision); // Converts character to an uppercase

      // Fail check for user input
      while(cin.fail() || decision != 'U' && decision != 'D' && decision != 'L' && decision != 'R')
      {
        cout << endl;
        cout << "Invalid move!" << endl;
        cin.clear();
        cin.ignore(100,'\n');

        cout << endl;
        cout << "Which direction would you like to move? (U, D, L , R): ";
        cin >> decision;
        decision = toupper(decision);
      } // end while loop

      // If the user's input is 'L', call the moveLeft function
      if (decision == 'L'){
        game.moveLeft();
        game.output();
      }

      // If the user's input is 'R', call the moveRight function
      else if (decision == 'R'){
        game.moveRight();
        game.output();
      }

      // If the user's input is 'U', call the moveUp function
      else if (decision == 'U'){
        game.moveUp();
        game.output();
      }

      // If the user's input is 'D', call the moveDown function
      else if (decision == 'D'){
        game.moveDown();
        game.output();
      }

      // gameValue is assigned to the number that the over function returns
      gameValue = game.over();

      // If a 1 is returned, you've won the game
      if (gameValue == 1){
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Congrats!! You won!!!" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
        break;
      }

      // If a -1 is returned, you've lost the game
      else if (gameValue == -1){
        cout << "Sorry! You lost! :(" << endl;
        break;
      }
    } while(decision == 'U' || 'D' || 'L' || 'R' && gameValue == 0 );
    // end do while loop,

  return 0;
}
