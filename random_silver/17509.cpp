#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

ll ans=0;
int main() {
    ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    priority_queue<ll> pq;
    for(ll i=0;i<11;++i){
        ll a,b;
        cin>>a>>b;
        // d: i번째 문제를 푸는데 걸리는 시간
        // v: i번째 문제에서 틀린거?
        // 문제를 t분에 해결하면, t+20v의 패널티가 추가됨
        // 모든 문제를 풀 때의 최소 시간은?
        pq.push(a*-1);
        ans+=b*20;
    }
    ll a=0;
    while(!pq.empty()){
        ll c=pq.top()*-1;
        pq.pop();
        a+=c;
        ans+=a;
    }
    cout<<ans;
    
    return 0;
}