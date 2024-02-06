#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<int> v(7,0);
void Input(){
	for(int i=1;i<=6;++i){
		int a=0;
		cin>>a;
		v[i]=a;
	}
}

void solve(){
	int cnt=0;
	for(int i=6;i>=1;--i){
		if(i==6){
			cnt+=v[i];
		}else if(i==5){
			cnt+=v[i];
			v[1]=max(0,v[1]-v[i]*11);
		}else if(i==4){
			cnt+=v[i];
			while(v[i]--){
				if(v[2]>=5){
					v[2]-=5;
				}else{
					v[1]=max(0,v[1]-(20-v[2]*4));
					v[2]=0;		
				}
			}
		}else if(i==3){
			if(v[i]<=0) continue;
			cnt+=v[i]/4;
			if(v[i]%4!=0){
				++cnt;
				if(v[i]%4==1){
					// 3구역 남음, 27칸
					if(v[2]>=5){
						v[2]-=5;
						v[1]=max(0,v[1]-7);
					}else{
						v[1]=max(0,v[1]-(27-4*v[2]));
						v[2]=0;
					}
				}else if(v[i]%4==2){
					// 2구역 남음, 18칸
					if(v[2]>=3){
						v[2]-=3;
						v[1]=max(0,v[1]-6);
					}else{
						v[1]=max(0,v[1]-(18-4*v[2]));
						v[2]=0;
					}
				}else{
					if(v[2]>=1){
						v[2]-=1;
						v[1]=max(0,v[1]-5);
					}else{
						v[1]=max(0,v[1]-9);
					}
				}
			}
		}else if(i==2){
			if(v[i]<=0) continue;
			cnt+=v[i]/9;
			if(v[i]%9!=0){
				++cnt;
				int rest=9-v[i]%9;
				int rest_piece=rest*4;
				v[1]=max(0,v[1]-rest_piece);
			}
		}else if(i==1){
			if(v[i]<=0) continue;
			cnt+=v[i]/36;
			if(v[i]%36!=0){
				++cnt;
			}
		}
	}
	cout<<cnt;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}