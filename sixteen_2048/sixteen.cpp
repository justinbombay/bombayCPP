/*
  Justin Bombay
  CS 202 - 1003
  Dr. Vasko
  Assignment 4
  sixteen.cpp
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
      } // end for loop 'j'
    } // end for loop 'i'
    // Sets certain positions to 2 as a starter value
    board[0][0] = 2;
    board[2][0] = 2;
  } // end function

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
          // if statement checks if position in the array holds a value
          if(board[i][k] != 0){
            // Sets the position that was moved equal to the previous position
            board[i][j] = board[i][k];
            if (k != j) //if the values are not equal to one another
              // sets position that was moved equal to 0
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
          board[i][j] *= 2; // Doubles the value at the position
          board[i][j + 1] = 0; // Sets previous position to 0 once it is moved
          for (int k = j+ 1; k < SIZE - 1; k++){ // This for loop checks for values in the array
            board[i][k] = board[i][k + 1]; // Sets the position that was moved equal to the previous position
          } // end for loop 'k'
          // Sets the right most position to 0
          board[i][SIZE - 1] = 0;
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional Variables
    int row, column;

    // do while loop generates another 2 at a random position in the array
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
        for (int k = j; k >= 0; k--) { // This for loop checks the values in the array
          // if position is not equal to 0
          if(board[i][k] != 0){
            // Sets new position to previous position
            board[i][j] = board[i][k];
            if (k != j)
              // sets previously moved position to 0
              board[i][k] = 0;
            break;
          } // end if statement
        } // end for loop 'k'
      } // end for loop 'j'
    } // end for loop 'i'


    // This nested for loop merges pair values together
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = SIZE - 1; j > 0; j--) { // This for loop is for the columns
        if(board[i][j] == board[i][j - 1]){ // Checks if two positions in the array are the same value
          board[i][j] *= 2; // doubles the value at the position
          for (int k = j - 1; k >= 0; k--){ // This for loop checks the values in the array
            board[i][k] = board[i][k - 1]; //  Sets new position to previous position
          } // end for loop 'k'
          board[i][0] = 0; // Sets left most position equal to 0
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional variables
    int row, column;

    // do while loop generates another 2 at a random position in the array
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
    // This nested for loop slides all values up
    for (int j = 0; j < SIZE; j++) { // This for loop is for the columns
      for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      // have not changed any values below this
        for (int k = j; k < SIZE; k++) { // This for loop checks the values in the array
          if(board[k][i] != 0){ // If the position is not equal to 0
            //  Sets new position to previous position
            board[j][i] = board[k][i];
            if (k != j)
              board[k][i] = 0; // Sets bottom position to 0
            break;
          } // end if statement
        } // end for loop 'k'
      } // end for loop 'i'
    } // end for loop 'j'

    // This nested for loop merges pair values together
    for (int j = 0; j < SIZE; j++) { // This for loop is for the columns
      for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
        // if statement checks if the two values in adjacent arrays are equal values
        if(board[j][i] == board[j + 1][i]){
          board[j][i] *= 2; // Doubles the value
          board[j + 1][i] = 0; // Sets previous position to 0
          for (int k = j + 1; k < SIZE - 1; k++){ // This for loop checks for values in the array
            board[k][i] = board[k + 1][i]; //Sets new position to previous position
          } // end for loop 'k'
          board[SIZE - 1][i] = 0; // Sets bottom position to 0
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional Variables
    int row, column;

    // do while loop generates another 2 at a random position in the array
    do {
        row = rand() % SIZE;
        column = rand() % SIZE;
    } while (board[row][column] != 0);

    board[row][column] = 2;
  } // end function

  /* ----------------------------------------------
    FUNCTION NAME: moveDown
    INPUT: No input
    OUTPUT: Has no output because it performs a task instead
  ------------------------------------------------*/
  void sixteen::moveDown ()
  {
    // This nested for loop slides all values down
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = SIZE - 1; j >= 0; j--) { // This for loop is for the columns
        for (int k = j; k >= 0; k--) { // This for loop checks the values in the array
          if(board[k][i] != 0){ // If the position in the array is not equal to 0
            board[j][i] = board[k][i]; // Sets the new position to the previous position
            if (k != j) // If k does not equal j
              board[k][i] = 0; // Sets the upmost position to 0
            break;
          } // end if statement
        } // end for loop 'k'
      } // end for loop 'j'
    } // end for loop 'i'

    // This nested for loop merges pair values together
    for (int i = 0; i < SIZE; i++) { // This for loop is for the rows
      for (int j = SIZE - 1; j >= 0; j--) { // This for loop is for the columns
        if(board[j][i] == board[j - 1][i]){
          board[j][i] *= 2;
          for (int k = j - 1; k > 0; k--){ //
            board[k][i] = board[k - 1][i];
          } // end for loop 'k'
          board[0][i] = 0; // Sets upmost position to 0
        } // end if statement
      } // end for loop for 'j'
    } // end for loop for 'i'

    // Additional variables
    int row, column;

    // do while loop generates another 2 at a random position in the array
    do {
        row = rand() % SIZE;
        column = rand() % SIZE;
    } while (board[row][column] != 0);

    board[row][column] = 2;
  } // end function

  /* ----------------------------------------------
    FUNCTION NAME: over
    INPUT: No input
    OUTPUT: Returns an integer as a const
  ------------------------------------------------*/
  int sixteen::over() const
  {
    // This for loop checks for a 16 in the array
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        // if statement checks if a 16 or WIN is found
        // and returns 1
        if (board[i][j] == WIN){
           return 1;
           break;
        } // end if statement
      } // end for loop 'i'
    } // end for loop 'j'

    // additional variable
    int total = 0;

    // This for loop checks if all positions in the array are full
    // and if no moves are possible
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        // if positions in the array hold a value
        // the total integer increases
        if (board[i][j] != 0){
           total++;
        } // end if statement
      } // end for loop 'i'
    } // end for loop

    // if all positions in the array are full, you lose the game and
    // the function return -1
    //if(total == 9){
    if (total == 20){
      return -1;
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
          // if the value in the index has no value output an underscore instead of a 0
          else{
            cout << setw(3) << right << "_";
          }
      } // end for loop 'j'
      cout << endl;
    } // end for loop 'i'
  } // end function
