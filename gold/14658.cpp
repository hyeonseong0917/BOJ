#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n,m,l,k;
		cin>>n>>m>>l>>k;
		ll max_num=1;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<k;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		for(ll i=0;i<k;++i){
			// i번째 좌표를 왼쪽 변으로 할 때
			ll x=v[i].first;
			ll y=v[i].second;
			// j번째 좌표를 아래 변으로 할 때
			vector<pair<ll,ll>> p;
			for(ll j=0;j<k;++j){
				if(i==j) continue;
				ll nx=v[j].first;
				ll ny=v[j].second;
				if(y-l<=ny && nx<=x+l){
					// if(i==4){
					// 	cout<<"he"<<j<<" "<<y<<" "<<ny<<endl;
					// }
					p.push_back({nx,ny});
				}
			}
			ll cnt=0;
			// p에는 아래 변의 후보가 될 수 있는 좌표들이 담겨져 있음
			for(ll j=0;j<p.size();++j){
				ll nx=p[j].first;
				ll ny=p[j].second;
				// 현재 밑변은 nx,ny를 포함함
				// 왼쪽 꼭짓점음?
				ll min_x=x;
				ll min_y=ny;
				cnt=0;
				for(ll z=0;z<k;++z){
					ll nnx=v[z].first;
					ll nny=v[z].second;
					if(x<=nnx && nnx<=x+l && ny<=nny && nny<=ny+l){
						++cnt;
					}
				}
				max_num=max(max_num,cnt);
			}
		}
		cout<<k-max_num;
		
		
	}
	return 0;
}