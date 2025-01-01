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
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		ll cnt=0;
		priority_queue<ll> pq;
		ll sum=0;
		for(ll i=0;i<n;++i){
			if(v[i].first>=sum){
				sum+=v[i].second;	
				pq.push(v[i].second);
			}else{
				// i번째 진입이 안됨 - i번째를 배제할수도 있네
				if(cnt==1){
					// 이미 한 번 날린 전적이 있음
					++cnt;
					break;
				}
				// i번째를 언제 배제해야 할까?
				// i번째 라운드의 상금 비용이 top보다 크다면 i제외
				ll cur_num=pq.top();
				if(cur_num<=v[i].second){
					// i번째 대회 날리기
					// 상금 같다면 지금꺼 날리기
					++cnt;
				}else{
					// 현재 큐에서 가장 상금 큰거 날리기
					pq.pop();
					++cnt;
					sum-=cur_num;
					// i번째 진입 되는지?
					if(v[i].first>=sum){
						sum+=v[i].second;
						pq.push(v[i].second);
					}else{
						// i번째 진입 안됨.. 그냥 i번째를 날려야함
						pq.push(v[i].second);
						sum+=cur_num;
					}
				}
				
			}
		}
		if(cnt<=1){
			cout<<"Kkeo-eok";
		}else{
			cout<<"Zzz";
		}
	} 
	return 0;
}