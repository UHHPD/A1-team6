#include<iostream>
#include<fstream>

int main()
{
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  int zahl1, zahl2;
  while(!fin.eof()){
    fin >> zahl1 >> zahl2; 
    fout << zahl1 + zahl2 << std::endl;
  } 
  fout.close();
  fin.close();
}
