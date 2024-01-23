#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	ll arr[100000+1]={0,};
	ll psum[100000+1]={0,};
	for(ll i=0;i<100000+1;++i){
		arr[i]=0;
		psum[i]=0;
	}
	for(ll i=0;i<N;++i){
		cin>>arr[i];
		
	}
	ll sum=0;
	psum[0]=arr[0];
	
	for (ll i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + arr[i];
	}

	for (ll i = 0; i < N - 1; ++i) {
		sum += arr[i] * (psum[N - 1] - psum[i]);
	}
	cout<<sum;
	return 0;
}