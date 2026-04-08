#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> ans(n+1,0);
		ll max_num=n;
		for(ll i=n;i>=1;--i){
			if(i%2==1){
				ans[i]=max_num;
				--max_num;
			}
		}
		// 1 2 3 4 5
		// a b c d e
		// 
		for(ll i=1;i<=n;++i){
			if(i%2==0){
				ans[i]=max_num--;
			}
		}
		for(ll i=1;i<=n;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}