#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,B;
vector<pair<int,int>> area;
const int MAX=500+1;
int board[MAX][MAX];
void Input(){
	cin>>N>>M>>B;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
int maxNum=1222232421;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first>b.first;
	}
	return a.second<b.second;
}
int calc(int cur_height){
	int curB=B;
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]>cur_height){
				int diff=board[i][j]-cur_height;
				curB+=diff;
				cnt+=(diff*2);
			}
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]<cur_height){
				int diff=cur_height-board[i][j];
				if(curB<diff){
					return maxNum;
				}else{
					curB-=diff;
					cnt+=diff;
				}
			}
		}
	}
	return cnt;
}
void solve(){
	for(int i=0;i<=256;++i){
		int cur_num=calc(i);
		if(cur_num==maxNum) continue;
		area.push_back({i,cur_num});
	}
	sort(area.begin(),area.end(),comp);
	cout<<area[0].second<<" "<<area[0].first;
	
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}