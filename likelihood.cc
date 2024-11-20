#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double prob(std::vector<int> daten, double mu) {
  double p = 1.;
  for(int k: daten) {
    p *= pow(mu, k)*exp(-mu)/tgamma(k+1);
  }
  return p;
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    //ofstream fout("likelihood.txt");
    ofstream fout("nll.txt");

    int zahl;
    std::vector<int> daten;

    for(int i = 0; i < 234; ++i) {
        fin >> zahl;
	daten.push_back(zahl);
    }

    /* for(double mu = 0; mu < 6.; mu += 0.01) {
      fout << mu << " " << prob(daten, mu) << endl;
      } */

    for(double mu = 0; mu < 6.; mu += 0.01) {
      fout << mu << " " << -2*log(prob(daten, mu)) << endl;
    }

    fin.close();
    fout.close();
}
