#include <iostream>
#include <queue>
using namespace std;

#define ll long long
ll mod=1000000007;
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
		ll sum=1;
		while(pq.size()!=1){
			ll fst_num=pq.top()*-1;
			pq.pop();
			ll sed_num=pq.top()*-1;
			pq.pop();
			ll cur_num=(fst_num*sed_num)%mod;
			sum=cur_num*(sum%mod);
			// cout<<sum<<" "<<cur_num<<endl;
			pq.push(fst_num*sed_num*-1);
		}
		sum%=mod;	
		cout<<sum<<"\n";
	}
	return 0;
}