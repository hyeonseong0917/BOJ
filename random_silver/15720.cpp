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
		ll b,c,d;
		cin>>b>>c>>d;
		vector<ll> B,C,D;
		ll fst_sum=0;
		ll sed_sum=0;
		for(ll i=0;i<b;++i){
			ll s;
			cin>>s;
			fst_sum+=s;
			B.push_back(s);
		}
		for(ll i=0;i<c;++i){
			ll s;
			cin>>s;
			fst_sum+=s;
			C.push_back(s);
		}
		for(ll i=0;i<d;++i){
			ll s;
			cin>>s;
			fst_sum+=s;
			D.push_back(s);
		}
		sort(B.rbegin(),B.rend());
		sort(C.rbegin(),C.rend());
		sort(D.rbegin(),D.rend());
		ll min_size=min(b,min(c,d));
		ll max_size=max(b,max(c,d));
		for(ll i=0;i<min_size;++i){
			sed_sum+=((B[i]+C[i]+D[i])*9)/10;
		}
		for(ll i=min_size;i<max_size;++i){
			if(i<b){
				sed_sum+=B[i];
			}
			if(i<c){
				sed_sum+=C[i];
			}
			if(i<d){
				sed_sum+=D[i];
			}
		}
		cout<<fst_sum<<"\n";
		cout<<sed_sum<<"\n";
	}
	return 0;
}