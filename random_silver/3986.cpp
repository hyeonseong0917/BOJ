#include <iostream>
#include <algorithm>
#include <vector>
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
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		ll cnt=0;
		for(ll i=0;i<n;++i){
			stack<char> st;
			string cur_str=v[i];
			for(ll j=0;j<cur_str.size();++j){
				if(st.empty()){
					st.push(cur_str[j]);
				}else{
					if(st.top()==cur_str[j]){
						st.pop();
					}else{
						st.push(cur_str[j]);
					}
				}
			}
			if(st.empty()){
				++cnt;
			}
		}
		cout<<cnt;
			
	}
	return 0;
}