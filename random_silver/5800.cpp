#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll k;
		cin>>k;
		for(ll i=0;i<k;++i){
			ll n;
			cin>>n;
			vector<ll> tmp(n,0);
			ll max_gap=-1;
			for(ll j=0;j<n;++j){
				cin>>tmp[j];
				
			}
			
			cout<<"Class "<<i+1<<"\n";
			sort(tmp.begin(),tmp.end());
			reverse(tmp.begin(),tmp.end());
			for(ll j=1;j<n;++j){
				max_gap=max(max_gap,abs(tmp[j]-tmp[j-1]));
			}
			cout<<"Max "<<tmp[0]<<", "<<"Min "<<tmp[n-1]<<", Largest gap "<<max_gap<<"\n";
		}
	}
	return 0;
}