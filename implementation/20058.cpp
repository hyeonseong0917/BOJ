#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int MAX=64+1;
int A[MAX][MAX];
int N,Q=0;
vector<int> L;
int p=0;
void Input(){
	cin>>N>>Q;
	p=pow(2,N);
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<Q;++i){
		int a=0;
		cin>>a;
		L.push_back(a);
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<p && x<p);
}
int maxCnt=0;
int res=0;
bool visited[MAX][MAX];
void dfs(int m, int n){
	for(int i=0;i<4;++i){
		int ny=m+dy[i];
		int nx=n+dx[i];
		if(isRange(ny,nx) && A[ny][nx]!=0 && !visited[ny][nx]){
			visited[ny][nx]=1;
			++maxCnt;
			// cout<<maxCnt<<" "<<m<<" "<<n<<endl;
			dfs(ny,nx);
		}
	}
}

void solve(){
	int y=0,x=0;
	for(int i=0;i<Q;++i){
		int cur_step=pow(2,L[i]);
		y=0, x=0;
		vector<pair<int,int>> melt;
		while(1){
			
			// cout<<y<<" "<<x<<endl;
			vector<pair<int,int>> v;
			int cnt=0;
			//cnt순 정렬
			for(int j=y+cur_step-1;j>=y;--j){
				for(int k=x;k<x+cur_step;++k){
					v.push_back({A[j][k],cnt});
					++cnt;
				}
			}
			int idx=0;
			for(int j=x;j<x+cur_step;++j){
				for(int k=y;k<y+cur_step;++k){
					A[k][j]=v[idx].first;
					++idx;
				}
			}
			//회전 끝
			//얼음 계산
			
			x+=cur_step;
			if(x>=p){
				x=0;
				y+=cur_step;
			}
			if(y==p){
				break;
			}
		}
		for(int j=0;j<p;++j){
				for(int k=0;k<p;++k){
					if(A[j][k]==0) continue;
					int ice_cnt=0;
					for(int m=0;m<4;++m){
						int ny=j+dy[m];
						int nx=k+dx[m];
						if(isRange(ny,nx)){
							if(A[ny][nx]>0){
								++ice_cnt;
							}
						}
					}
					if(ice_cnt<3){
						melt.push_back({j,k});
					}
				}
		}
		for(int j=0;j<melt.size();++j){
			int my=melt[j].first;
			int mx=melt[j].second;
			--A[my][mx];	
		}
		// for(int i=0;i<p;++i){
		// 	for(int j=0;j<p;++j){
		// 		cout<<A[i][j]<<" ";
		// 	}cout<<endl;
		// }cout<<endl;
	}
	int sum=0;
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			sum+=A[i][j];
		}
	}
	cout<<sum<<endl;
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			visited[i][j]=0;
			
		}
	}
	for(int i=0;i<p;++i){
		for(int j=0;j<p;++j){
			if(!visited[i][j] && A[i][j]>0){
				maxCnt=0;
				dfs(i,j);		
				res=max(res,maxCnt);	
			}
		}
	}
	cout<<res;
	
	// for(int i=0;i<p;++i){
	// 			for(int j=0;j<p;++j){
	// 				cout<<A[i][j]<<" ";
	// 			}cout<<endl;
	// 		}
}

//1045
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}