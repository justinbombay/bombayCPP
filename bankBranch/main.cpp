/*
  Justin Bombay
  CS 202 - 1003
  Dr. Vasko
  Assignment 3
  main.cpp
*/

#include <cctype>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bankBranch.h"

using namespace std;

int main(){
  // Additional Variables
  ifstream infile;
  string filename;
  long acctNo;
  short p;
  char decision1, decision2;
  bool check2, result;

  // Variables that are read into file
  string f;
  string l;
  double amt;
  long acct;
  short pin;

  // bankBranch object
  bankBranch o1;

  // Prompts user for file
  cout << endl;
  cout << "Enter file name to begin this program...again: ";
  cin >> filename;

  // Do loop error checks the file the user input
  do {
      infile.open(filename.c_str());

      // If user's input fails, then the if statement clears the previous
      // input and prompts user for another input
      if (infile.fail())
      {
          cin.clear();
          cin.ignore(100, '\n');

          cout << endl;
          cout << "Ahem...Let's try this again: ";
          cin >> filename;
      }

  } while(!infile.is_open());


  // While statement reads in the datafile in the order of
  // first name, last name, account number, pin, and amount
  while (infile)
  {
    infile  >> f >> l >> acct >> pin >> amt;
    o1.addAccount(f, l, amt, acct, pin); // object calls the addAccount function
  }

  // Do while loop is active while the user's decision2 is 'Y' for yes
  do {
      // Prompts user for account number
      cout << endl;
      cout << "Enter account number: ";
      cin >> acct;

      // Assigns index variable to the value that is returned by the searchAccounts function
      int index = o1.searchAccounts(acct); // object calls searchAccounts function

      // If the returned integer from the searchAccounts function is not -1, the if statement is activated
      if (index != -1)
      {
        // Prompts user for pin
        cout << "Enter pin: ";
        cin >> p;

        // check2 variable is assigned to the boolean variable from the verifyAccount function
        check2 = o1.verifyAccount(index, p); // object calls verifyAccount function

        // if check2 boolean variable is true, the if statement is activated
        if (check2 == true)
        {
          o1.outputUserInfo(index); // object calls outputUserInfo function

          cout << endl;

            // do loop prompts user for a decision until a valid input is given
            do {
                cout << "Would you like to make a withdrawl or deposit? (W/D): ";
                cin >> decision1;

                decision1 = toupper(decision1); // CONVERTS LOWERCASE TO UPPERCASE

                // If the user's input is not 'W' or 'D'
                // the while loop clears the user's previous input and prompts them
                // for an input again
                while(cin.fail() || decision1 != 'W' && decision1 != 'D')
                {
                  cout << "Invalid option!" << endl;
                  cin.clear();
                  cin.ignore(100,'\n');

                  cout << endl;
                  cout << "Would you like to make a withdrawl or deposit? (W/D): ";
                  cin >> decision1;
                  decision1 = toupper(decision1); // Converts character to uppercase
                }
              } while (decision1 != 'W'  &&  decision1 != 'D');

          // If the user's input is 'W'
          if(decision1 == 'W'){

            // Prompts user to enter the amount they wish to withdraw
            cout << "Enter an amount you would like to withdraw: ";
            cin >> amt;

            // If the user's input is less than 0 or fails,
            // the do loop clears the user's previous input and prompts them again
            // to enter a valid amount
            do {
                if(amt < 0 || cin.fail()){
                    cout << "Invalid amount entered. >:(" << endl;
                    cin.clear();
                    cin.ignore(100,'\n');

                    cout << endl;

                    cout << "Enter an amount you would like to withdraw: ";
                    cin >> amt;
                }
              } while(amt < 0 || cin.fail());

            // Converts user's input to a negative double
            amt = amt * -1;

          }// end of if (decision1 == 'W') check

          // If the user's input is 'D'
          else if(decision1 = 'D'){
            cout << "Enter an amount you would like to deposit: ";
            cin >> amt;

            // If the user's input is less than 0 or fails,
            // the do loop clears the user's previous input and prompts them again
            // to enter a valid amount
            do {
                if(amt < 0 || cin.fail()){
                    cout << "Invalid amount entered. >:(" << endl;
                    cin.clear();
                    cin.ignore(100,'\n');

                    cout << endl;

                    cout << "Enter an amount you would like to deposit: ";
                    cin >> amt;
                }
              } while(amt < 0 || cin.fail());

          }// end of else if decision = 'D'

        // Result variable is assigned to the returning boolean expression that the
        // updateAccount function returns
        result = o1.updateAccount(index, amt);

        // If the result returned is false
        if (result == false){
          cout << endl;
          cout << "Sorry! Cannot process transaction..." << endl;
        }
      } // end of if (check 2 = true)

      // If the check2 variable returned is false
      else if (check2 == false){
        cout << endl;
        cout << "Account frozen or incorrect pin entered, exiting account..." << endl;
      }

     } // end of if (index != -1)

     // Prompts user if they wish to continue
      cout << endl;
      cout << "Do you wish to continue? (Y/N): ";
      cin >> decision2;
      decision2 = toupper(decision2); // Converts lowercase character to uppercase

      // If the user's input is 'N'
      if (decision2 == 'N')
      {
        cout << endl;
        cout << "Bye! Have a great day! " << endl;
        cout << endl;
      }

      // If the user's input is not 'N' or 'Y'
      // the while loop clears the user's previous input and prompts them
      // for an input again
      while (cin.fail() || decision2 != 'Y' && decision2 != 'N')
      {
          cin.clear();
          cin.ignore(100, '\n');

          cout << endl;
          cout << "Do you wish to continue? (Y/N): ";
          cin >> decision2;
          decision2 = toupper(decision2);
      }
    } while (decision2 == 'Y');

  return 0;
}
