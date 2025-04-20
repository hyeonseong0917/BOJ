#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(a<=b){
			cout<<"NO"<<"\n";
		}else{
			ll c=a-2*(a-b);
			ll d=b-(a-b);
			if(d!=c || d<0 || c<0){
				cout<<"NO"<<"\n";
				continue;
			}
			cout<<"YES"<<"\n";
			cout<<a-b<<"\n";
			
			for(ll i=0;i<a-b;++i){
				cout<<"aba";
				if(i==0){
					for(ll j=0;j<d;++j){
						cout<<"ba";
					}
				}
				cout<<"\n";
			}
		}
	} 
	return 0;
}