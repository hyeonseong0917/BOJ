#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		map<string,string> check;
		for(ll i=0;i<n;++i){
			string a,b;
			cin>>a;
			cin>>b;
			check[a]=b;
		}
		for(ll i=0;i<m;++i){
			string a;
			cin>>a;
			cout<<check[a]<<"\n";
		}
	}
	return 0;
}