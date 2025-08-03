#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		//1341
		// 길이 n의 문자열 s를 만들곶함.
		// 최소 며칠이 걸리는지?
		ll n;
		string s;
		cin>>n;
		cin>>s;
		stack<char> st;
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(st.empty()){
				st.push(s[i]);
			}else{
				if(st.top()!=s[i]){
					st.pop();
				}else{
					st.push(s[i]);
				}
			}
			ll sts=st.size();
			ans=max(ans,sts);
		}
		if(!st.empty()){
			cout<<-1;
		}else{
			cout<<ans;
		}
	} 
	return 0;
}