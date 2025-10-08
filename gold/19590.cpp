#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<v[0];
			break;
		}
		sort(v.begin(),v.end());
		ll psum=0;
		for(ll i=0;i<n-1;++i){
			psum+=v[i];
		}
		ll max_num=v[n-1];
		if(max_num>=psum){
			max_num-=psum;
			cout<<max_num;
		}else{
			// max_num<psum
			if((psum+max_num)%2==0){
				cout<<0;
			}else{
				cout<<1;
			}
		}
		// [4,5,8,10,12]
		// [4,5,8,8,10,12]

		// [4,4,7,10,12]
		// [4,4,4,7,12]
		// [4,4,4,4,9]
		// [3,3,3,3,5]
		// [2,3,3,3,4]
		// [2,2,3,3,3]
		// [2,2,2,2,3]
		// [1,2,2,2,2]
		// [1,1,1,1,1]
		// [1,0,0,0,0]

		// [3,3,3,3,20]
		
		
	}
	return 0;
}