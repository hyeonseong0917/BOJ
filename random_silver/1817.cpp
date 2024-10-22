#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		int cnt=1;
		int cur_size=0;
		for(ll i=0;i<n;++i){
			if(cur_size+v[i]>m){
				++cnt;
				cur_size=v[i];
			}else{
				cur_size+=v[i];
			}
		}
		if(n==0){
			cout<<0;
		}else{
			cout<<cnt;
		}
	}
	
	return 0;
}