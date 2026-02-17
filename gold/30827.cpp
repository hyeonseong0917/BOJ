#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll o=1;
    while(o--){
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;++i){
            ll a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end(),comp);
        priority_queue<pair<ll,ll>> pq;
        ll ans=0;
        vector<ll> check(k,0);
        for(ll i=0;i<n;++i){
            ll ps=pq.size();
            if(ps<k){
                priority_queue<pair<ll,ll>> tmp;
                ll room_num=-1;
                while(!pq.empty()){
                    ll cur_num=pq.top().first;
                    pair<ll,ll> p=pq.top();
                    if(cur_num<v[i].first){
                        // 방 뺄 수 있는거 찾음
                        // 뺄 수 있는 방중 가장 큰 시간을 가짐 -> 이게 무조건 최적임
                        room_num=pq.top().second;
                        check[room_num]=0;
                        pq.pop();
                        break;
                    }else{
                        // 방 뺄 수 없음
                        tmp.push(p);
                        pq.pop();
                    }
                }
                while(!tmp.empty()){
                    pair<ll,ll> p=tmp.top();
                    pq.push(p);
                    tmp.pop();
                }
                if(room_num!=-1){
                    check[room_num]=1;
                    ++ans;
                    pq.push({v[i].second,room_num});
                }else{
                    for(ll j=0;j<k;++j){
                        if(!check[j]){
                            room_num=j;
                            ++check[j];
                            break;
                        }
                    }
                    ++ans;
                    // pq에는 끝나는 시간을 내림차순으로 넣음
                    pq.push({v[i].second,room_num});
                }
                // 뺄 수 있는거 있으면 빼는게?
                
            }else{
                // ps>=k
                // 시간 다 종료된 회의실을 찾아야함
                // v[i].first 작업을 시작할 수 있는지?
                // pq에는 끝나는 시간이 내림차순으로 담겨져 있음
                // 
                priority_queue<pair<ll,ll>> tmp;
                ll room_num=-1;
                while(!pq.empty()){
                    ll cur_num=pq.top().first;
                    pair<ll,ll> p=pq.top();
                    if(cur_num<v[i].first){
                        // 방 뺄 수 있는거 찾음
                        // 뺄 수 있는 방중 가장 큰 시간을 가짐 -> 이게 무조건 최적임
                        room_num=pq.top().second;
                        check[room_num]=0;
                        pq.pop();
                        break;
                    }else{
                        // 방 뺄 수 없음
                        tmp.push(p);
                        pq.pop();
                    }
                }
                while(!tmp.empty()){
                    pair<ll,ll> p=tmp.top();
                    pq.push(p);
                    tmp.pop();
                }
                if(room_num!=-1){
                    check[room_num]=1;
                    ++ans;
                    pq.push({v[i].second,room_num});
                }
            }
        }
        cout<<ans;
    }
    return 0;
}