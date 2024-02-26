#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> v;
map<ll,ll> m;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll sum=0;
	ll cnt=1;
	for(ll i=0;i<v.size();++i){
		if(v[i]==cnt){
			++m[v[i]];
		}else{
			if(m[cnt]){
				if(v[i]==cnt+1){
					++m[cnt+1];
					++cnt;
				}else{
					sum+=(v[i]-(cnt+1));
					++m[cnt+1];
					++cnt;
				}
			}else{
				sum+=(v[i]-cnt);
				++m[cnt];
			}
		}
		
	}
	cout<<sum;
	return 0;
}