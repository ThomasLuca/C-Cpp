
#include <iostream>
#include <string.h>
#include <vector>
#include "containers.h"
#include <set>
#include <map>


template <typename T>
ostream &operator<<(ostream &out, const set<T> &set){
    for(auto &setel: set){
        out << "{" <<setel <<"},";
    }
    out << endl;
    return out;
}


template<typename T, typename S>
ostream &operator<<(ostream &out,const map<T,S> &maptje){
    for(auto &el: maptje){
        out << el.first << "-->" << el.second <<endl;
    }
    return out;
}

int main(){
    set<int> setint = {1,5,3,6,9,8,4,5,12,45};
    cout << setint <<endl;

    map<string,int> eerstemap = {{"een",5},{"twee",135},{"boe",80},{"huiswaarde",850000}};
    cout << eerstemap << endl;
    return 0;
}