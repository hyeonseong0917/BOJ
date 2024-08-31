#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> A(n+1,0);
		map<pair<ll,ll>,ll> m;
		for(ll i=0;i<n;++i){
			cin>>A[i];
			m[{A[i],i}]=1;
		}
		ll M;
		cin>>M;
		
		for(ll i=0;i<M;++i){
			ll a;
			cin>>a;
			if(a==2){
				cout<<m.begin()->first.second+1<<"\n";
			}else{
				ll index,v;
				cin>>index>>v;
				--index;
				auto it=m.find({A[index],index});
				m.erase(it);
				A[index]=v;
				m[{v,index}]=1;
			}
		}
	}
	return 0;
}