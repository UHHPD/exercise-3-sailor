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
    int zahl;
    std::vector<int> daten;
    double mu = 3.11538;

    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
	daten.push_back(zahl);
    }

    cout << "Likehood: " << prob(daten, mu) << endl;
    fin.close();
}
