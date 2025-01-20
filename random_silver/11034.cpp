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
	ll o=1;	
	while(o--){	
		ll a,b,c;
		while(cin>>a>>b>>c){
			cout<<max(b-a,c-b)-1<<"\n";
		}
	}
	return 0;
}