#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int N;
vector<pair<int,int>> egg;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		// 내구도, 무게
		egg.push_back({a,b});
	}
}
int max_cnt=0;
void pick(int cur_idx){
	// cout<<cur_idx<<endl;
	if(cur_idx==N){
		// for(int i=0;i<egg.size();++i){
		// 	cout<<egg[i].first<<" ";
		// }cout<<endl;
		int cnt=0;
		for(int i=0;i<egg.size();++i){
			if(egg[i].first<=0){
				++cnt;
			}
		}
		max_cnt=max(max_cnt,cnt);
		return;
	}
	if(egg[cur_idx].first<=0){
		pick(cur_idx+1);
	}else{
		bool flag=0;
		for(int i=0;i<N;++i){
			if(i==cur_idx) continue;
			if(egg[i].first>0){
				flag=1;
				egg[i].first-=egg[cur_idx].second;
				egg[cur_idx].first-=egg[i].second;
				pick(cur_idx+1);
				egg[i].first+=egg[cur_idx].second;
				egg[cur_idx].first+=egg[i].second;
			}
		}	
		if(!flag){
			pick(cur_idx+1);
		}
	}
	
}
void solve(){
	pick(0);
	cout<<max_cnt;
}

int main() {
	// your code goes here
	Input();
	solve();

	return 0;
}