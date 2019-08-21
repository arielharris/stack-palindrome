
// Ariel Harris
// Program Assignment 1 Driver
// Purpose: This program reads strings from a provided file and tells if they are
// a palindrome or not.
// Input: Provided file of phrases
// Process: Create three stacks and attmept to read file, if not possible exit
// the program. If the file can be read input each line, but only take in chars
// in the alphabet. Convert these to lower case and push onto first stack.
// Push the same phrase in reverse onto another stack, pop tops and compare each
// char until stacks are empty or chars do not match.
// Output: Print each line and whether or not it is a palindrome

#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace std;

bool isPal(Stack& phrase, Stack& revPhrase);
void clearStacks(Stack &phrase, Stack& revPhrase, Stack& temp);

int main()
{
  const int length = 20;
  const string READFILE = "/home/fac/sreeder/class/cs2430/p1input.dat";
  Stack phrase(length);
  Stack revPhrase(length);
  Stack temp(length); //intermediate stack to pass btwn other stacks
  ifstream input;
  string line; //the input string
  int len; //length of the input string
  char hold; //temp char to push/pop btwn stacks

  cout << endl << endl;
  cout << "Welcome!" << endl;
  cout << "This program will tell if provided phrases are palindromes." << endl << endl;
  
  // open file
  input.open(READFILE);
  
  if (input.fail()){
    cout << endl << "Cannot read file, exiting program." << endl;

    return 0;
  }

  // if file can be read then read each line & remove punct/spaces
  while (getline(input,line)){
    len = line.length();
    for (int i = 0; i < len; i++){
      if (isalpha(line[i])){ //only chars of the alphabet are pushed
        phrase.push(tolower(line[i])); // send to lower so all chars are same
      }
    }

    // move from one stack to temp & rev stack so rev stack is rev order
    while (!phrase.isEmpty()){
      phrase.pop(hold);
      temp.push(hold);
      revPhrase.push(hold);
    }

    //move from temp stack back to orig stack so that stack is in orig order
    while (!temp.isEmpty()){
      temp.pop(hold);
      phrase.push(hold);
    }

    // call isPal fucnt to check if the phrase is a palindrome
    // print line and result of funct
    if (isPal(phrase, revPhrase)){
      cout << line << endl;
      cout << "Is a palindrome" << endl << endl;
    } else {
      cout << line << endl;
      cout << "Is not a palindrome" << endl << endl;
    }

    // empty the stacks
    clearStacks(phrase, revPhrase, temp);
    
  }
      
  input.close();

  cout << "End of program, goodbye!" << endl;
  
  return 0;
}

bool isPal(Stack& phrase, Stack& revPhrase)
// this function loops through the two stacks popping each top char and
// comparing each to check if they match until it finds two different
// chars, or the stack phrase is empty
// returns the true/false result of the last two compared chars
{
  char topOne;
  char topTwo;

  phrase.pop(topOne);
  revPhrase.pop(topTwo);

  while(topOne == topTwo && !phrase.isEmpty()){
    phrase.pop(topOne);
    revPhrase.pop(topTwo);
  }

  return topOne == topTwo;
}

void clearStacks(Stack &phrase, Stack& revPhrase, Stack& temp)
// this function clears the stacks by looping through and popping off the cars
// until each stack is empty
{
  char trash;
  
  while (!phrase.isEmpty()){
    phrase.pop(trash);
  }

  while (!revPhrase.isEmpty()){
    revPhrase.pop(trash);
  }

  while (!temp.isEmpty()){
    temp.pop(trash);
  }

}
