#include "headers.h"

int main(int argc, char *argv[])
{
  if(argc==2)
  {
    lexical_analyser(argv[1]);
    return 0;
  }
  cout << "Problem" << endl;
  return 1;
}
