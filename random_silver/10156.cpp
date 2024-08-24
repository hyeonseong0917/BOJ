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
	while(o--){
		
		ll k,n,m;
		cin>>k>>n>>m;
		ll ans=0;
		cout<<max(ans,k*n-m);
	}
	return 0;
}