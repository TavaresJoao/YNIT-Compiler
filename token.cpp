#include "headers.h"

void addToken(list<Token> tokens, pair<string, int> word_token)
{
  Token aux;
  aux.id_token = word_token.first;
  aux.num = word_token.second;

  tokens.push_back(aux);
}
