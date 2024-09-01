#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll cnt=0;
		while(L<R){
			// cout<<L<<" "<<R<<" "<<v[L]<<" "<<v[R]<<endl;
			if(v[L]+v[R]==m){
				++L;
				--R;
				// cout<<"fsd"<<L<<" "<<R<<endl;
				++cnt;
			}else{
				if(v[L]+v[R]>m){
					--R;
				}else if(v[L]+v[R]<m){
					++L;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}