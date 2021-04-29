#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000);

// Loop getting the number of digits in the code
    int numDigits = 0;
    int code;

    while (numDigits != -1) {
      cout << "Enter number of digits in code (3, 4 or 5): ";
      cin >> numDigits;
      if ((numDigits == 0) || (numDigits == 3) || (numDigits == 4) || (numDigits == 5)) {
        break;
      }
      else {
        continue;
      }
    }

// Generate code
vector<int> codeCode;   // Vector containing the code input
int a;                  // variable to help input each digit from code into the vector codeCode
if (numDigits == 0) {
  cout << "Enter code: ";
  cin >> code;
  cout << "Enter number of digits in code: ";
  cin >> numDigits;

  // Extracting each digit from the single integer
for (int i = pow(10, numDigits - 1); i > numDigits; i = i / 10){
  a = code / i % 10;
  codeCode.push_back(a);
}
  codeCode.push_back(code % 10);  // last number/digit added to the vector

//   // Printing the number to guess
//   cout << "Number to guess: " << codeCode.at(0);
//   for (int i = 1; i < numDigits; i++) {
//     cout << "-" << codeCode.at(i);
//   }
// cout << endl;

}
// When the input of digits is 3, 4, or 5
else {
  // Inputting random digits into the correct game code
  for (int i = 0; i < numDigits; i++) {
    codeCode.push_back(rand() % 10);  // Adds random numbers to the vector
  }

// Checking for duplicate digits in game code
int codeCheck;
int boolCodeCheck = 1;
while (boolCodeCheck == 1) {
  for (int i = 0; i < codeCode.size(); i++) {
    codeCheck = codeCode.at(i);
    for (int j = i+1; j < codeCode.size(); j++) {
      if (codeCheck == codeCode.at(j)) {
        codeCode.erase(codeCode.begin() + i);
        codeCode.push_back(rand() % 10);
        i = 0;
        j = 0;
      }
      else {
        continue;
      }
    }
  }
  boolCodeCheck = 0;
}

  // // Outputting the code to guess
  // cout << "Number to guess: " << codeCode.at(0);
  // for (int i = 1; i < numDigits; i++) {
  //   cout << "-" << codeCode.at(i);
  // }
  // cout << endl;

}
// Getting the guess from the user
int guess;                      // users guess
int whileLoop = 1;              // Makes the while loop proceed forever
vector<int> guessingCode;       // vector for the users guess
int guessLength = 0;
int guessHold;                  // Placeholder for the guess value (Used in calculations)

//While loop for the user to continue guessing if bad conditions are met
while (whileLoop != 0) {
guessingCode.clear();
cout << "Enter Guess: ";
cin >> guess;
guessHold = guess;

guessLength = 0;
while (guessHold != 0) {  // Counter to add the guess value into the other vector
  guessHold = guessHold / 10;
  guessLength += 1;
}
// Checking if the user input is too big
if (guessLength > numDigits) {
  cout << "You can only enter " << numDigits << " digits." << endl;
  guessLength = 0;
  continue;

}
// Extracting digits from the guess and inputting into a vector
else if (guessLength <= numDigits) {
  for (int i = pow(10, numDigits - 1); i > numDigits; i = i / 10){
    int a = guess / i % 10;
    guessingCode.push_back(a);
  }
    guessingCode.push_back(guess % 10);
}

// Checks if user inputted duplicate numbers
int guessCheck;
int boolCheck = 1;        // Variable to include in the condition below when getting number of bulls/cows
for (int i = 0; i < guessingCode.size(); i++) {
  guessCheck = guessingCode.at(i);
  for (int j = i+1; j < guessingCode.size(); j++) {
    if (guessCheck == guessingCode.at(j)) {
      cout << "Each number must be different." << endl;
      boolCheck = 0;
      goto endGuessCheck; // Exit the nested loop
    }
  }
}
endGuessCheck:  // Starting point from exiting the nest loop

  // Getting the number of bulls and cows by comparing the two vectors
  if ((guessingCode.size() == numDigits) && (boolCheck == 1)) {
    int bullCount = 0;
    for (int i = 0; i < numDigits; i++) {
      if (guessingCode.at(i) == codeCode.at(i)) {
        bullCount += 1;
      }
    }
    if (bullCount == numDigits) {
      int bullCount = 0;
      for (int i = 0; i < numDigits; i++) {
        if (guessingCode.at(i) == codeCode.at(i)) {
          bullCount += 1;
        }
      }
      cout << bullCount << " bulls... " << codeCode.at(0);
      for (int i = 1; i < numDigits; i++) {
        cout << "-" << codeCode.at(i);
      }
      cout << " is correct!" << endl;
      return 0;
    }
    cout << bullCount << " bulls" << endl;


// Finding the amount of cows
    int numberPlace;  // Placeholder variable
    int cowCount = 0;
    for (int i = 0; i < guessingCode.size(); i++) {
      numberPlace = guessingCode.at(i);
      for (int j = 0; j < codeCode.size(); j++) {
        if (numberPlace == codeCode.at(j)) {
          cowCount += 1;
        }
      }
    }
    // Subtracting amount of bulls from cows to account for correct number of cows
     if (bullCount >= 1){
      cowCount = cowCount - bullCount;
    }
    cout << cowCount << " cows" << endl;
    bullCount = 0;
    cowCount = 0;
  }
}
}
