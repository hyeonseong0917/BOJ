#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<pair<string,int>,pair<int,int>> a, pair<pair<string,int>,pair<int,int>> b){
	if(a.first.second==b.first.second){
		if(a.second.first==b.second.first){
			return a.second.second<b.second.second;
		}
		return a.second.first<b.second.first;
	}
	return a.first.second<b.first.second;
}
int main() {
	// your code goes here
	int N;
	cin>>N;
	vector<pair<pair<string,int>,pair<int,int>>> v;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({{s,c},{b,a}});
	}
	sort(v.begin(), v.end(), comp);
	cout<<v[N-1].first.first<<"\n";
	cout<<v[0].first.first;
	
	return 0;
}