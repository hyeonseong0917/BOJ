#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
        ll n,m;
        cin>>n>>m;
        // v[i]: 무게당 요금
        vector<ll> v(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }

        // p[i]: 차량무게
        vector<ll> p(m,0);
        for(ll i=0;i<m;++i){
            cin>>p[i];
        }
        ll Q=m*2;
        vector<ll> cur_order(Q,0);
        for(ll i=0;i<Q;++i){
            cin>>cur_order[i];
        }
        // check[i]: i번째 주차장에 몇 번째 차량이 들어가 있는지?
        vector<ll> check(n,-1);
        ll ans=0;
        // i번째 차량이 들어갈 때, 현재 비어있는 가장 작은 주차장의 번호
        queue<ll> q;
        for(ll i=0;i<Q;++i){
            if(cur_order[i]<0){
                ll cur_parking_num=-1;
                ll cur_car_num=cur_order[i]*-1;
                for(ll j=0;j<n;++j){
                    if(cur_car_num==check[j]){
                        cur_parking_num=j;
                        break;
                    }
                }
                // cout<<"FD"<<cur_parking_num<<"\n";
                ans+=v[cur_parking_num]*p[cur_car_num-1];
                check[cur_parking_num]=-1;

                // q에 있는거 청산
                if(!q.empty()){
                    ll next_car_num=q.front();
                    q.pop();
                    check[cur_parking_num]=next_car_num;
                }
            }else{
                ll cur_car_num=cur_order[i];
                bool is_full=1;
                for(ll j=0;j<n;++j){
                    if(check[j]==-1){
                        is_full=0;
                    }
                }
                if(is_full){
                    q.push(cur_car_num);
                }else{
                    for(ll j=0;j<n;++j){
                        if(check[j]==-1){
                            check[j]=cur_car_num;
                            // cout<<"FDFDSFDFsfs"<<i<<" "<<j<<" "<<check[j]<<"\n";
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans;
	} 
	return 0;
}