/*
  Justin Bombay
  CS 302 - 1003
  Dr. Vasko
  Assignment 02
*/

#include <iostream>
#include <stack>

using namespace std;

// FUNCTION PROTOTYPES
void drawStars(int amount);
void drawStarsUntil(int amount);
stack <bool> convertToBin(int x);
void outputBits(stack<bool> binNum);

int main(){

  int amount, x;

  cout << "How many stars do you wish upon?: ";
  cin >> amount;

  drawStars(amount);
  cout << endl;

  cout << "Ok almost done! " << endl;
  cout << endl;

  cout << "Enter an integer and I'll try to convert it to Binary: ";
  cin >> x;

  outputBits(convertToBin(x));

  cout << endl;

  return 0;
} // END INT MAIN()



// DRAW STARS FUNCTION
void drawStars(int amount){
  // BASE CASE
  if (amount == 0)
    return;

  // PRINTS STARS FROM GREATEST AMOUNT TO LEAST
  drawStarsUntil(amount);
  cout << endl;

  // GENERAL CASE DECREASES THE AMOUNT
  drawStars(amount - 1);

  // PRINTS STARS FROM LEAST AMOUNT TO GREATEST
  drawStarsUntil(amount);
  cout << endl;
} // END DRAWSTARS FUNCTION


// DRAW STARS UNTIL FUNCTION
void drawStarsUntil(int amount){
  // BASE CASE
  if (amount == 0)
    return;
  cout << "*";

  // GENERAL CASE DECREASES THE AMOUNT
  drawStarsUntil(amount - 1);
} // END DRAWSTARSUNTIL FUNCTION


// CONVERT TO BINARY FUNCTION
stack <bool> convertToBin(int x){
  // BASE CASE
  if (x == 0){
    stack <bool> newStk;
    return newStk;
  }

  // GENERAL CASE
  else{
    // OBTAINS THE BINARY NUMBER BY CONTINUOUSLY
    // DIVIDING THE INPUT BY 2 UNTIL THE INPUT IS 0
    stack <bool> bin(convertToBin(x / 2));

    // USING MODULUS, WE FIND IF THE RESULT
    // IS A 0 OR 1 AND PLACE THAT IN THE STACK
    if (x % 2 == 1)
      bin.push(1);
    if (x % 2 == 0)
      bin.push(0);
    return bin;
  }
} // END CONVERTTOBIN FUNCTION

// OUTPUT BITS FUNCTION
void outputBits(stack<bool> binNum){
  int y = 0;

  // GENERAL CASE CONTINUES TO OUTPUT
  // THE BINARY RESULTS UNTIL THE STACK IS EMPTY
  if(!binNum.empty()){
    y = binNum.top(); 
    binNum.pop();
    outputBits(binNum);
    cout << y;
    return;
  } // END IF STATEMENT

  // BASE CASE
  else
    return;
} // END OUTPUT BITS FUNCTION
