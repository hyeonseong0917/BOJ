#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll s;
		cin>>s;
		for(ll i=0;i<n;++i){
			if(s==0) break;
			ll max_num=-1;
			ll max_idx=-1;
			for(ll j=i+1;j<=min(i+s,n-1);++j){
				if(max_num<v[j]){
					max_num=v[j];
					max_idx=j;
				}
			}
			if(max_num<v[i]) continue;
			ll tmp=v[i];
			v[i]=max_num;
			for(ll j=max_idx;j>i+1;--j){
				v[j]=v[j-1];
			}
			v[i+1]=tmp;
			s-=(max_idx-i);
		}
		for(ll i=0;i<n;++i){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}