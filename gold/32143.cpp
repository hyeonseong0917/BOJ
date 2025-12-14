#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1220
		// 상대의 체력은 h
		// 다양한 공격력을 가진 카드 n장
		// 어떤 카드로 공격하면 그 카드의 공격력만큼 체력이 줄어듦
		// 체력 0이하 되면 죽음
		// 카드를 최대한 적게써서 상대를 죽이려고함
		// 
		ll h;
		cin>>h;
		ll n,q;
		cin>>n>>q;
		priority_queue<ll> d;
		vector<ll> v;
		ll sum=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			d.push(a);
			v.push_back(a);
			sum+=a;
		}
		if(sum<h){
			cout<<-1<<"\n";
		}else{
			sort(v.rbegin(),v.rend());
			ll tmp=0;
			ll cnt=0;
			for(ll i=0;i<n;++i){
				tmp+=v[i];
				if(tmp>=h){
					cnt=i+1;
					break;
				}
			}
			cout<<cnt<<"\n";
		}
		priority_queue<ll> pq;
		ll d_idx=0;
		ll psum=0;
		// pq에는 최적의 조합을 담는다.
		// psum: pq에 있는 수들의 합
		for(ll i=0;i<q;++i){
			ll a;
			cin>>a;
			// d에 a가 추가되었을 때 h를 최소 몇 개를 써서 깎을 수 있는지??
			sum+=a;
			d.push(a);
			if(sum<h){
				cout<<-1<<"\n";
			}else{
				// sum>=h
				// 1. pq의 top과 a를 비교해서 교체하려면 교체?
				// 2. 추가해야되는건 어떤 상황??
				// d의 d_idx값과 pq의 top()
				while(1){
					if(pq.empty()){
						ll d_num=d.top();
						d.pop();
						pq.push(d_num*-1);
						psum+=d_num;
					}else{
						// pq의 top과 d의 top 비교하면서
						// pq의 top이 d의 top보다 작다면 교체해야함
						ll p_num=pq.top()*-1;
						ll d_num=d.top();
						if(p_num<d_num){
							d.pop();
							pq.pop();
							d.push(p_num);
							pq.push(d_num*-1);
							psum+=d_num-p_num;
						}else{
							// 교체 굳이 안해도됨 그냥 추가
							// p_num>=d_num
							psum+=d_num;
							d.pop();
							pq.push(d_num*-1);
						}
					}
					if(psum>=h){
						break;
					}
				}
				// cout<<i<<" "<<psum<<"\n";
				// pq절감하기
				while(!pq.empty()){
					ll p_num=pq.top()*-1;
					if(psum-p_num>=h){
						psum-=p_num;
						d.push(p_num);
						pq.pop();
					}else{
						break;
					}
				}
				// if(i==2){
				// 	while(!pq.empty()){
				// 		ll p_num=pq.top();
				// 		pq.pop();
				// 		cout<<p_num<<"\n";
				// 	}
				// }
				
				ll ps=pq.size();
				cout<<ps<<"\n";

			}
		}
	}
	return 0;
}