#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		string s;
		cin>>n;
		cin>>s;
		ll L=0, R=0;
		map<char,ll> m;
		ll cnt=0; // 현재 선택한 문자 개수
		ll ans=0;
		while(L<=R && R<s.size()){
			// cout<<L<<" "<<R<<" "<<cnt<<endl;
			if(cnt==n){
				if(m[s[R]]){
					++m[s[R]];
					ans=max(ans,R-L+1);
					++R;
				}else{
					// 못가져감
					--m[s[L]];
					if(!m[s[L]]) --cnt;
					++L;
				}
			}else{
				// cnt<n
				++m[s[R]];
				if(m[s[R]]==1){
					++cnt;
				}
				ans=max(ans,R-L+1);
				++R;
			}
			
		}
		cout<<ans;
		
	}
	return 0;
}