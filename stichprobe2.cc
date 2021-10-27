#include<iostream>
#include<fstream>
#include<cmath>

double mittelwert(std::ifstream& fin, const int num) {
  double sum = 0;
  double a;
  double b;
  for(int i = 0 ; i < num; i++){
    fin >> a;
    sum += a;
  }
  return sum/num;
}

double varianz(std::ifstream& fin, const double mittelwert, const int num) {
  double a;
  double b;
  double c = 0;
  for(int i = 0; i < num; i++){
    fin >> a;
    c += pow((a - mittelwert),2);
  }
  double Varianz = c/num;
  return Varianz;
}

void ninepack(const std::string name, const std::string mwtname, const std::string varname, const int alldatnum, const int packsize)
{
  std::cout << std::endl << "Mittelwerte und Varianzen von " << packsize <<"er Datenpaketen" << std::endl << std::endl;
  std::ifstream fin1(name);
  std::ifstream fin2(name);
  std::ofstream fmwt(mwtname);
  std::ofstream fvar(varname);
  double mwt;
  double var;
  double gesamtmwt;
  double mwtvarianz;
    for (int i=0; i <= alldatnum; i+=packsize) {
      mwt = mittelwert(fin1, packsize);
      gesamtmwt += mwt;
      var = varianz(fin2, mwt, packsize);
      mwtvarianz += var;
      std::cout << "Paket nummer: " << (i+1)/packsize << " Mittelwert: " << mwt << " varianz: " << var << std::endl;
      fmwt << mwt << std::endl;
      fvar << var << std::endl;
    }
  fin1.close();
  fin2.close();
  fmwt.close();
  fvar.close();
  std::cout << std::endl << "Der Mittelwert der " << packsize << "er Pakete ist: " << gesamtmwt/(alldatnum/packsize) << std::endl;
  std::cout << "Der Mittelwert der Varianz der " << packsize << "er Pakete ist: " << mwtvarianz/(alldatnum/packsize) << std::endl;
}

void all(const std::string name) {
  std::ifstream fin1(name);
  std::ifstream fin2(name);
  double mwt = mittelwert(fin1, 234);
  std::cout << std::endl << "Der Mittelwert ist aller Daten: " << mwt << std::endl;
  double Varianz = varianz(fin2, mwt, 234);
  std::cout << "Die Varianz aller Daten ist: "<< Varianz << std::endl;
  std::cout << "Die Standartabweichung aller Daten ist: " << std::sqrt(Varianz) << std::endl;
  fin1.close();
  fin2.close();
}

int main()
{
  const std::string name = "datensumme2.txt";
  const std::string mwtname = "Mittelwert.txt";
  const std::string varname = "Varianz.txt";
  all(name);
  ninepack(name, mwtname, varname, 234, 9);
}

