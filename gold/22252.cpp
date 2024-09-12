#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll q;
		cin>>q;
		ll ans=0;
		map<string,ll> m;
		ll cnt=1;
		priority_queue<ll> pq[100000+1];
		while(q--){
			ll a;
			cin>>a;
			if(a==1){
				string s;
				cin>>s;
				if(!m[s]){
					m[s]=cnt++;
				}
				ll n;
				cin>>n;
				for(ll i=0;i<n;++i){
					ll k;
					cin>>k;
					pq[m[s]].push(k);
				}
			}else{
				string s;
				cin>>s;
				ll cur_num=m[s];
				ll add_cnt;
				cin>>add_cnt;
				while(add_cnt && !pq[cur_num].empty()){
					ans+=pq[cur_num].top();
					pq[cur_num].pop();
					--add_cnt;
				}
			}

		}
		cout<<ans;

	}
	return 0;
}