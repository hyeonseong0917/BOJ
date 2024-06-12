#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll D,N;
const ll MAX=300000+1;
ll v[MAX];
ll p[MAX];
void Input(){
	cin>>D>>N;
	for(ll i=0;i<D;++i){
		cin>>v[i];
	}
	for(ll i=0;i<N;++i){
		cin>>p[i];
	}
}
void solve(){
	for(ll i=0;i<D-1;++i){
		if(v[i]<v[i+1]){
			v[i+1]=v[i];
		}
	}
	bool flag=0;
	ll ans;
	ll idx=D-1;
	for(ll i=0;i<N;++i){
		ll cur_pizza=p[i];
		if(idx==-1){
			flag=1;
			break;
		}
		bool tmp=0;
		while(idx>=0){
			if(v[idx]>=cur_pizza){
				tmp=1;
				ans=idx;
				--idx;
				break;
			}else{
				--idx;
			}
		}
		if(!tmp){
			flag=1;
			break;
		}
		// cout<<i<<" "<<idx<<endl;
	}
	if(flag){
		cout<<0;
	}else{
		cout<<ans+1;
	}
}

int main() {
	// your code goes here
	Input();
	solve();

	return 0;
}