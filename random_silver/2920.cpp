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
		vector<ll> v(8,0);
		for(ll i=0;i<8;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(ll i=1;i<7;++i){
			if(v[i]<v[i-1] && v[i]<v[i+1]){
				flag=1;
			}
			if(v[i]>v[i-1] && v[i]>v[i+1]){
				flag=1;
			}
		}
		if(flag){
			cout<<"mixed";
		}else{
			if(v[0]<v[1]){
				cout<<"ascending";
			}else{
				cout<<"descending";
			}
		}

	} 
	return 0;
}