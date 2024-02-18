#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> P,D;
int N,K;
vector<int> reverse_shuffle(){
	vector<int> v(N,0);
	for(int i=0;i<N;++i){
		v[D[i]-1]=P[i];
	}
	return v;
}
vector<int> tmp;
int main() {
	// your code goes here
	
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		P.push_back(a);
		tmp.push_back(a);
	}
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		D.push_back(a);
	}
	for(int i=0;i<K;++i){
		P=reverse_shuffle();
	}
	for(int i=0;i<N;++i){
		cout<<P[i]<<" ";
	}
	return 0;
}