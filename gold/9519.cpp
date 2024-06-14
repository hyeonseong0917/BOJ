#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ll o=1;
	while(o--){
		ll n,x;
		cin>>x;
		string s;
		cin>>s;
		n=s.size();
		string origin_str=s;
		ll cnt=0;
		while(1){
			ll L=0, R=n-1;
			string t="";
			for(ll i=0;i<n;++i){
				if(i%2==0){
					t+=s[L++];
				}else{
					t+=s[R--];
				}
				if(t.size()==n){
					break;
				}
			}
			for(ll i=0;i<n;++i){
				s[i]=t[i];
			}
			++cnt;
			if(s.compare(origin_str)==0){
				break;
			}
		}
		
		// cout<<cnt;
		x%=cnt;
		cnt-=x;
		while(cnt--){
			ll L=0, R=n-1;
			string t="";
			for(ll i=0;i<n;++i){
				if(i%2==0){
					t+=s[L++];
				}else{
					t+=s[R--];
				}
				if(t.size()==n){
					break;
				}
			}
			for(ll i=0;i<n;++i){
				s[i]=t[i];
			}
		}
		cout<<s;
	}

	return 0;
}