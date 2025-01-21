#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

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
		stack<ll> st;
		st.push(1);
		for(ll i=1;i<n;++i){
			ll cur_num=v[i];
			stack<ll> tmp;
			while(cur_num--){
				tmp.push(st.top());
				st.pop();
			}
			st.push(i+1);
			while(!tmp.empty()){
				st.push(tmp.top());
				tmp.pop();
			}
		}
		vector<ll> ans;
		while(!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}