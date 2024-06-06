#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int n;
		cin>>n;
		vector<ll> a(n,0),b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		if(n==1){
			if(a[0]<b[0]){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
			break;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll cnt=0;
		ll idx=-1;
		for(ll i=0;i<n;++i){
			if(idx==n) break;
			if(idx==-1){
				for(ll j=0;j<n;++j){
					// cout<<a[j]<<" "<<b[j]<<endl;
					if(a[i]<b[j]){
						idx=j;
						break;
					}
				}
				// cout<<idx<<endl;
				if(idx==-1){
					break;
				}else{
					++idx;
					++cnt;
				}
			}else{
				if(a[i]<b[idx]){
					++idx;
					++cnt;
				}else{
					// a[i]>=b[idx]
					while(idx<n){
						++idx;
						if(a[i]<b[idx] && idx<n){
							++idx;
							++cnt;
							break;
						}
					}
				}
			}
			// cout<<i<<" "<<cnt<<endl;
		}
		// cout<<cnt;
		// 1 2 3 5 6
		// 1 1 2 3 5
		// 1 3 10 10 10
		// 2 2 2 4 6
		if(cnt>=(n+1)/2){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	

	

	return 0;
}