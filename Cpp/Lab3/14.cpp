#include <iostream>
#include <string.h>
#include <vector>
#include "containers.h"
#include <set>
#include <map>

template<typename T, typename S>
ostream &operator<<(ostream &out,const map<T,S> &maptje){
    for(auto &el: maptje){
        out << el.first << "-->" << el.second <<endl;
    }
    return out;
}



int main(){
    map<string,char> demap;
    string word = "";
    while(word != "STOP"){
        cin >> word;
        demap.insert({word,word[0]});
    };

    char letter;
    int counter = 0;
    cout << "you wrote: " << endl;
    cout << demap << endl;
    cout << "now give me al letter" << endl;
    cin >> letter;
    for(auto &el: demap){
        if(el.second == letter) 
            counter++;
    }
    cout << "there are " << counter << " words beginning with that letter";
    return 0;
}