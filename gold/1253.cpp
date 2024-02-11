#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll N;
vector<ll> v;
map<ll,ll> m;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	ll zero_cnt=0;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
		if(a==0){
			++zero_cnt;
		}
	}
	sort(v.begin(),v.end());
	ll cnt=0;
	for(ll i=0;i<N;++i){
		ll L=0, R=N-1;
		while(L<R){
			if(v[L]+v[R]>v[i]){
				--R;
			}else if(v[L]+v[R]<v[i]){
				++L;
			}else{
				if(L!=i && R!=i){
					++cnt;
					break;
				}else{
					if(L==i){
						++L;
					}else{
						--R;
					}
				}
			}
		}
	}
	
	cout<<cnt;
	
	return 0;
}