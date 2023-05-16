#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N,M=0;
const int MAX=50+1;
int A[MAX][MAX]={0,};
int dy[8]={0,-1,-1,-1,0,1,1,1};
int dx[8]={-1,-1,0,1,1,1,0,-1};
vector<int> d,s;
vector<pair<int,int>> cloud;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}

void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<M;++i){
		int a,b=0;
		cin>>a>>b;
		d.push_back(a-1);
		s.push_back(b%N);
	}
}
void solve(){
	cloud.push_back({N-1,0});
	cloud.push_back({N-1,1});
	cloud.push_back({N-2,0});
	cloud.push_back({N-2,1});
	for(int i=0;i<M;++i){
		map<pair<int,int>, int> m;
		for(int j=0;j<cloud.size();++j){
			int curDir=d[i];
			int curDist=s[i];
			cloud[j].first+=(dy[curDir]*curDist);
			cloud[j].second+=(dx[curDir]*curDist);
			if(cloud[j].first<0){
				cloud[j].first+=N;
			}
			if(cloud[j].first>N-1){
				cloud[j].first-=N;
			}
			if(cloud[j].second<0){
				cloud[j].second+=N;
			}
			if(cloud[j].second>N-1){
				cloud[j].second-=N;
			}
			// cout<<cloud[j].first<<" "<<cloud[j].second<<endl;
			
		}
		// return;
		for(int j=0;j<cloud.size();++j){
			A[cloud[j].first][cloud[j].second]+=1;
			m[{cloud[j].first,cloud[j].second}]=1;
		}
		for(int j=0;j<cloud.size();++j){
			int cnt=0;
			for(int k=0;k<8;++k){
				if(k%2==1){
					int ny=cloud[j].first+dy[k];
					int nx=cloud[j].second+dx[k];
					if(isRange(ny,nx) && A[ny][nx]>0){
						++cnt;
					}
				}
				
			}
			A[cloud[j].first][cloud[j].second]+=cnt;
		}
		
		cloud.clear();
		for(int j=0;j<N;++j){
			for(int k=0;k<N;++k){
				if(A[j][k]>=2 && m[{j,k}]!=1){
					cloud.push_back({j,k});
					A[j][k]-=2;
				}
			}
		}
		// for(int k=0;k<cloud.size();++k){
		// 	cout<<i+1<<" move after cloud: "<<cloud[k].first<<" "<<cloud[k].second<<endl;
		// }
		// for(int j=0;j<N;++j){
		// 	for(int k=0;k<N;++k){
		// 		cout<<A[j][k];
		// 	}cout<<endl;
		// }
		// cout<<endl;
	}
	int res=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(A[i][j]>0){
				res+=A[i][j];	
			}
			
		}
	}
	cout<<res;
}



int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}