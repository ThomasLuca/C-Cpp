#include "containers.h"
#include <iostream>
#include <vector>
using namespace std;

const int AANTAL = 5;

int main() {
    vector<string> tabel[AANTAL];
    tabel[1].push_back("aap"); //nog geen elementen in de vector
    tabel[1].push_back("noot");
    tabel[1].push_back("mies");
    for (vector<string> &v : tabel)
        cout << v;
    cout << endl;

    vector<vector<int> > v2;
    v2.reserve(AANTAL);
    for(int i=0; i<AANTAL; i++){
        vector<int> w;
	    w.reserve(i);
        for(int k=0; k<i; k++)
            w.push_back(10+10*k);
        v2.push_back(std::move(w));  //w wordt nu niet gekopieerd! (zie later)
    }

    for(int i=v2.size()-1 ; i>=0 ; i--){
        for(int k=v2[i].size()-1 ; k>=0 ; k--){
            cout << v2[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}
