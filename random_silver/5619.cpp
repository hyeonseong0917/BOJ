#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

bool comp(string a, string b){
	if(a.size()==b.size()){
		return a<b;
	}
	return a.size()<b.size();
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(10000+1,0);
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			++v[a];
		}
		vector<ll> tmp;
		for(ll i=1;i<=10000;++i){
			if(v[i]){
				ll ts=tmp.size();
				if(ts==4){
					break;
				}
				tmp.push_back(i);
			}
		}
		vector<string> c;
		for(ll i=0;i<tmp.size();++i){
			for(ll j=0;j<tmp.size();++j){
				if(i==j) continue;
				c.push_back(to_string(tmp[i])+to_string(tmp[j]));
			}
			
		}
		// for(ll i=0;i<c.size();++i){
		// 	cout<<c[i]<<endl;
		// }
		sort(c.begin(),c.end(),comp);
		cout<<c[2];

	} 
	return 0;
}