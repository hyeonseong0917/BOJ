#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	while(o--){
		vector<ll> v(5,0);
		for(ll i=0;i<5;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll diff=v[3]-v[1];
		if(diff>=4){
			cout<<"KIN"<<"\n";
		}else{
			ll sum=0;
			for(ll i=1;i<4;++i){
				sum+=v[i];
			}
			cout<<sum<<"\n";
		}

	}
	return 0;
}