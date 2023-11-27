#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int S;

void Input(){
	cin>>S;
}
const int MAX=1000+1;
int dp[MAX*2][MAX*2];
int BFS(){
	queue<pair<int,int>> q; //현재 길이, 복사한 길이, 현재 시간
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			dp[i][j]=122232421;
		}
	}
	dp[1][0]=0;
	q.push({1,0});
	while(!q.empty()){
		int cur_len=q.front().first;
		int copy_len=q.front().second;
		q.pop();
		if(cur_len==S){
			return dp[cur_len][copy_len];
		}
		// 현재 문자열 복사
		if(dp[cur_len][cur_len]>dp[cur_len][copy_len]+1){
			dp[cur_len][cur_len]=dp[cur_len][copy_len]+1;
			q.push({cur_len,cur_len});
		}
		// 복사된 문자열 붙여넣기
		if(dp[cur_len+copy_len][copy_len]>dp[cur_len][copy_len]+1){
			dp[cur_len+copy_len][copy_len]=dp[cur_len][copy_len]+1;
			q.push({cur_len+copy_len,copy_len});
		}
		// 문자열 삭제
		if(cur_len>=2 && dp[cur_len-1][copy_len]>dp[cur_len][copy_len]+1){
			dp[cur_len-1][copy_len]=dp[cur_len][copy_len]+1;
			q.push({cur_len-1,copy_len});
		}
	}
	return -1;
}
void solve(){
	cout<<BFS();
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	solve();
	
	return 0;
}
