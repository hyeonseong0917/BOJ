#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long
ll ans=0;
ll n,k;
vector<ll> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		n,k;
		cin>>n>>k;
		v=vector<ll>(n,0);
		ans=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		
		sort(v.begin(),v.end());
		// -7 9 2 -4 12 1 5 -3 -2 0
		ll min_diff=2023101800;
		for(ll i=0;i<n;++i){
			ll cur_num=v[i];
			ll L=i+1, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(cur_num+v[mid]>k){
					min_diff=min(min_diff,cur_num+v[mid]-k);
					R=mid-1;
				}else if(cur_num+v[mid]<k){
					min_diff=min(min_diff,k-(cur_num+v[mid]));
					L=mid+1;
				}else{
					min_diff=0;
					break;
				}
			}
		}
		// 1. k+min_diff
		for(ll i=0;i<n;++i){
			ll cur_num=v[i];
			ll L=i+1, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]+cur_num>k+min_diff){
					R=mid-1;
				}else if(v[mid]+cur_num<k+min_diff){
					L=mid+1;
				}else{
					++ans;
					break;
				}
			}
		}
		if(min_diff){
			for(ll i=0;i<n;++i){
				ll cur_num=v[i];
				ll L=i+1, R=n-1;
				while(L<=R){
					ll mid=(L+R)/2;
					if(v[mid]+cur_num>k-min_diff){
						R=mid-1;
					}else if(v[mid]+cur_num<k-min_diff){
						L=mid+1;
					}else{
						++ans;
						break;
					}
				}
			}	
		}
		cout<<ans<<"\n";
	}
	return 0;
}