#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
  return pow(mu, k)*exp(-mu)/tgamma(k+1);
}

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("histpoi.txt");

    int n_i;
    double mu = 3.11538;
    vector<int> zaehler(11);
    for(int i = 0; i < 234; ++i) {
        fin >> n_i;
	zaehler[n_i] += 1;
    }

    for(unsigned int k = 0; k < zaehler.size(); ++k) {
      cout << k << ": " << zaehler[k] << endl;
      fout << k << " " << zaehler[k] << " " << 234*poisson(mu, k) << endl;
    }

    fin.close();
    fout.close();
}
