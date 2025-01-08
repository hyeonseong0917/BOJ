#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll cache[200+1][200+1];
string a,b,c;
ll dp(ll x, ll y){
	// cout<<x<<" "<<y<<endl;
	if(cache[x][y]!=-1) return cache[x][y];
	if(x+y==c.size()){
		return cache[x][y]=1;
	}
	if(x==a.size()){
		if(b[y]==c[x+y]){
			return cache[x][y]=dp(x,y+1);
		}else{
			return cache[x][y]=0;
		}
	}
	if(y==b.size()){
		if(a[x]==c[x+y]){
			return cache[x][y]=dp(x+1,y);
		}else{
			return cache[x][y]=0;
		}
	}
	// a의 x인덱스까지와 b의 y인덱스까지로 c의[x+y]까지 만들 수 있는지?
	if(a[x]==c[x+y] || b[y]==c[x+y]){
		return cache[x][y]=(dp(x+1,y) || dp(x,y+1));
	}else{
		return cache[x][y]=0;
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			
			cin>>a;
			cin>>b;
			cin>>c;
			// a,b,c
			// a와 b의 순서 지키며 c만들 수 있는지?
			// cat tree tcraete
			// dp[x][y][z]: a의 x번째인덱스, b의 y번째 인덱스까지 봤을 때
			// c의 z번째 인덱스까지 처리할 수 있는지?
			// dp[x][y][z]: 만약 a[x]가 c[z] | b[y]=c[z]라면
			// dp[x][y][z]=1 z++
			// 둘 다 아니라면? x++ y++?

			// a와 b를 활용해 dp[x]: c의 x인덱스까지 만들 수 있는지
			// if(a)
			for(ll j=0;j<=a.size();++j){
				for(ll k=0;k<=b.size();++k){
					cache[j][k]=-1;
				}
			}
			dp(0,0);
			ll flag=0;
			if(cache[a.size()][b.size()]!=-1){
				// cout<<cache[a.size()][b.size()][c.size()];
				flag=1;
			}
			cout<<"Data set "<<i+1<<": ";
			if(flag){
				cout<<"yes"<<"\n";
			}else{
				cout<<"no"<<"\n";
			}
		}
	}
	return 0;
}