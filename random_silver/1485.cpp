#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
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
		vector<pair<ll,ll>> v;
		for(ll i=0;i<4;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		bool flag=0;
		vector<ll> p;
		for(ll i=0;i<v.size();++i){
			for(ll j=i+1;j<v.size();++j){
				// i와 j 사이의 거리
				p.push_back(abs(v[j].first-v[i].first)+abs(v[j].second-v[i].second));
			}
		}
		sort(p.begin(),p.end());
		if(p[4]!=p[5]){
			flag=1;
		}
		for(ll i=1;i<4;++i){
			if(p[i]!=p[0]){
				flag=1;
			}
		}
		if(!flag){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}