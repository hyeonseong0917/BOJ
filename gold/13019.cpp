#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		string a,b;
		cin>>a;
		cin>>b;
		ll n=a.size();
		vector<ll> a_check(26,0),b_check(26,0);
		for(ll i=0;i<n;++i){
			++a_check[a[i]-'A'];
			++b_check[b[i]-'A'];
		}
		bool flag=0;
		for(ll i=0;i<26;++i){
			if(a_check[i]!=b_check[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1;
			continue;
		}
		ll ans=0;
		ll idx=n-1;
		for(ll i=n-1;i>=0;--i){
			if(a[i]==b[idx]){
				--idx;
			}else{
				++ans;
			}
		}
		cout<<ans;

	}	
	return 0;
}