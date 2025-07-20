#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,p;
		cin>>a>>p;
		map<ll,ll> m;
		vector<ll> v;
		v.push_back(a);
		ll target_num=-1;
		++m[a];
		while(1){
			ll idx=v.size()-1;
			string s=to_string(v[idx]);
			// cout<<s<<endl;
			ll cur_num=0;
			for(ll i=0;i<s.size();++i){
				ll c=s[i]-'0';
				ll d=1;
				for(ll j=0;j<p;++j){
					d*=c;
				}
				cur_num+=d;
			}
			// cout<<cur_num<<" ";
			if(m[cur_num]){
				target_num=cur_num;
				break;
			}else{
				v.push_back(cur_num);
				++m[cur_num];
			}
		}
		ll ans=0;
		for(ll i=0;i<v.size();++i){
			if(v[i]==target_num) break;
			++ans;
		}
		cout<<ans;
	}
	return 0;
}