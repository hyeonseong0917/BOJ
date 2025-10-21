#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 0 1 2 3 4 5
		// 1 4 3 5 6 2
		// 1 2 3 4 5 6
		// 6 1 5 2 4 3

		// 3 4 5
		// 5 3 4
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		vector<ll> tmp;
		while(L<=R){
			if(L==R){
				tmp.push_back(v[R]);
				break;
			}
			tmp.push_back(v[R]);
			--R;
			tmp.push_back(v[L]);
			++L;
		}
		ll ans=tmp[0];
		for(ll i=2;i<n;i+=2){
			ans+=tmp[i]-tmp[i-1];
		}
		cout<<ans;
	}
	return 0;
}