#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;	
	while(t--){	
		ll a,b;
		cin>>a>>b;
		cout<<a+b<<"\n";
		cout<<a-b<<"\n";
		cout<<a*b;
	}
	return 0;
}