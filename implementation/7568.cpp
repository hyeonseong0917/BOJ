#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N=0;
vector<pair<int,pair<int,int>>> v;
bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	if(a.second.first==b.second.first){
		return a.second.second>b.second.second;
	}
	return a.second.first>b.second.first;
}
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b=0;
		cin>>a>>b;
		v.push_back({i,{a,b}});
	}
	sort(v.begin(),v.end(),comp);
}
int cur_rank=1;
int same_rank=1;
int Rank[50+1];
int startIdx=0;

void solve(){
	for(int i=0;i<N;++i){
		int cnt=1;
		for(int j=0;j<N;++j){
			if(v[i].second.first<v[j].second.first && v[i].second.second<v[j].second.second){
				++cnt;
			}
		}
		Rank[v[i].first]=cnt;
	}
	for(int i=0;i<N;++i){
		cout<<Rank[i]<<" ";
	}
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}