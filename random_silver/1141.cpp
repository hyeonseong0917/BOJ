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
		// 다른 단어가 접두어 x
		// 접두어 x부분집합의 최대 크기
		ll n;
		cin>>n;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.pb(s);
		}
		vector<bool> check(n,0);
		for(ll i=0;i<n;++i){
			string cur_str=v[i];
			ll cs=cur_str.size();
			// cur_str의 접두어가 존재하는지?
			for(ll j=0;j<n;++j){
				if(i==j) continue;
				string next_str=v[j];
				ll ns=next_str.size();
				if(cs>=ns) continue;
				string part_next_str=next_str.substr(0,cs);
				if(part_next_str.compare(cur_str)==0){
					check[i]=1;
					break;
				}
			}
		}
		map<string,ll> m;
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(!check[i]){
				if(!m[v[i]]){
					m[v[i]]=1;
					++ans;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}