#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	int t=1;
	while(t--){
		// map<int,int> m;
		// m[4]=100;
		// m[3]=200;
		// m[2]=500;
		// m[6]=300;
		// m.erase(6);
		// auto lower=m.lower_bound(5);
		// if(lower==m.end()){
		// 	cout<<"YE";
		// }
		// cout<<lower->second;
		ll N,Q;
		cin>>N>>Q;
		vector<ll> a(N,0);
		map<ll,ll> m;
		for(ll i=0;i<N;++i){
			cin>>a[i];
			if(a[i]>0){
				m[i]=1;
			}
		}
		ll v=0;
		while(Q--){
			ll cmd;
			cin>>cmd;
			if(cmd==1){
				ll cur_num;
				cin>>cur_num;
				--cur_num;
				if(m.find(cur_num)==m.end()){
					m[cur_num]=1;
				}else{
					m.erase(cur_num);
				}
			}else if(cmd==2){
				ll x;
				cin>>x;
				v=(v+x)%N;
			}else{
				auto bigger_key=m.lower_bound(v);
				if(bigger_key==m.end()){
					// cout<<"HE";
					auto lower_key=m.lower_bound(0);
					if(lower_key==m.end()){
						cout<<-1<<"\n";
					}else{
						ll lower_pos=lower_key->first;	
						cout<<(lower_pos+N)-v<<"\n";
					}
				}else{
					// cout<<"YE"<<"\n";
					ll bigger_pos=bigger_key->first;
					// cout<<bigger_pos<<endl;
					cout<<bigger_pos-v<<"\n";
				}
			}
		}

	}
	return 0;
}