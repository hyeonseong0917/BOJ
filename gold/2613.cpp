#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]+=psum[i-1]+v[i];
		}
		ll ans=2023101800;
		vector<ll> tmp_fst, tmp_sed;
		ll last_l,last_r;
		for(ll i=0;i<n;++i){
			for(ll j=i;j<n;++j){
				if(i+(n-1-(j+1)+1)<m-1) continue;
				// cur_sum을 최소로
				ll cur_sum=psum[j]-psum[i]+v[i];
				bool flag=0;
				for(ll k=0;k<i;++k){
					if(v[k]>cur_sum){
						flag=1;
						break;
					}
				}
				for(ll k=j+1;k<n;++k){
					if(v[k]>cur_sum){
						flag=1;
						break;
					}
				}
				if(flag) continue;

				ll fst_cnt=1, sed_cnt=1;
				vector<ll> fst_save, sed_save;
				if(i==0) fst_cnt=0;
				if(j==n-1) sed_cnt=0;

				ll fst_sum=0;
				ll fst_size=0;
				for(ll k=0;k<i;++k){
					if(fst_sum+v[k]<=cur_sum){
						fst_sum+=v[k];
						++fst_size;
					}else{
						fst_save.push_back(fst_size);
						fst_size=1;
						fst_sum=v[k];
					}
				}
				if(fst_size){
					fst_save.push_back(fst_size);
				}
				ll fs=0;
				if(!fst_save.empty()){
					fs=fst_save.size();
				}

				ll sed_sum=0;
				ll sed_size=0;
				for(ll k=j+1;k<n;++k){
					if(sed_sum+v[k]<=cur_sum){
						sed_sum+=v[k];
						++sed_size;
					}else{
						sed_save.push_back(sed_size);
						sed_size=1;
						sed_sum=v[k];
					}
				}
				if(sed_size){
					sed_save.push_back(sed_size);
				}
				ll ss=0;
				if(!sed_save.empty()){
					ss=sed_save.size();
				}
				if(fs+ss<=m-1 && ans>cur_sum){
					ans=cur_sum;
					
					tmp_fst=fst_save;
					tmp_sed=sed_save;
					last_l=i;
					last_r=j;
					// cout<<i<<" "<<j<<endl;
				}
			}
		}
		ll fs=tmp_fst.size();
		ll ss=tmp_sed.size();
		if(fs+ss==m-1){
			cout<<ans<<"\n";
			for(ll i=0;i<fs;++i){
				cout<<tmp_fst[i]<<" ";
			}
			cout<<last_r-last_l+1<<" ";
			for(ll i=0;i<ss;++i){
				cout<<tmp_sed[i]<<" ";
			}
		}else{
			// fs+ss<m-1
			ll diff=(m-1)-(fs+ss);
			// cout<<last_l<<" "<<last_r<<" "<<diff<<" "<<fs<<endl;
			// diff 만큼 쪼개기 시작
			for (int i = 0; i < tmp_fst.size() && diff > 0; ++i) {
				while (tmp_fst[i] > 1 && diff > 0) {
					long long splitValue = tmp_fst[i] / 2;
					tmp_fst[i] -= splitValue;
					tmp_fst.insert(tmp_fst.begin() + i + 1, splitValue);
					diff--;
				}
			}
			
			for (int i = 0; i < tmp_sed.size() && diff > 0; ++i) {
				while (tmp_sed[i] > 1 && diff > 0) {
					long long splitValue = tmp_sed[i] / 2;
					tmp_sed[i] -= splitValue;
					tmp_sed.insert(tmp_sed.begin() + i + 1, splitValue);
					diff--;
				}
			}
			
			cout<<ans<<"\n";

			for (long long num : tmp_fst) cout << num << " ";
			cout<<last_r-last_l+1<<" ";
			for (long long num : tmp_sed) cout << num << " ";
		}
		
		

	}
	return 0;
}