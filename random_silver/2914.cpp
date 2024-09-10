#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b;
		cin>>a>>b;
		cout<<(a*(b-1))+1;
	}

	return 0;
}