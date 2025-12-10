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
		string s;
		cin>>s;
		ll n=s.size();
		ll idx=0, ans=0, state=0;
		while(idx<n){
			// cout<<idx<<"\n";
			ll cur_state=1;
			if('a'<=s[idx] && s[idx]<='z'){
				cur_state=0;
			}
			if(state==cur_state){
				++ans;
				++idx;
			}else{
				// state와 cur_state가 다른상태임
				if(idx+1==n){
					ans+=2;
					break;
				}else{
					ll next_state=1;
					if('a'<=s[idx+1] && s[idx+1]<='z'){
						next_state=0;
					}
					if(state==next_state){
						ans+=2;
						++idx;
					}else{
						state=next_state;
						++ans;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}