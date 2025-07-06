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
		string s,t;
		cin>>s;
		cin>>t;
		queue<ll> q[26+1];
		for(ll i=0;i<s.size();++i){
			ll c=s[i]-'a';
			q[c].push(i);
		}
		ll ans=0;
		bool flag=0;
		while(!flag){
			ll last_idx=-1;
			for(ll i=0;i<t.size();++i){
				char c=t[i];
				if(q[c-'a'].empty()){
					flag=1;
					break;
				}else{
					bool is_exist=0;
					while(!q[c-'a'].empty()){
						ll k=q[c-'a'].front();
						if(k>last_idx){
							is_exist=1;
							last_idx=k;
							q[c-'a'].pop();
							break;
						}else{
							q[c-'a'].pop();
						}
					}
					if(!is_exist){
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				++ans;
			}
		}
		cout<<ans;
	}
	return 0;
}