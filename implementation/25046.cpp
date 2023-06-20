#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1252
int N=0;
const int MAX=9+1;
int board[MAX][MAX];
int check[MAX][MAX];
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
long long maxNum=-100000000000-1;
bool visited[MAX];
vector<int> v;
void dfs(int cnt, int idx){
	if(cnt==0){
		long long curSum=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				check[i][j]=0;
			}
		}
		for(int i=0;i<v.size();++i){
			int curNum=v[i];
			for(int j=0;j<N;++j){
				check[curNum][j]=1;
			}
		}
		for(int i=0;i<N;++i){
			long long checked_sum=0;
			long long no_checked_sum=0;
			for(int j=0;j<N;++j){
				if(check[j][i]==1){
					checked_sum+=board[j][i];
				}else{
					no_checked_sum+=board[j][i];
				}
			}
			if(checked_sum>no_checked_sum){
				for(int j=0;j<N;++j){
					++check[j][i];
				}
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(check[i][j]==1){
					curSum+=board[i][j];
				}
			}
		}
		maxNum=max(maxNum,curSum);
		return;
	}
	if(idx>=N){
		return;
	}
	for(int i=idx;i<N;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			dfs(cnt-1,i);
			visited[i]=0;
			v.pop_back();
		}
	}
}
void solve(){
	// cout<<maxNum<<endl;
	for(int i=0;i<=N;++i){
		for(int j=0;j<N;++j){
			visited[j]=0;
		}
		v.clear();
		dfs(i,0);
	}
	cout<<maxNum;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}