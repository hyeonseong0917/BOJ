#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

vector<ll> is_prime(5000000+1,1);
// check[i]=1; 소수가 아님

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		is_prime[1]=0;
		is_prime[0]=0;
		for(ll i=2;i*i<=5000000;++i){
			if(!is_prime[i]) continue;
			for(ll j=i*i;j<=5000000;j+=i){
				is_prime[j]=0;
			}
		}
		ll n;
		cin>>n;
		vector<ll> check(5000000+1,0);
		ll fst_sum=0;
		ll sed_sum=0;
		priority_queue<ll> fst_pq, sed_pq;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			// a는 대웅
			// b는 규성
			
			// 1. a처리
			if(!is_prime[a]){
				// 소수가 아니라면?
				ll ps=sed_pq.size();
				if(ps<3){
					sed_sum+=1000;
				}else{
					ll fst_num=sed_pq.top();
					sed_pq.pop();
					ll sed_num=sed_pq.top();
					sed_pq.pop();

					sed_sum+=sed_pq.top();

					sed_pq.push(fst_num);
					sed_pq.push(sed_num);
				}
			}else{
				// 소수긴함
				if(check[a]){
					fst_sum-=1000;
				}else{
					++check[a];
					fst_pq.push(a);
				}
			}
			// 2. b처리
			if(!is_prime[b]){
				// 소수가 아니라면?
				ll ps=fst_pq.size();
				if(ps<3){
					fst_sum+=1000;
				}else{
					ll fst_num=fst_pq.top();
					fst_pq.pop();
					ll sed_num=fst_pq.top();
					fst_pq.pop();
					fst_sum+=fst_pq.top();
					fst_pq.push(fst_num);
					fst_pq.push(sed_num);
				}
			}else{
				// 소수긴함
				if(check[b]){
					sed_sum-=1000;
				}else{
					++check[b];
					sed_pq.push(b);
				}
			}
			// cout<<i<<" "<<fst_sum<<" "<<sed_sum<<"\n";
		}
		// cout<<fst_sum<<" "<<sed_sum<<endl;
		if(fst_sum>sed_sum){
			cout<<"소수의 신 갓대웅";
		}else if(fst_sum<sed_sum){
			cout<<"소수 마스터 갓규성";
		}else{
			cout<<"우열을 가릴 수 없음";
		}
	}
	return 0;
}