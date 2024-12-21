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
	ll t=1;	
	cin>>t;
	while(t--){	
		ll J,N;
		cin>>J>>N;
		vector<ll> v;
		for(ll i=0;i<N;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back(a*b);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<v.size();++i){
			J-=v[i];
			if(J<=0){
				ans=i+1;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}