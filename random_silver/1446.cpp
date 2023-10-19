#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

vector<pair<pair<int,int>,int>> v;
int N,D;

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	return a.first.second<b.first.second;
}

const int MAX=10000+5;
int dp[MAX];
void Input(){
	cin>>N>>D;
	for(int i=0;i<N;++i){
		int s,f,l;
		cin>>s>>f>>l;
		v.push_back({{s,f},l});
	}
	for(int i=0;i<MAX;++i){
		dp[i]=i;
	}
	sort(v.begin(),v.end(),comp);
}
int ans=122232421;
// void pick(int idx, int cur_pos, int cur_cost){
// 	// cout<<cur_pos<<" "<<D<<"  "<<cur_cost<<endl;
// 	ans=min(ans,cur_cost+D-cur_pos);
// 	if(idx==N){
// 		return;
// 	}
// 	for(int i=idx;i<v.size();++i){
// 		if(v[i].first.first<cur_pos) continue;
// 		//v[i]번째 지름길 사용 x
// 		pick(idx+1,cur_pos,cur_cost);

// 		//v[i]번쨰 지름길 사용
// 		if(v[i].first.second>D) continue;
// 		pick(idx+1,v[i].first.second,cur_cost+(v[i].first.first-cur_pos)+v[i].second);
// 	}
// }
// 270+28+140
void solve(){
	// pick(0,0,0);
	// dp[i]: i까지 가려는 최소비용
	// dp[i]=min(dp[i],)
	for(int i=0;i<N;++i){
		int start_pos=v[i].first.first;
		int finish_pos=v[i].first.second;
		int cost=v[i].second;
		for(int j=0;j<=start_pos;++j){
			dp[start_pos]=min(dp[start_pos],dp[start_pos-j]+j);
		}
		dp[finish_pos]=min(dp[finish_pos],dp[start_pos]+cost);
		// cout<<finish_pos<<" "<<dp[start_pos]+cost<<endl; 

		for(int j=0;j<=finish_pos;++j){
			dp[finish_pos]=min(dp[finish_pos],dp[finish_pos-j]+j);
		}
	}
	for(int i=0;i<=D;++i){
		ans=min(ans,dp[D-i]+i);
	}
	cout<<ans;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}