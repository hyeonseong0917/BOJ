#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long


ll m,n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<=n && x<=n);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll y=0, x=0, d=1;
		cin>>n>>m;
		bool flag=0;
		for(ll i=0;i<m;++i){
			string s;
			ll k;
			cin>>s;
			cin>>k;
			if(s.compare("MOVE")==0){
				// cout<<y+dy[d]*k<<" "<<x+dx[d]*k<<" "<<d<<"\n";
				if(isRange(y+dy[d]*k, x+dx[d]*k)){
					y+=dy[d]*k;
					x+=dx[d]*k;
				}else{
					flag=1;
					// break;
				}
			}else{
				if(k==0){
					d=(d+1)%4;
				}else{
					d=(d+3)%4;
				}
			}
			// cout<<y<<" "<<x<<" "<<d<<endl;
		}
		if(flag){
			cout<<-1;
		}else{
			cout<<x<<" "<<y;
		}
	}
	return 0;
}