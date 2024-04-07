#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int N;
const int MAX=10+1;
int board[MAX][MAX];
bool visited[MAX][MAX];
int check[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<pair<int,int>> v;
int ans=1222232421;
void dfs(int y, int x){
	if(v.size()==3){
		// for(int i=0;i<3;++i){
		// 	cout<<"("<<v[i].first<<" "<<v[i].second<<")";
		// }cout<<endl;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				check[i][j]=0;
			}
		}
		// if(v[0].first==2 && v[0].second==3 && v[1].first==4 && v[2].first==1){
		// 	cout<<"he";
		// }
		bool flag=0;
		for(int i=0;i<3;++i){
			int y=v[i].first;
			int x=v[i].second;
			++check[y][x];
			for(int j=0;j<4;++j){
				int ny=y+dy[j];
				int nx=x+dx[j];
				if(check[ny][nx]){
					flag=1;
					break;
				}
				++check[ny][nx];
			}
			if(flag) break;
		}
		// if(v[0].first==2 && v[0].second==3){
		// 	cout<<flag<<endl;;
		// }
		if(!flag){
			// for(int i=0;i<3;++i){
			// 	cout<<"("<<v[i].first<<" "<<v[i].second<<")";
			// }cout<<endl;
			int sum=0;
			for(int i=0;i<3;++i){
				int y=v[i].first;
				int x=v[i].second;
				for(int j=0;j<4;++j){
					int ny=y+dy[j];
					int nx=x+dx[j];
					sum+=board[ny][nx];
				}
				sum+=board[y][x];
			}
			ans=min(ans,sum);
		}
		return;
	}
	//y,x
	// if(y==4 && x==4){
	// 	cout<<v.size()<<endl;
	// }
	v.push_back({y,x});
	if(x+1==N-1){
		if(y+1<N-1){
			dfs(y+1,1);	
		}else{
			if(v.size()==3){
				dfs(y,x);
			}
		}
	}else{
		dfs(y,x+1);
	}
	v.pop_back();
	if(x+1==N-1){
		if(y+1<N-1){
			dfs(y+1,1);
		}else{
			if(v.size()==3){
				dfs(y,x);
			}
		}
	}else{
		dfs(y,x+1);
	}
	
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}