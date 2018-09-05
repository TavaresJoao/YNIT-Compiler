#include "headers.h"

const vector<string> split(const string& s, const char& delimiter)
{
  string buff{""};
  vector<string> v;

  for(auto n:s)
  {
    if( n != delimiter )
      buff += n;
    else
    {
      if( buff != "" )
      {
        v.push_back(buff);
        buff="";
      }
    }
  }
  if(buff != "")
    v.push_back(buff);

  return v;
}

vector<pair<string,int>> read_file(string inFile)
{
  vector<pair<string,int>> code;

  ifstream mycode;
  mycode.open(inFile);

  if( !mycode.is_open() )
  {
    cout << "Problem opening the input file" << endl;
    return code; // ERROR
  }

  int i, j, row=1;
  pair<string,int> aux_code;
  vector<string> aux_split;
  string line;

  while( !mycode.eof() )
  {
    getline(mycode, line);

    aux_split = split(line, ' ');
    for(i=0; aux_split.begin()+i != aux_split.end(); i++)
    {
      aux_code.first = aux_split[i];
      aux_code.second = row;
      code.push_back(aux_code);
    }

    row++;
  }

  /*
  for(i=0; code.begin()+i!=code.end(); i++)
  {
    cout << code[i].first << '\t' << code[i].second << endl;
  }
  */

  mycode.close();
  return code;
}
