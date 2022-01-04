/*
  Justin Bombay
  -- Perfect Invariants Project --
  -- Coded in C++ --
  This program finds perfect digital invariants that are within the range from 10,000 to 99,999. 
  For further explanation, a perfect digital invariant is a number in a given number base b that is the sum of its own digits each raised to a given power p. 
  For example, 4,150 == 4^5 + 1^5 + 5^5 + 0^5.
*/

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  // local variables
  int currentNum, tempNum, newNum, endNum, powNum;
  int sum = 0;

    //for loop that iterates through the set range of numbers from the smallest 5 digit number to
    // the greatest 5 digit number
    for (currentNum = 10000; currentNum <= 99999; currentNum++) {

        // sets temporary number that is used in the while loop to the current number
        tempNum = currentNum;

        // resets the sum
        sum = 0;

        // while loop to find the sum and lessen the length of the current number
        while (tempNum > 0) {
                // separates the last number of the current number
                endNum = tempNum % 10;

                // separates the previous numbers from the end number
                newNum = tempNum / 10;

                // sets the last number of the integer to the 5th power
                powNum = pow(endNum,5);

                // adds the powNum variable to the sum
                sum = sum + powNum;

                // sets the tempNum variable to the new number
                tempNum = newNum;
          }

          // if sum is equal to the current number, then it outputs the number that was found
          if(sum == currentNum) {
              cout << "Number found! " << sum << " is a valid five digit number!" << endl;
            }
    }

  return 0;
}
