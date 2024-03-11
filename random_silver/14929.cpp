#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
ll psum[100000+1];
vector<ll> v;
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	for(ll i=0;i<N;++i){
		psum[i]=0;
	}
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		v.push_back(a);
	}
	psum[N-1]=v[N-1];
	for(ll i=N-2;i>=0;--i){
		psum[i]=psum[i+1]+v[i];
	}
	ll sum=0;
	for(ll i=0;i<N-1;++i){
		sum+=v[i]*psum[i+1];
	}
	cout<<sum;
	
	

	return 0;
}