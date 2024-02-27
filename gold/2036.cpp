#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define ll long long




int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll N;
	cin>>N;
	priority_queue<ll> mq,pq;
	for(ll i=0;i<N;++i){
		ll a=0;
		cin>>a;
		if(a<=0){
			mq.push(a*-1);
		}else{
			pq.push(a);
		}
	}
	ll sum=0;
	while(!mq.empty()){
		if(mq.size()>=2){
			ll fst_num=mq.top();
			mq.pop();
			ll sed_num=mq.top();
			mq.pop();
			sum+=(fst_num*sed_num);
		}
		if(mq.size()==1){
			sum+=(mq.top()*-1);
			mq.pop();
		}
	}
	while(!pq.empty()){
		if(pq.size()>=2){
			ll fst_num=pq.top();
			pq.pop();
			ll sed_num=pq.top();
			pq.pop();
			sum+=max(fst_num+sed_num,fst_num*sed_num);
		}
		if(pq.size()==1){
			sum+=pq.top();
			pq.pop();
		}
	}
	cout<<sum;
	

	return 0;
}