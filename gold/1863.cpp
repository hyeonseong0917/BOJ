#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		ll ans=0;
		ll cnt=0;
		stack<ll> st;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(b==0){
				while(!st.empty()){
					st.pop();
					++cnt;
				}
				continue;
			}
			if(st.empty()){
				st.push(b);
			}else{
				ll s=st.top();
				if(s>b){
					while(!st.empty()){
						ll s=st.top();
						if(s>b){
							st.pop();
							++cnt;
						}else{
							break;
						}
					}
				}
				if(st.empty() || st.top() < b){
					st.push(b);
				}
			}
			// ll ss=st.size();
			// cout<<i<<" "<<ss<<endl;
		}
		// ll ss=st.size();
		// cout<<ss<<endl;
		while(!st.empty()){
			ll s=st.top();
			if(s>0){
				st.pop();
				++cnt;
			}else{
				break;
			}
		}
		cout<<cnt;
	}
	return 0;
}