#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> g(5,0);
		for(ll i=0;i<5;++i){
			cin>>g[i];
		}
		vector<ll> v[5+1];
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		for(ll i=1;i<=5;++i){
			if(v[i].empty()) continue;
			sort(v[i].begin(),v[i].end());
		}
		ll sum=0;
		for(ll i=0;i<5;++i){
			if(!g[i]) continue;
			bool flag=0;
			for(ll j=0;j<i;++j){
				if(g[j]){
					flag=1;
					break;
				}
			}
			if(flag) sum+=60;
			for(ll j=0;j<g[i];++j){
				ll a=v[i+1][j];
				sum+=a;
				if(j!=0){
					sum+=(a-v[i+1][j-1]);
				}
			}
			// cout<<sum<<endl;
		}
		cout<<sum;
	}
	return 0;
}