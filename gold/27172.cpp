#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(1000000+1,0);
		vector<ll> tmp(1000000+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++tmp[v[i]];
		}
		// 3 4 12
		// i번째 플레이어는 몇 점을 얻을까?
		// i번째 수의 배수 개수만큼 +1
		// i번째 수의 약수 개수만큼 -1

		// i번째 수에 대해 배수라면 i번째 수 +1, 해당 배수는 -1
		for(ll i=0;i<n;++i){
			// v[i]에 대해서 
			for(ll j=2;v[i]*j<=1000000;++j){
				if(tmp[v[i]*j]){
					// cout<<v[i]<<" "<<v[i]*j<<endl;
					++check[v[i]];
					--check[v[i]*j];
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<check[v[i]]<<" ";
		}
	}
	return 0;
}