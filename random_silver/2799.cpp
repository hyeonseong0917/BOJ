#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int n,m;
vector<int> v(5,0);
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>m>>n;
	string s[501+1];
	for(ll i=0;i<m*5+1;++i){
		cin>>s[i];
	}
	int y=1, x=1;
	while(1){
		if(y>=m*5+1){
			break;
		}
		int ny=y;
		int nx=x;
		bool flag=0;
		for(ll i=ny;i<=ny+3;++i){
			if(s[i][nx]=='*'){

			}else{
				flag=1;
				if(i==ny){
					++v[0];
				}else if(i==ny+1){
					++v[1];
				}else if(i==ny+2){
					++v[2];
				}else if(i==ny+3){
					++v[3];
				}
				break;
			}
		}
		if(!flag){
			++v[4];
		}
		x+=5;
		if(x>=5*n+1){
			y+=5;
			x=1;
		}
	}
	for(int i=0;i<5;++i){
		cout<<v[i]<<" ";
	}
	return 0;
}