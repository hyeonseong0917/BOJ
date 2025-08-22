#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,a,d;
		cin>>n>>a>>d;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// sort(v.begin(),v.end());
		ll cur_num=-1;
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(cur_num==-1){
				if(v[i]==a){
					++ans;
					cur_num=v[i];
				}
			}else{
				if(v[i]==cur_num+d){
					cur_num+=d;
					++ans;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}