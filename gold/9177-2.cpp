#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

ll cache[200+1][200+1];
string a,b,c;
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
			for(ll j=0;j<=a.size();++j){
				for(ll k=0;k<=b.size();++k){
					cache[j][k]=0;
				}
			}
			// cat
			// tree
			// cattree
			cache[0][0]=1;
			for(ll i=1;i<=a.size();++i){
				if(a[i-1]==c[i-1] && cache[i-1][0]){
					cache[i][0]=1;
				}else{
					cache[i][0]=0;
				}
			}
			for(ll i=1;i<=b.size();++i){
				if(b[i-1]==c[i-1] && cache[0][i-1]){
					cache[0][i]=1;
				}else{
					cache[0][i]=0;
				}
			}
			for(ll i=1;i<=a.size();++i){
				for(ll j=1;j<=b.size();++j){
					if(a[i-1]!=c[i+j-1] && b[j-1]!=c[i+j-1]){
						cache[i][j]=0;
						continue;
					}
					if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1]){
						cache[i][j]=cache[i-1][j];
						continue;
					}
					if(b[j-1]==c[i+j-1] && a[i-1]!=c[i+j-1]){
						cache[i][j]=cache[i][j-1];
						continue;
					}
					cache[i][j]=(cache[i-1][j] || cache[i][j-1]);
					
				}
			}

			cout<<"Data set "<<i+1<<": ";
			bool flag=0;
			if(cache[a.size()][b.size()]){
				flag=1;
			}
			if(flag){
				cout<<"yes"<<"\n";
			}else{
				cout<<"no"<<"\n";
			}
		}
	}
	return 0;
}