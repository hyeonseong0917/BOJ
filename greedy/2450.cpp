#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=100000+1;
int a[MAX];
int b[MAX];
int minNum=122232421;
int N=0;
int num[4+1], order[4+1], visited[4+1];

void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
		++num[a[i]];
	}
}


void dfs(int cnt){
	// cout<<cnt<<endl;
	if(cnt>=4){
		int cur_num=0;
		int origin_pos[4+1][4+1]={0,};
		int first_num=0, second_num=0;
		int idx=0;
		for(int i=1;i<4;++i){
			int cur_order=order[i];
			for(int j=0;j<num[cur_order];++j){
				b[idx]=cur_order;
				++idx;
			}
		}
		for(int i=0;i<N;++i){
			++origin_pos[b[i]][a[i]];
		}
		for(int i=1;i<3;++i){
			for(int j=i+1;j<4;++j){
				idx=min(origin_pos[i][j], origin_pos[j][i]);
				//cout<<idx;
				first_num+=idx;
				second_num+=origin_pos[i][j]+origin_pos[j][i]-(idx*2);
			}
		}
		cur_num=first_num+(second_num/3*2);
		// cout<<cur_num<<endl;
		minNum=min(minNum,cur_num);
		// cout<<minNum<<endl;
		return;
	}
	for(int i=1;i<=3;++i){
		if(!visited[i]){
			visited[i]=1;
			order[cnt]=i;
			dfs(cnt+1);
			visited[i]=0;
		}
	}
}

void solve(){
	dfs(1);
	cout<<minNum;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}