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
		ll a,b,c;
		cin>>a>>b>>c;
		if(a+b==c){
			cout<<a<<"+"<<b<<"="<<c;
			break;
		}
		if(a-b==c){
			cout<<a<<"-"<<b<<"="<<c;
			break;
		}
		if(a*b==c){
			cout<<a<<"*"<<b<<"="<<c;
			break;
		}
		if(a==b+c){
			cout<<a<<"="<<b<<"+"<<c;
			break;
		}
		if(a==b-c){
			cout<<a<<"="<<b<<"-"<<c;
			break;
		}
		if(a==b*c){
			cout<<a<<"="<<b<<"*"<<c;
			break;
		}
		if(a==b/c){
			if(a*c==b){
				cout<<a<<"="<<b<<"/"<<c;
				break;
			}
		}
		if(a/b==c){
			if(a==b*c){
				cout<<a<<"="<<b<<"*"<<c;
				break;
			}
		}
		
	} 

	return 0;
}