#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll ldp[1000+1][1000+1];
ll rdp[1000+1][1000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		string a,b;
		cin>>a;
		cin>>b;
		ll as=a.size();
		ll bs=b.size();
		ll cnt=0;
		for(ll i=0;i<as;++i){
			for(ll j=0;j<bs;++j){
				ll same_cnt=0;
				if(a[i]!=b[j]){
					++same_cnt;
				}
				if(i==0 && j==0){
					ldp[i][j]=same_cnt;
					continue;
				}
				ll fst_cnt=0, sed_cnt=0, trd_cnt=0;
				if(i-1>=0 && j-1>=0){
					fst_cnt=ldp[i-1][j-1];
				}else{
					if(i-1>=0){
						fst_cnt=i;
					}else{
						fst_cnt=j;
					}
				}
				if(j-1>=0){
					sed_cnt=ldp[i][j-1];
				}else{
					sed_cnt=2023101800;
				}
				if(i-1>=0){
					trd_cnt=ldp[i-1][j];
				}else{
					trd_cnt=2023101800;
				}
				ldp[i][j]=fst_cnt+same_cnt;
				ldp[i][j]=min(ldp[i][j],min(sed_cnt+1,trd_cnt+1));
			}
		}
		for(ll i=as-1;i>=0;--i){
			for(ll j=bs-1;j>=0;--j){
				ll same_cnt=0;
				if(a[i]!=b[j]){
					++same_cnt;
				}
				if(i==as-1 && j==bs-1){
					rdp[i][j]=same_cnt;
					continue;
				}
				ll fst_cnt=0, sed_cnt=0, trd_cnt=0;
				if(i+1<=as-1 && j+1<=bs-1){
					fst_cnt=rdp[i+1][j+1];
				}else{
					if(i+1<=as-1){
						fst_cnt=as-(i+1);
					}else if(j+1<=bs-1){
						fst_cnt=bs-(j+1);
					}
				}
				if(i+1<=as-1){
					sed_cnt=rdp[i+1][j];
				}else{
					sed_cnt=2023101800;
				}
				if(j+1<=bs-1){
					trd_cnt=rdp[i][j+1];
				}else{
					trd_cnt=2023101800;
				}
				// cout<<i<<" "<<j<<" "<<fst_cnt<<" "<<sed_cnt<<" "<<trd_cnt<<endl;
				rdp[i][j]=fst_cnt+same_cnt;
				rdp[i][j]=min(rdp[i][j],min(sed_cnt+1,trd_cnt+1));
			}
		}
		// cout<<rdp[1][1]<<endl;
		ll ans=2023101800;
		for(ll i=0;i<as;++i){
			for(ll j=0;j<bs;++j){
				if(i>0 && j>0){
					ans=min(ans,ldp[i-1][j-1]+rdp[i][j]);
				}else{
					if(i==0 && j==0){
						ans=min(ans,rdp[i][j]);
					}else{
						if(i==0){
							ans=min(ans,j+1+rdp[i][j]);
						}else if(j==0){
							ans=min(ans,i+1+rdp[i][j]);
						}
					}
				}
			}
		}
		// cout<<rdp[0][0]<<endl;
		cout<<ans;
	}
	return 0;
}