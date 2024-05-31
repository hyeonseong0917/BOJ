#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		vector<ll> even_cnt(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll idx=0;
		vector<ll> p;
		while(idx<n){
			if(v[idx]%2==1){
				p.push_back(idx);
			}else{
				ll tmp_idx=idx;
				ll cnt=0;
				for(ll i=tmp_idx;i<n;++i){
					if(v[i]%2==0){
						idx=i;
						++cnt;
					}else{
						break;
					}
				}
				for(ll i=tmp_idx;i<=idx;++i){
					even_cnt[i]=cnt;
				}
			}
			++idx;
		}
		// for(ll i=0;i<n;++i){
		// 	cout<<even_cnt[i]<<" ";
		// }
		ll ps=p.size();
		if(ps<=k){
			cout<<n-ps;
			continue;
		}
		ll cur_sum=0;
		ll ans=0;
		for(ll i=0;i<=ps-k;++i){
			if(i==0){
				if(p[0]-1>=0){
					cur_sum+=even_cnt[p[0]-1];
				}
				for(ll j=0;j<k-1;++j){
					
					cur_sum+=p[j+1]-p[j]-1;
				}
				if(p[k-1]+1<n){
					cur_sum+=even_cnt[p[k-1]+1];
				}
			}else{
				cur_sum-=(p[i]-p[i-1]-1);
				if(p[i-1]-1>=0){
					cur_sum-=even_cnt[p[i-1]-1];
				}
				cur_sum+=p[i+k]-p[i+k-1];
				if(p[i+k]+1<n){
					cur_sum+=even_cnt[p[i+k]+1];
				}
			}
		}
		cout<<cur_sum;
		// 최대 k번 삭제 가능 -> 홀수 없으면 stop
		// K=min(K,홀수 개수)
		// [0,2,4,7]
		// 연속한 짝수 부분 수열 중 최대 길이
		// 0 1 2 3 4 5 6 7 8 9
		// 1 2 3 4 5 6 6 7 8 9
		// 0 1 0 1 0 2 2 0 1 0
		// 연속한 홀수 구간을 제거
		// cnt[x]: x인덱스가 속해있는 구간의 짝수 개수
		// p[0]=0, p[1]=2, p[2]=4
		// [0,2,4,7,9]
		// [0,2,4]->cnt[-1]+(2-0-1)+(4-2-1)+cnt[5]=4
		// [2,4,7]->cnt[1]+(4-2-1)+(7-4-1)+cnt[8]=5
		// [4,7,9]

	}

	return 0;
}