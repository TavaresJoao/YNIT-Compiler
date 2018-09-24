#1bin/bash
g++ -c file.cpp
g++ -c lexical_analysis.cpp
g++ -c main.cpp
g++ -c token.cpp
g++ -o main file.o lexical_analysis.o main.o token.o

for x in Instances/*
do
  echo $x;
  ./main $x
done
