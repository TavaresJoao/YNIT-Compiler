#include "headers.h"

#define IDENTIFIER_ERROR -1
#define NUMBER_ERROR -2

char verify_digit(int digit)
{
  if(digit>=48 && digit<=57)
    return 'd'; // Classifica o char como um Digito.

  if((digit>=65 && digit<=90) || (digit>=97 && digit<=122))
    return 'l'; // Classifica o char como uma Letra.

    return '0'; // Retorna 0 quer dizer que deve ser um caractere especial
}

int verify_identifier(string word)
{
  if( verify_digit((int)word[0]) == 'l' )
  {
    for(int i=1; i<word.length(); i++)
    {
      if( verify_digit((int)word[i]) == '0' )
        return IDENTIFIER_ERROR;
    }
    return 0;
  }
  else
    return 1;
}

int verirify_number(string word)
{
  for(int i=0; i<word.length(); i++)
    if( verify_digit((int)word[i]) != 'd' )
      return NUMBER_ERROR;
  return 0;
}

string id_token_word(string word)
{
  if(word.compare("if")==0)
    return "IF";
  else if(word.compare("then")==0)
    return "THEN";
  else if(word.compare("else")==0)
    return "ELSE";
  else if(word.compare("end")==0)
    return "END";
  else if(word.compare("repeat")==0)
    return "REPEAT";
  else if(word.compare("until")==0)
    return "UNTIL";
  else if(word.compare("read")==0)
    return "READ";
  else if(word.compare("write")==0)
    return "WRITE";
  else if(word.compare("+")==0)
    return "PLUS";
  else if(word.compare("-")==0)
    return "MINUS";
  else if(word.compare("*")==0)
    return "TIMES";
  else if(word.compare("/")==0)
    return "DIV";
  else if(word.compare("=")==0)
    return "EQUAL";
  else if(word.compare("<")==0)
    return "LESS";
  else if(word.compare("(")==0)
    return "LBRACKET";
  else if(word.compare(")")==0)
    return "RBRACKET";
  else if(word.compare(";")==0)
    return "DOTCOMA";
  else if(word.compare(":=")==0)
    return "ATRIB";
  else if(verirify_number(word)==0)
    return "NUMBER";
  else if(verify_identifier(word)==0)
    return "ID";
  else
    return "ERROR";
}

int take_comment_out(vector<pair<string, int>> code, int start)
{
  int i=0;
  while(( code.begin()+start+i != code.end() )
        && ( code[start+i].first.compare("}") ))
  {
    //code.erase(code.begin()+start+i);
    i++;
  }
  //code.erase(code.begin()+start+i);
  return i;
}

int lexical_analyser(string inFile)
{
  int i;
  list<Token> tokens;

  vector<pair<string, int>> code = read_file(inFile);

  for(i=0; code.begin()+i != code.end(); i++)
  {
    if(code[i].first.compare("{")==0)
      i = take_comment_out(code, i);
    else
    {
      string reserved_word = id_token_word(code[i].first);
      if(reserved_word.compare("ERROR")==0)
      {
        if(verify_identifier(code[i].first)==IDENTIFIER_ERROR)
        {
          cout  << "Erro lexico na palavra: " << code[i].first
                << ". Na linhna: " << code[i].second << endl;
        }
        else
        {
          cout  << "Erro lexico no numero: " << code[i].first
                << ". Na linha: " << code[i].second << endl;
        }
      }
      else
        cout << "<" << reserved_word << "," << code[i].second << ">" << endl;
    }
  }

  return 0;
}
