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
		ll L, ML, MK;
		cin>>L>>ML>>MK;
		ll C;
		cin>>C;
		vector<ll> Z(L,0);
		for(ll i=0;i<L;++i){
			cin>>Z[i];
		}
		bool flag=0;
		vector<ll> max_len_save;
		for(ll i=0;i<L;++i){
			if(max_len_save.empty()){
				if(Z[i]>MK){
					if(C){
						--C;
					}else{
						flag=1;
						break;
					}
				}else{
					max_len_save.push_back(min(L-1, i+ML-1));
				}
			}else{
				// 현재 좀비의 피를 구해보자
				// max_len에 현재 idx와 크거나 같은 최소 인덱스는 얼마일까?
				// cout<<"he"<<i<<endl;
				ll mls=max_len_save.size();
				ll Left=0,Right=mls-1;
				ll mid;
				ll cur_idx=1222232421;
				while(Left<=Right){
					mid=(Left+Right)/2;
					if(max_len_save[mid]>=i){
						cur_idx=min(cur_idx,mid);
						Right=mid-1;
					}else{
						Left=mid+1;
					}
				}
				// if(i==3){
				// 	for(int j=0;j<mls;++j){
				// 		cout<<max_len_save[j]<<" ";
				// 	}cout<<endl;
				// }
				// cout<<i<<" "<<cur_idx<<" "<<C<<endl;
				if(cur_idx!=1222232421){
					ll cur_num=mls-cur_idx;
					Z[i]-=MK*cur_num;
					
				}
				if(Z[i]>MK){
					if(C){
						--C;
					}else{
						flag=1;
						break;
					}
				}else{
					max_len_save.push_back(min(L-1, i+ML-1));		
				}
			}
		}
		if(flag){
			cout<<"NO";
		}else{
			cout<<"YES";
		}
	}

	return 0;
}