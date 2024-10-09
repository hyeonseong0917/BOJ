#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

ll n,k;
vector<ll> v;
bool check[20+1];
vector<ll> tmp;
ll fact(ll num){
	if(num<=1) return 1;
	return num*fact(num-1);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		ll num;
		cin>>num;
		vector<ll> ans(n+1,0);
		if(num==1){
			cin>>k;
			// k번째 수열?
			for(ll i=0;i<n-1;++i){
				ll cnt=0;
				for(ll j=1;j<=20;++j){
					if(check[j]) continue;
					cnt+=fact(n-1-i);
					if(cnt<k) continue;
					if(cnt>=k){
						k-=(cnt-fact(n-1-i));
						check[j]=1;
						ans[i]=j;
						break;
					}
				}
			}
			for(ll i=1;i<=n;++i){
				if(!check[i]){
					ans[n-1]=i;
					break;
				}
			}
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<" ";
			}
		}else{
			for(ll i=0;i<n;++i){
				ll a;
				cin>>a;
				v.push_back(a);
			}
			// 이게 몇 번째 순열?
			if(n==1){
				cout<<1;
			}else{
				ll cnt=1;
				for(ll i=0;i<n-1;++i){
					ll not_used=0;
					for(ll j=1;j<v[i];++j){
						if(!check[j]){
							++not_used;
						}
					}
					cnt+=not_used*fact(n-1-i);
					check[v[i]]=1;
				}
				cout<<cnt;
			}
			
		}
	}
	return 0;
}