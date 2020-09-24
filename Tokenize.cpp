// Program name: "Tokenize". This program takes an input file and returns it as a vector of tokens. Tokens are not categorized, as this is done later by the 3 DFSMs.
// Copyright (C) 2020 Richard Gobea
// This program is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License version 3 as published by the Free Software Foundation.
// This program is distributed in the hope that it will be useful, but without any warranty;
// without even the implied warranty of merchantibility or fitness for a particular purpose.
// See the GNU General Public License for more details.
// A copy of the GNU General Public License v3 is available here:
// <https://www.gnu.org/licenses/>.

// Author information:
// Author name: Richard Gobea
// Author email: rgobea@csu.fullerton.edu

// Program information:
// Program name: Tokenize
// Programming languages 2 modules in C++
// Date program began 2020/9/21
// Date program completed 2020/9/24

// Project information:
// Files: Tokenize.cpp, Token.hpp
// Status: Program has been tested and fulfills purpose with no errors

// Translator information:
// Gnu compiler: g++ -o Tokenize Tokenize.cpp

// Execution:
// ./Tokenize

// References and credits
// No references

// Begin code area





#include "Token.hpp"
#include <iostream>
#include <vector>
#include <fstream>
std::vector<char> Tokenize (std::string filename){
  std::ifstream file(filename); // Opens file
  if(file.fail()){ // Error message if file fails to open
    std::cout << "Error. Unable to open file" << std::endl;
    exit(0);
  }

  char cha1;
  std::vector<char> vec1; // Iterates through file
  while (file  >> std::noskipws >> cha1){
    if(whitespace.find(cha1) != whitespace.end()){
      vec1.push_back('\n');
    }
    else if(delims.find(cha1) != delims.end()){ // Different cases for comparing to definitions of delims and operators. Will return vector containing tokens
      vec1.push_back('\n');
      vec1.push_back(cha1);
      vec1.push_back('\n');
    }
    else if(delims.find(cha1) != delims.end()){
      vec1.push_back('\n');
      vec1.push_back(cha1);

    }
    else if(operators.find(cha1) != operators.end() && operators.find(file.peek()) != operators.end()){
      vec1.push_back('\n');
      vec1.push_back(cha1);
    }
    else if(operators.find(cha1) != operators.end()){
      vec1.push_back(cha1);
    }

    else{
      vec1.push_back(cha1);
    }
  }
  std::vector<char>::iterator ptr; // Prints contents of vec1 containing tokens of inputted file
  for(ptr = vec1.begin(); ptr < vec1.end(); ptr++){
  std::cout << *ptr;

}
return vec1;

}
int main(){ // Main that will call Tokenize function. Included here for testing purposes, will be moved to own file at end of project
  std::string file;
  std::cout << "Input the name of the file to tokenize" << std::endl; // Takes user input for name of file to be tokenized
  std::cin >> file;
  std::cout << "Received input: " << file << ". Opening file" << std::endl;
  Tokenize(file);
  std::cout << "Program done. Returning 0" << std::endl;
  return 0;
}
