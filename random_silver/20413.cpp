#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

vector<ll> price(4,0);
ll calc(char c){
	if(c=='S'){
		return price[1];
	}else if(c=='G'){
		return price[2];
	}else if(c=='P'){
		return price[3];
	}else if(c=='B'){
		return price[0];
	}
	return 0;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		for(ll i=0;i<4;++i){
			cin>>price[i];
		}
		string s;
		cin>>s;
		vector<ll> v(n,0);
		ll sum=0;
		if(s[0]!='D'){
			sum=calc(s[0])-1;
			v[0]=calc(s[0])-1;
		}else{
			sum=price[3];
			v[0]=price[3];
		}
		
		for(ll i=1;i<n;++i){
			if(s[i]=='D'){
				sum+=price[3];
			}else{
				ll cur_num=calc(s[i])-1;
				sum+=(cur_num-v[i-1]);
				v[i]=cur_num-v[i-1];
			}
		}
		cout<<sum;
	}
	return 0;
}