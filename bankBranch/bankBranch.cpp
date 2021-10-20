/*
  Justin Bombay
  CS 202 - 1003
  Dr. Vasko
  Assignment 3
  bankBranch.cpp
*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "bankBranch.h"


using namespace std;

  /* ----------------------------------------------
    DEFAULT CONSTRUCTOR
    INPUT: No input
    OUTPUT: No output because it performs a task instead
  ------------------------------------------------*/
  bankBranch::bankBranch ()
  {
    amountOfAccounts = 0;
  } // end default constructor

  /* ----------------------------------------------
    FUNCTION NAME: addAccount
    INPUT: Reads in the first name, last name, the amount, the account number, and pin
    OUTPUT: No output because it performs a task instead
  ------------------------------------------------*/
  void bankBranch::addAccount(string f, string l, double amt, long acct, short p)
  {
      // Reads in each variable into their appropriate array
      first[amountOfAccounts] = f;
      last[amountOfAccounts] = l;
      amount[amountOfAccounts] = amt;
      acctNo[amountOfAccounts] = acct;
      pin[amountOfAccounts] = p;

      // Increases the amount of accounts
      amountOfAccounts++;
  } // end addAccount function

  /* ----------------------------------------------
    FUNCTION NAME: searchAccounts
    INPUT: Reads in the account number as the variable "acct"
    OUTPUT: Returns an integer
  ------------------------------------------------*/
  int bankBranch::searchAccounts(long acct) const
  {
    // Additional variables within the searchAccounts function
    int i = 0;
    bool found = false;

    // Linear search checks if the account number the user entered in is found in the data file
    for (i = 0; i < amountOfAccounts; i++) {
          if (acctNo[i] == acct){
            found = true;
            break;
          }
    }

    // If the account is verified, return the position of the array
    if (found){
      return i;
    }

    // If the account does not match any account in the array return a negative integer
    else {
      cout << endl;
      cout << "Sorry! Account not found!" << endl;
      return -1;
    }
  } // end searchAccounts function


  /* ----------------------------------------------
    FUNCTION NAME: verifyAccount
    INPUT: Reads in the position of the array as the variable "index", and the pin as the variable "p"
    OUTPUT: Outputs a boolean variable
  ------------------------------------------------*/
  bool bankBranch::verifyAccount(int index, short p)
  {
    // Additional variable for verifyAccount function
    bool check = false;

    // If the number of attempts is less than 3, the program continues to prompt user for the acount number
    if (attempts[index] < 3){

      // If the pin matches the pin of the index in the array, then the boolean expression returned is true
      if(p == pin[index]){
        check = true;
        return check;
      }

      // If the pin does does atch the pin of the index in the array, then the amount of attempts increases
      // and the boolean expression returned is false
      else {
          attempts[index]++;
          check = false;
          return check;
        }
    } // end of if (attempts[index]< 3)
    return check;
  } //end verifyAccount function

  /* ----------------------------------------------
    FUNCTION NAME: updateAccount
    INPUT: Reads in the position of the array as the variable "index" and the amount the user
          enters in as the variable "amt"
    OUTPUT: Returns a boolean variable
  ------------------------------------------------*/
  bool bankBranch::updateAccount(int index, double amt)
  {
    // If the amount of the position in the array is less than 0, the boolean expression returned is false
    if (amount[index] < 0 && amt < 0){
      return false;
    }

    // If the amount of the position of the array is not less than 0, then the amount for the account
    // is the amount of the account added with the user's input
    else {
          amount[index] = amount[index] + amt;
          return true;
    }
  }// end updateAccount function

  /* ----------------------------------------------
    FUNCTION NAME: outputUserInfo
    INPUT: Reads in the position of the array as the variable "index"
    OUTPUT: Outputs the user's first and last name, their account number, and their balance
  ------------------------------------------------*/
  void bankBranch::outputUserInfo(int index) const
  {
    cout << endl;
    cout << setw(16) << left << "Name: " << setw(17) << right << last[index] << ", " << first[index] << endl;
    cout << setw(20) << left << "Account #: " << setw(25) << right << acctNo[index] << endl;
    cout << setw(20) << left << "Balance $: " << setw(25) << right  << fixed << setprecision(2) << amount[index] << endl;
  }
