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
	int o;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		ll min_num=100;
		ll max_num=0;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			min_num=min(min_num,a);
			max_num=max(max_num,a);
		}
		cout<<(max_num-min_num)*2<<"\n";


	}
	return 0;
}