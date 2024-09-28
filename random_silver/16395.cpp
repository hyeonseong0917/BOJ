#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

ll c(ll n, ll k){
	if(k==1) return n;
	if(n==1 || n==k || k==0) return 1;
	return c(n-1,k)+c(n-1,k-1);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		cout<<c(n-1,k-1);
	}
	return 0;
}