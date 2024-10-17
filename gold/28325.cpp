#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<bool> visited(n,0);
		bool flag=0;
		queue<ll> q;
		ll ans=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]){
				flag=1;
				// L과 R 놓을 수 있는지?
				// L가능하면 L-1 큐에 넣을 수 있는지
				// R가능하면 R+1 큐에 넣을 수 있는지
				q.push(i);
			} 
			ans+=v[i];
		}
		if(flag){
			while(!q.empty()){
				ll cur_num=q.front();
				q.pop();
				// cur_num에는 못놓기 때문에 L,R을 확인해봄
				ll L=cur_num-1;
				if(L==-1) L=n-1;
				ll R=cur_num+1;
				if(R==n) R=0;
				// L 가능?
				if(!v[L] && !visited[L]){
					// L에 놓을 수 있음
					// L-1에는 못놓음
					// L-2에 놓을 수 있는지?
					ll LL=L-1;
					if(LL<0) LL+=n;
					if(!visited[LL]){
						visited[L]=1;
						++ans;
						q.push(LL);
					}
				}
				if(!v[R] && !visited[R]){
					// R에 놓을 수 있음
					
					// R+1에는 못놓음
					// R+2에 놓아야
					ll RR=R+1;
					if(RR==n) RR=0;
					if(!visited[RR]){
						visited[R]=1;
						++ans;
						q.push(RR);
					}
				}
			}
			cout<<ans;
		}else{
			cout<<n/2;
		}
	}
	return 0;
}