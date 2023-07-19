#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> board[50+1];
// vector<int> visited[50+1];
vector<int> d;
vector<pair<int,int>> h;
bool visited[50+1][3+1];
 
void Input(){
	for(int i=0;i<10;++i){
		int a=0;
		cin>>a;
		d.push_back(a);
	}
	for(int i=0;i<4;++i){
		h.push_back({0,0});
	}
}
void Init(){
	for(int i=0;i<40;++i){
		if(i%2==0){
			board[i].push_back(i+2);
		}
	}
	board[10].push_back(13);
	board[13].push_back(0);
	board[13].push_back(16);
	board[16].push_back(19);
	board[19].push_back(0);
	board[19].push_back(25);
 
	board[20].push_back(22);
	board[22].push_back(24);
	board[24].push_back(25);
 
	board[30].push_back(28);
	board[28].push_back(27);
 
	board[27].push_back(0);
	board[27].push_back(26);
	board[26].push_back(25);
 
	board[25].push_back(0);
	board[25].push_back(0);
	board[25].push_back(30);
	board[30].push_back(35);
	board[35].push_back(0);
	board[35].push_back(0);
	board[35].push_back(40);
 
	board[40].push_back(-1);
	// board[40].push_back(0);
	// board[40].push_back(-1);
}
 
int Move(int h_idx, int dice){
	int curPos=h[h_idx].first;
	int curIdx=h[h_idx].second;
	if((curPos==10 || curPos==20 || curPos==30) && curIdx!=2){
		curIdx=1;
	}
	if(curPos==25){
		curIdx=2;
	}
	if(curPos==40){
		curIdx=0;
	}
	while(dice--){
		curPos=board[curPos][curIdx];
		if(curPos==-1){
			// cout<<curIdx<<"\n";
			break;
		}
		if(curPos==25){
			curIdx=2;
		}
		if(curPos==40){
			curIdx=0;
		}
	}
	if((curPos==10 || curPos==20 || curPos==30) && curIdx!=2){
		curIdx=1;
	}
	if(curPos==25){
		curIdx=2;
	}
	if(curPos==40){
		curIdx=0;
	}
	// if(curPos==10){
	// 	cout<<visited[curPos][curIdx]<<"\n";
	// }
	if(!visited[curPos][curIdx] && curPos!=-1){
		visited[curPos][curIdx]=1;
		h[h_idx]={curPos,curIdx};
		return curPos;	
	}else{
		if(curPos==-1){
			h[h_idx]={curPos,curIdx};
			return -1;
		}
		// if(curPos==10){
		// 	cout<<0<<"\n";
		// }
		return 0;
	}
}
int maxNum=-122232421;
vector<int> tidx,tnum;
void dfs(int idx, int sum){
	// cout<<idx<<" "<<sum<<"\n";
	if(idx==10){
		maxNum=max(maxNum,sum);
		// if(sum>=190){
		// 	for(int i=0;i<10;++i){
		// 		cout<<tidx[i]<<" ";
		// 	}
		// 	cout<<sum<<" ";
		// 	for(int i=0;i<10;++i){
		// 		cout<<tnum[i]<<" ";
		// 	}
		// 	cout<<"\n";	
		// }
 
		// cout<<maxNum<<"\n";
		return;
	}
	for(int i=0;i<4;++i){
		if(h[i].first==-1) continue;
		int tmpPos=h[i].first;
		int tmpIdx=h[i].second;
		if((tmpPos==10 || tmpPos==20 || tmpPos==30) && tmpIdx!=2){
			tmpIdx=1;
		}
		if(tmpPos==25){
			tmpIdx=2;
		}
		if(tmpPos==40){
			tmpIdx=0;
		}
		
		int num=Move(i,d[idx]); // 이동
		// cout<<num<<"\n";
		//num이 0인 이유? 이미 말이 있는곳을 방문한 경우
		//근데 실제로 말이 없는데..? 방문 처리를 잘못했나?
		if(num!=0){
			visited[tmpPos][tmpIdx]=0;
			if(num==-1){
				// visited[tmpPos][tmpIdx]=0;
				num=0;
				tnum.push_back(num);
				tidx.push_back(i);
				dfs(idx+1,sum+num);
				tidx.pop_back();
				tnum.pop_back();
				h[i].first=tmpPos;
				h[i].second=tmpIdx;
				visited[tmpPos][tmpIdx]=1;
			}else{
				// visited[tmpPos][tmpIdx]=0;
				int curPos=h[i].first;
				int curIdx=h[i].second;
				visited[curPos][curIdx]=1;
				// visited[tmpPos][tmpIdx]=0;
				tnum.push_back(num);
				tidx.push_back(i);
				dfs(idx+1,sum+num);
				visited[tmpPos][tmpIdx]=1;
				visited[curPos][curIdx]=0;
				tidx.pop_back();
				tnum.pop_back();
				h[i].first=tmpPos;
				h[i].second=tmpIdx;	
			}
			
		}
 
		// 메롱
 
	}
}
 
void solve(){
	Init();
	// cout<<Move(1,d[0]);
	dfs(0,0);
	cout<<maxNum;
}
 
int main() {
	// your code goes here
	Input();
	solve();
 
	return 0;
}