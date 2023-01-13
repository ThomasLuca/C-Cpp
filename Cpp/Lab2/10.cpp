#include <memory>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void dupliceer(vector<unique_ptr<T>> &vector, int n) {
    int original_size = vector.size();
    //cout << original_size << endl;
    vector.reserve(vector.size() * (n + 1));

    for(auto &naam : vector) {
        for(int j = 0; j < n; j++) {
            vector.push_back(make_unique<string>(*naam));
        }
    }

    for(int i = 0; i < original_size; i++) {
        vector.erase(vector.begin());
    }
    vector.shrink_to_fit();
}

int main() {
    unique_ptr<string> namen[] = {
        make_unique<string>("Rein"), make_unique<string>("Ada"),
        make_unique<string>("Eppo"), make_unique<string>("Pascal"),
        make_unique<string>("Ilse")};

    vector<unique_ptr<string>> namenvector;

    //voeg de unieke pointers van namen toe aan namenvector
    for(auto &naam : namen) {
        namenvector.push_back(move(naam));
    }

    dupliceer(namenvector, 3);

    //print de inhoud van namenvector
    for(auto &naam : namenvector){
        cout << *naam << " ";
    }

    cout << endl;
    cout << "capacity of vector is: " << namenvector.capacity() << endl;
    cout << "size of vector is: " <<namenvector.size() << endl;
    
    //output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal Pascal Ilse Ilse Ilse
    
    return 0;
}

