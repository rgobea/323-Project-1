// Program name: "Token". This program builds the definitions of 3 of the categories that will be utilized by the DFSMs, namely keywords, operators, and delimiters.
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
// Program name: Token
// Programming languages with 2 modules in C++
// Date program began 2020/9/21
// Date program completed 2020/9/24

// Project information:
// Files: Token.hpp, Tokenize.cpp
// Status: Program has been tested and fulfills purpose with no errors

// Translator information:
// Gnu compiler: g++ -o Tokenize Tokenize.cpp
// Execution:
// ./Tokenize

// References and credits
// No references

// Begin code area

#ifndef TOKENS_H
#define TOKENS_H

#include <unordered_set>
#include <string>
#include<cstddef>

enum class Tokentype{
  Identifier, Keyword, String, Literal, Comment, Operator, Delim
};
static const std::unordered_set<std::string> keywords = {"var", "for", "while", "print", "constant"};
static const std::unordered_set<char> operators = {'+', '-', '*', '/', '=','<','>'};
static const std::unordered_set<char> delims = {'(', ')', ';'};
static const std::unordered_set<char> whitespace = {'\n', '\r', '\t', ' ' };

struct Token{
private:
  std::string tokenValue;
  Tokentype tokenType;
public:
  Token() = delete;
  Token(const std::string& tokenValue1, Tokentype tokenType1): tokenValue(tokenValue1), tokenType(tokenType1) {}
  Token(const Token& token): tokenValue(token.tokenValue), tokenType(token.tokenType) {}
};

#endif
