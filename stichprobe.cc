#include<iostream>
#include<fstream>
#include<cmath>

double mittelwert(const std::string name) {
  std::ifstream fin(name);
  double sum = 0;
  double a;
  double b;
  for(int i = 0 ; i < 234; i++){
    fin >> a;
    sum += a;
  }
  fin.close();
  return sum/234.0;
}

double varianz(const std::string name, const double mittelwert) {
  std::ifstream fin(name);
  double a;
  double b;
  double c = 0;
  for(int i = 0; i < 234; i++){
    fin >> a;
    c += pow((a - mittelwert),2);
  }
  fin.close();
  double Varianz = c/234.0;
  return Varianz;
}

int main()
{
  double mwt = mittelwert("datensumme2.txt");
  double Varianz = varianz("datensumme2.txt",mwt);
  std::cout << "Die Varianz ist: "<< Varianz << std::endl;
  std::cout << "Die Standartabweichung ist: " << std::sqrt(Varianz) << std::endl;
}