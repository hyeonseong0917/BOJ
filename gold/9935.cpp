#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define ll long long

ll n;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string s,t;
		cin>>s;
		cin>>t;
		ll ts=t.size();
		stack<char> st;
		for(ll i=0;i<s.size();++i){
			st.push(s[i]);
			if(st.size()<ts) continue;
			string tmp="";
			for(ll j=0;j<ts;++j){
				tmp+=st.top();
				st.pop();
			}
			reverse(tmp.begin(),tmp.end());
			// cout<<i<<" "<<tmp<<endl;
			if(!tmp.compare(t)) continue;
			for(ll j=0;j<ts;++j){
				st.push(tmp[j]);
			}
		}
		string ans="";
		while(!st.empty()){
			ans+=st.top();
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		if(!ans.compare("")){
			cout<<"FRULA";
		}else{
			cout<<ans;
		}
		
	}
	return 0;
}