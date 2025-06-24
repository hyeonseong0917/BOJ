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
		ll n;
		cin>>n;
		vector<ll> v(n-1,0);
		ll c;
		for(ll i=0;i<n;++i){
			if(i==0){
				cin>>c;
			}else{
				cin>>v[i-1];
			}
		}
		if(n==2){
			if(c<=v[0]){
				cout<<"No";
			}else{
				cout<<"Yes";
			}
			break;
		}
		// cout<<c<<endl;
		sort(v.begin(),v.end());
		
		bool flag=0;
		for(ll i=0;i<n-1;++i){
			if(v[i]>=c){
				flag=1;
				break;
			}else{
				c+=v[i];
			}
			// cout<<i<<" "<<c<<endl;
		}
		if(flag){
			cout<<"No";
		}else{
			cout<<"Yes";
		}

	} 
	return 0;
}