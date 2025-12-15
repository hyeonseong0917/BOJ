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
		// 0114
		string s;
		cin>>s;
		// 1. 노는 ) 괄호가 몇개인지?
		stack<char> st;
		ll fst_cnt=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]==')'){
				if(st.empty()){
					++fst_cnt;
				}else{
					st.pop();
				}
			}else{
				st.push(s[i]);
			}
		}
		// 2. 노는 (괄호가 몇 개인지?
		stack<char> ts;
		ll sed_cnt=0;
		for(ll i=s.size()-1;i>=0;--i){
			if(s[i]=='('){
				if(ts.empty()){
					++sed_cnt;
				}else{
					ts.pop();
				}
			}else{
				ts.push(s[i]);
			}
		}
		cout<<fst_cnt+sed_cnt;
		return 0;
	} 
	return 0;
}