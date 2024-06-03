#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long

ll N;
void Input(){
	cin>>N;
	for(ll i=0;i<N;++i){
		ll a=0;
		for(ll j=0;j<N;++j){
			ll b;
			cin>>b;
			a|=b;
		}
		cout<<a<<" ";
	}
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	
	return 0;
}