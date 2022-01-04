/*
  Justin Bombay
  sixteen2.cpp
*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "sixteen.h"

using namespace std;

  /* ----------------------------------------------
    DEFAULT CONSTRUCTOR
    INPUT: No input
    OUTPUT: No output because it performs a task instead
  ------------------------------------------------*/
  sixteen::sixteen ()
  {
    for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
        board[i][j] = 0;
      }
    }

    //board[0][0] = 2; //og
    //board[2][0] = 2; //og

    board[0][2] = 2; // move left
    board[2][2] = 2; // move left
    //board[0][0] = 4;
  //  board[0][1] = 4;
  //  board[0][2] = 2;
  //  board[2][2] = 2;
  }
  /* ----------------------------------------------
    FUNCTION NAME: moveLeft
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::moveLeft ()
  {
    // This nested for loop slides all values over to the left
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = 0; j < SIZE; j++) { // This for loop is for the columns
        for (int k = j; k < SIZE; k++) { // This for loop checks the values in the array
          if(board[i][k] != 0){
            board[i][j] = board[i][k];
            if (k != j)
              board[i][k] = 0;
            break;
          } // end if statement
        } // end for loop 'k'
      } // end for loop 'j'
    } // end for loop 'i'

    // This nested for loop merges pair values together
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = 0; j < SIZE; j++) { // This for loop is for the columns
        // if statement checks if the two values in adjacent arrays are equal values
        if(board[i][j] == board[i][j + 1]){
          board[i][j] *= 2;
          board[i][j + 1] = 0;
          for (int k = j+ 1; k < SIZE - 1; k++ ){
            board[i][k] == board[i][k + 1];
          } // end for loop 'k'
          board[i][SIZE - 1] = 0;
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional Variables
    int row, column;

    do {
        row = rand() % SIZE;
        column = rand() % SIZE;
    } while (board[row][column] != 0);

    board[row][column] = 2;
  } // end function

  /* ----------------------------------------------
    FUNCTION NAME: moveRight
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::moveRight ()
  {

    // This nested for loop slides all values over to the right
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = SIZE - 1; j >= 0; j--) { // This for loop is for the columns
        for (int k = j - 1; k >= 0; k--) { // This for loop checks the values in the array
          if(board[i][k] != 0){
            board[i][j] = board[i][k];
            if (k != j)
              board[i][k] = 0;
            break;
          } // end if statement
        } // end for loop 'k'
      } // end for loop 'j'
    } // end for loop 'i'


    // This nested for loop merges pair values together
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = SIZE - 1; j >= 0; j--) { // This for loop is for the columns
        if(board[i][j] == board[i][j - 1]){ // Checks if the
          board[i][j] *= 2;
          board[i][j - 1] = 0;
          for (int k = j - 1; k >= 0; k--){
            board[i][k] == board[i][k - 1];
          } // end for loop 'k'
          board[i][0] = 0;
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional variables
    int row, column;

    do {
        row = rand() % SIZE;
        column = rand() % SIZE;
    } while (board[row][column] != 0);

    board[row][column] = 2;
  }

  /* ----------------------------------------------
    FUNCTION NAME: moveUp
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::moveUp ()
  {

  }

  /* ----------------------------------------------
    FUNCTION NAME: moveDown
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::moveDown ()
  {

  }

  /* ----------------------------------------------
    FUNCTION NAME: over
    INPUT: No input
    OUTPUT: Returns an integer as a const
  ------------------------------------------------*/
  int sixteen::over() const
  {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {

      }
    }
  } // end function

  /* ----------------------------------------------
    FUNCTION NAME: output
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::output() const
  {
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = 0; j < SIZE; j++) { // This for loop is for the columns
          // if the value in the index does not equal 0
          if (board[i][j] != 0){
            cout << setw(3) << right << board[i][j];
          }
          // if the value in the index has no value output an underscore
          else{
            cout << setw(3) << right << "_";
          }
      } // end for loop 'j'
      cout << endl;
    } // end for loop 'i'
  } // end function
