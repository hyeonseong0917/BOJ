#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// a: 300, b: 60, c: 10
		ll t;
		cin>>t;
		ll a=t/300;
		t%=300;
		ll b=t/60;
		t%=60;
		ll c=t/10;
		t%=10;
		if(t!=0){
			cout<<-1;
		}else{
			cout<<a<<" "<<b<<" "<<c;
		}

	}
	

	

	return 0;
}