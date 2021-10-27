#include<iostream>
#include<fstream>

int main(){
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme2.txt");
  double a;
  double b;
  for(int n=1 ; n < 235 ; ++n){
    fin >> a >> b;
    double c = a+b;
    fout << c << std::endl;
  }
  fout.close();
  fin.close();
}