#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<pair<string,int>> v;

bool comp(pair<string,int> a, pair<string,int> b){
	if(a.second==b.second){
		if(a.first.size()==b.first.size()){
			return a.first<b.first;
		}
		return a.first.size()>b.first.size();
	}
	return a.second>b.second;
}
int N,M;
map<string,int> m;
vector<string> input_str;
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		input_str.push_back(s);
	}
}
void solve(){
	for(int i=0;i<N;++i){
		string cur_str=input_str[i];
		if(cur_str.size()>=M){
			++m[cur_str];
		}
	}	
	for(int i=0;i<N;++i){
		string cur_str=input_str[i];
		if(m[cur_str]){
			v.push_back({cur_str,m[cur_str]});
			m[cur_str]=0;
		}
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();++i){
		cout<<v[i].first<<"\n";
	}
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}