#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<list>

using namespace std;

typedef struct
{
  string id_token; // tipo da palavra reservada
  int num; // line
}Token;

// file functions
const vector<string> split(const string& s, const char& c);
vector<pair<string,int>> read_file(string inFile);

// lexical_analysis functions
char verify_digit(int digit);
int verify_identifier(string word);
int verirify_number(string word);
string id_token_word(string word);
int lexical_analyser(string inFile);

// token functions

#endif
