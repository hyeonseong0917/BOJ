#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		stack<pair<ll,ll>> st;
		ll ans=0;
		for(ll i=n-1;i>=0;--i){
			if(st.empty()){
				st.push({v[i],0});
			}else{
				// st에서 v[i]보다 작은거+1
				ll cnt=0;
				while(!st.empty()){
					ll cur_num=st.top().first;
					ll cur_cnt=st.top().second;
					if(cur_num<v[i]){
						st.pop();
						cnt+=cur_cnt+1;
					}else{
						break;
					}
				}
				st.push({v[i],cnt});
				ans+=cnt;
			}
		}
		cout<<ans;
	}
	return 0;
}