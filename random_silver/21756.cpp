#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0;
	cin>>N;
	vector<int> v;
	v.push_back(0);
	for(int i=1;i<=N;++i){
		v.push_back(i);
	}
	while(v.size()>2){
		vector<int> tmp(1,0);
		for(int i=1;i<v.size();++i){
			if(i%2==0){
				tmp.push_back(v[i]);
			}
		}
		v=tmp;
	}
	cout<<v[1]<<"\n";
	return 0;
}