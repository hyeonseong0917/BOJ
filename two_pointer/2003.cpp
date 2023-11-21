#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<ll> v;
ll dp[10000+1];
ll N,M;
void Input(){
	cin>>N>>M;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
	}
}
void solve(){
	ll res=0;
	for(int i=0;i<N;++i){
		ll cur_sum=0;
		for(int j=i;j<N;++j){
			cur_sum+=v[j];
			if(cur_sum==M){
				++res;
				break;
			}
		}
	}
	cout<<res;
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();	
	
	
	return 0;
}