#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
        if(n==1){
			cout<<-1;
			break;
		}
		ll idx=-1;
		for(ll i=n-1;i>=1;--i){
			if(v[i-1]>v[i]){
				idx=i-1;
				ll sed_max_num=-1;
				ll sed_max_idx=-1;
				for(ll j=i;j<n;++j){
					if(sed_max_num<v[j] && v[j]<v[i-1]){
						sed_max_num=v[j];
						sed_max_idx=j;
					}
				}
				ll ttmp=v[i-1];
				v[i-1]=sed_max_num;
				v[sed_max_idx]=ttmp;
				vector<ll> tmp;
				for(ll j=i;j<n;++j){
					tmp.push_back(v[j]);
				}
				sort(tmp.begin(),tmp.end());
				reverse(tmp.begin(),tmp.end());
				for(ll j=i;j<n;++j){
					v[j]=tmp[j-i];
				}
				break;
			}
		}
		if(idx==-1){
			cout<<-1;
		}else{
			for(ll i=0;i<n;++i){
				cout<<v[i]<<" ";
			}	
		}
		
		
	}
	return 0;
}