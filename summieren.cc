#include<iostream>
#include<fstream>

int main()
{
  std::ifstream fin("daten.txt");
  int zahl1, zahl2;
  while(!fin.eof()){
    fin >> zahl1 >> zahl2; 
    std::cout << zahl1 << ", " << zahl2 << std::endl;
  }
}