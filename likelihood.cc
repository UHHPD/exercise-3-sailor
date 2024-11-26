#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double prob(std::vector<int> daten,double mu) {
    double p = 1;
        
    for(int k : daten){
        p *= pow(mu, k) * exp(-mu) / tgamma(k + 1);
        
    }
    return p;
}
int main() {
    using namespace std;
    vector<int> daten(234);
    

    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten[i] = n_i;
    }

    ofstream fout("likelihood.txt");
    for(double mu = 0; mu < 6; mu += 0.1){
        fout << mu << " " << prob(daten, mu) << endl;
    }
    // cout<<prob(daten, 3.11538)<<endl;

    ofstream fout2("nll.txt");
    for(double mu = 0; mu < 6; mu += 0.1){
        fout2 << mu << " " << -2*log(prob(daten, mu)) << endl;
    }

    ofstream fout3("deltanll.txt");
    for(double mu = 0; mu < 6; mu += 0.1){
        fout3 << mu << " " << -2*log(prob(daten, mu))-(-2*log(prob(daten,3.11538))) << endl;
        }

    fout.close();
    fout2.close();
    fout3.close();
    fin.close();
    
    //double lambda = prob(daten,3.11538) / prob(daten,daten);
    //cout<<-2*log(lambda)<<endl;
    //double ndof=233;
    //double z=-2log(lambda)-ndof/sqrt(2*ndof);
    //cout<<z<<endl;
    //cout<<erf(z/sqrt(2))<<endl;
}