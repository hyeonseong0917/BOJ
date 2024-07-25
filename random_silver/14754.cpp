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
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		ll arr[n+1][m+1];		
		ll sum=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>arr[i][j];
				sum+=arr[i][j];
			}
		}
		map<ll,ll> check;
		ll cur_sum=0;
		for(ll i=0;i<m;++i){
			ll max_num=0;
			for(ll j=0;j<n;++j){
				max_num=max(max_num,arr[j][i]);
			}
			check[max_num]=1;
			cur_sum+=max_num;
		}

		for(ll i=0;i<n;++i){
			ll max_num=0;
			for(ll j=0;j<m;++j){
				max_num=max(max_num,arr[i][j]);
			}
			if(!check[max_num]){
				check[max_num]=1;
				cur_sum+=max_num;
			}
		}
		cout<<sum-cur_sum;
	}
	
	return 0;
}