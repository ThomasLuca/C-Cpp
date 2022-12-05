#include <memory>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void dupliceer(vector<unique_ptr<T>> &namenvector, int n)
{
    int initial_size = namenvector.size();
    namenvector.reserve(namenvector.size()*(n+1));
    for(auto &naam : namenvector){
        for (int j = 0; j < n; j++)
        {
            namenvector.push_back(make_unique<string>(*naam));
        }
    }
    for (int i = 0; i < initial_size; i++)
    {
        namenvector.erase(namenvector.begin());
    }
    namenvector.shrink_to_fit();
    //cout<<namenvector.capacity()<<endl;
    
}

int main()
{

    unique_ptr<string> namen[] = {make_unique<string>("Rein"),
                                  make_unique<string>("Ada"), make_unique<string>("Eppo"),
                                  make_unique<string>("Pascal"), make_unique<string>("Ilse")};
    vector<unique_ptr<string>> namenvector;
    // voeg de unieke pointers van namen toe aan namenvector

    for (int i = 0; i < sizeof(namen) / sizeof(namen[0]); i++)
    {
        namenvector.push_back(move(namen[i]));
    }
    dupliceer(namenvector, 3);
    for (int i = 0; i < namenvector.size(); i++)
    {
        cout << *namenvector[i] <<" ";
    }
    cout<<endl;

    // print de inhoud van namenvector
    // output moet zijn: Rein Rein Rein Ada Ada Ada Eppo Eppo Eppo Pascal Pascal Pascal Ilse Ilse Ilse
    return 0;
}
