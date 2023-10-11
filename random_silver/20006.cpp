#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX=300+5;
#define ll long long
bool comp(pair<int,string> a, pair<int,string> b){
	return a.second<b.second;
}
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int p,m;
	cin>>p>>m;


	// 방 자료구조 어떻게? 
	vector<pair<int,string>> room[MAX];
	for(int i=0;i<MAX;++i){
		room[i].clear();
	}
	for(int i=0;i<p;++i){
		int level;
		string nick;
		cin>>level;
		cin>>nick;
		for(int j=0;j<MAX;++j){
			if(room[j].size()==0){
				room[j].push_back({level,nick});
				break;
			}
			if(room[j].size()==m) continue;
			if(abs(room[j][0].first-level)<=10){
				room[j].push_back({level,nick});
				break;
			}
		}
	}
	for(int i=0;i<MAX;++i){
		if(room[i].size()==0) break;
		if(room[i].size()==m){
			cout<<"Started!"<<"\n";	
		}else{
			cout<<"Waiting!"<<"\n";
		}
		sort(room[i].begin(),room[i].end(),comp);
		// reverse(room[i].begin(),room[i].end());
		for(int j=0;j<room[i].size();++j){
			cout<<room[i][j].first<<" "<<room[i][j].second<<"\n";
		}
	}
	
	return 0;
}