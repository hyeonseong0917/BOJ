#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll last_num;
		ll cnt=0;
		for(ll i=n-1;i>=0;--i){
			last_num=v[i];
			++cnt;
			if(cnt==k) break;
		}
		cout<<last_num;

	}
	return 0;
}