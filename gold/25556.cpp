#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define ll long long

int main() {
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
		stack<ll> st[4+1];
		bool can_clean=1;
		for(ll i=0;i<n;++i){
			bool flag=0;
			ll max_idx=-1;
			ll max_num=-1;
			for(ll j=0;j<4;++j){
				if(st[j].empty()){
					flag=1;
				}else{
					if(v[i]>st[j].top()){
						if(max_num<st[j].top()){
							max_num=st[j].top();
							max_idx=j;
						}
					}
				}
			}
			// cout<<i<<" "<<max_idx<<endl;
			if(!flag && max_idx==-1){
				can_clean=0;
				break;
			}
			if(max_idx==-1){
				for(ll j=0;j<4;++j){
					if(st[j].empty()){
						st[j].push(v[i]);
						break;
					}
				}
			}else{
				st[max_idx].push(v[i]);
			}
		}
		if(can_clean){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	return 0;
}