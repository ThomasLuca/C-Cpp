// headerfile; voorziet uitschrijven van containers

// uitschrijven: operator<<

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <cstdlib>  // rand
#include <ctime>
#include <string>
using std::endl;
using std::cout;
using std::vector;
using std::map;
using std::set;
using std::unordered_set;
using std::string;
using std::stack;
using std::ostream;
using std::string;
using std::istream;
using std::ifstream;

struct Persoon{
	string naam;
	int leeftijd; 
};

inline bool operator<(const Persoon & a, const Persoon & b){
		if (a.naam < b.naam) return true;
		if (a.naam == b.naam && a.leeftijd < b.leeftijd) return true;
		return false;
}

inline ostream& operator<<(ostream& out, const Persoon & p){
	out<<p.naam<<" ("<<p.leeftijd<<" j)";
	return out;
}


/////////////////////////////////////////////////////////////////////////
// operator<<

template<typename T>
ostream& operator<<(ostream& out, const vector<T> & v){
	if(v.size()==0){
		cout<<"[]"; 
		return out;
	}
	out<<"[ ";
	for(int i=0; i<v.size()-1; i++){
		out<<v[i]<<" | ";
	}
	out<<v[v.size()-1]<<" ]";
	return out;
}

// set uitschrijven? als je per se komma's tussen de elementen wil
// (en geen komma meer na het laatste element), kan je niet met
// een while-lus werken. De reden: je kan niet 'rekenen' met iteratoren,
// dus " s.end() - 1 " heeft geen betekenis (al had je gehoopt dat dat
// de iterator zou zijn die op het laatste element staat te wijzen...)
template<typename T>
ostream& operator<<(ostream& out, const set<T> & s){
	if(s.size()==0){
		cout<<"{}"; 
		return out;
	}
	out<<"{ ";
	typename set<T>::const_iterator it = s.begin();
	for(int i=0; i<s.size()-1; i++){
		out<<*it<<" , ";
		it++;
	}
	out<<*it<<" }";
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const unordered_set<T> & s){
	if(s.size()==0){
		cout<<"{}"; 
		return out;
	}
	out<<"{ ";
	typename unordered_set<T>::const_iterator it = s.begin();
	for(int i=0; i<s.size()-1; i++){
		out<<*it<<" , ";
		it++;
	}
	out<<*it<<" }";
	return out;
}

template<typename S, typename D>
ostream& operator<<(ostream& out, const map<S,D> & m){
	out<<"{ "<<endl;
	typename map<S,D>::const_iterator it = m.begin();
	while(it!=m.end()){
		out<<"  "<<it->first<<" --> "<<it->second<<endl;
		it++;
	}
	out<<"}";
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, stack<T> st){   // st MOET kopie zijn 
	out<<endl<<" __________"<<endl;
	out<<"|          "<<endl;
	while(!st.empty()){
		out<<"  "<<st.top()<<endl;
		st.pop();
	}
	out<<"|          "<<endl;
	out<<"|__________"<<endl;
	return out;
}



