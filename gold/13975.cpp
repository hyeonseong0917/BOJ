#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll N;
		cin>>N;
		priority_queue<ll> pq;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			pq.push(a*-1);
		}
		ll sum=0;
		while(!pq.empty()){
			if(pq.size()==1){
				break;
			}
			ll a=pq.top()*-1;
			pq.pop();
			ll b=pq.top()*-1;
			pq.pop();
			sum+=(a+b);
			pq.push((a+b)*-1);
		}
		cout<<sum<<"\n";
	}
	return 0;
}