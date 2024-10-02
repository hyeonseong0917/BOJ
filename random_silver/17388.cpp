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
		ll a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>=100){
			cout<<"OK";
		}else{
			if(a<b && a<c){
				cout<<"Soongsil";
			}
			if(b<a && b<c){
				cout<<"Korea";
			}
			if(c<a && c<b){
				cout<<"Hanyang";
			}
		}
	}
	return 0;
}