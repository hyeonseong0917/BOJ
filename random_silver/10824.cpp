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
		string a,b,c,d;
		cin>>a;
		cin>>b;
		cin>>c;
		cin>>d;
		string m=a+b;
		string n=c+d;
		ll mm=stoll(m);
		ll nn=stoll(n);
		cout<<mm+nn;
	} 
	return 0;
}