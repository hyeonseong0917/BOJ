#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAX=10+1;
const int BOARD_MAX=5+1;
int board_num[BOARD_MAX][BOARD_MAX];
char board_qual[BOARD_MAX][BOARD_MAX];
vector<vector<pair<int,char>>> board(5,vector<pair<int,char>>(5));
vector<vector<vector<pair<int, char>>>> tool(10, vector<vector<pair<int, char>>>(4, vector<pair<int, char>>(4)));
int n;

vector<vector<int>> left_up_idx; //left_up_idx[i]의 size:3
vector<int> left_up_tmp;
void left_up_pick(){
	if(left_up_tmp.size()==3){
		left_up_idx.push_back(left_up_tmp);
		return;
	}
	for(int i=0;i<4;++i){
		left_up_tmp.push_back(i);
		left_up_pick();
		left_up_tmp.pop_back();	
	}
	
}
vector<vector<pair<int,char>>> cur_impact(4, vector<pair<int,char>>(4));
vector<vector<pair<int,char>>> turned_impact(4, vector<pair<int,char>>(4));
void rotate90(vector<vector<pair<int,char>>> &turned_impact){
    // 주 대각선을 기준으로 원소 교환
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            swap(turned_impact[i][j], turned_impact[j][i]);
        }
    }

    // // 각 행을 역순으로 뒤집기
    for (int i = 0; i < 4; ++i) {
        reverse(turned_impact[i].begin(), turned_impact[i].end());
    }
}
// vector<vector<pair<int,char>>> turned_impact(4, vector<pair<int,char>>(4));
void turn(vector<int> picked, pair<int,pair<int,int>> v[3]){
	// picked: 재료의 인덱스 모음
	// picked[0]번쨰 인덱스에 v[0].first만큼 돌리고, v[0].second.first,v[0].second.second에서 시작함
	for(int i=0;i<picked.size();++i){
		int cur_idx=picked[i]; // 현재 재료 번호
		
		cur_impact=tool[cur_idx];
		int vj=v[i].first;
		for(int k=0;k<vj;++k){
			// rotate90(cur_impact);
			
			for (int u = 0; u < 4; ++u) {
			    for (int v = 0; v < 4; ++v) {
			        turned_impact[u][v] = {cur_impact[4 - 1 - v][u].first,cur_impact[4 - 1 - v][u].second};
			    }
			}
			cur_impact = turned_impact;
		}
		int cy=v[i].second.first;
		int cx=v[i].second.second;
		for(int y=cy;y<cy+4;++y){
			for(int x=cx;x<cx+4;++x){
				if(cur_impact[y-cy][x-cx].second!='W'){
					board[y][x].second=cur_impact[y-cy][x-cx].second;
				}
				board[y][x].first+=cur_impact[y-cy][x-cx].first;
				if(board[y][x].first<0){
					board[y][x].first=0;
				}
				if(board[y][x].first>9){
					board[y][x].first=9;
				}
					// board[y][x].first=max(0,board[y][x].first);
					// board[y][x].first=min(9,board[y][x].first);
			}
		}
	}
	// cur_impact=tool[idx];
	// for (int t = 0; t < turn_num; ++t) {
 //       vector<vector<pair<int,char>>> turned_impact(4, vector<pair<int,char>>(4));
 //       for (int i = 0; i < 4; ++i) {
 //           for (int j = 0; j < 4; ++j) {
 //               turned_impact[i][j] = {cur_impact[4 - 1 - j][i].first,cur_impact[4 - 1 - j][i].second};
 //           }
 //       }
 //       cur_impact = turned_impact;
 //   }
}

void board_init() {
    const char initChar = 'W';

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
        	board[i][j].first=0;
            board[i][j].second = initChar;
        }
    }
}
vector<pair<int,int>> left_up_pos;
void Input(){
	left_up_pos.push_back({0,0});
	left_up_pos.push_back({0,1});
	left_up_pos.push_back({1,0});
	left_up_pos.push_back({1,1});
	board_init();
	cin>>n;
	for(int i = 0; i < n; ++i) {
    	vector<vector<int>> tmp_impact(4, vector<int>(4));
    	vector<vector<char>> tmp_element(4, vector<char>(4));

    	for(int j = 0; j < 4; ++j) {
        	for(int k = 0; k < 4; ++k) {
            	cin >> tmp_impact[j][k];
        	}
    	}

    	for(int j = 0; j < 4; ++j) {
        	for(int k = 0; k < 4; ++k) {
            	cin >> tmp_element[j][k];
        	}
    	}

    	for(int j=0;j<4;++j){
    		for(int k=0;k<4;++k){
    			tool[i][j][k]={tmp_impact[j][k],tmp_element[j][k]};
    			// cout<<tool[i][j][k].first<<" "<<tool[i][j][k].second<<"\n";
    		}
    	}
    	
	}
}

int ans=-1222232421;
vector<int> picked;
vector<vector<pair<int,char>>> fst_tool(4,vector<pair<int,char>>(4)),sed_tool(4,vector<pair<int,char>>(4)),trd_tool(4,vector<pair<int,char>>(4)); //4*4
bool visited[10+1];
pair<int,pair<int,int>> v[3];
void pick(int idx){
	if(picked.size()==3){ // 0,1,2번째 재료를 pick
		for(int i=0;i<left_up_idx.size();++i){
			int fst_y=left_up_pos[left_up_idx[i][0]].first;
			int fst_x=left_up_pos[left_up_idx[i][0]].second;
			int sed_y=left_up_pos[left_up_idx[i][1]].first;
			int sed_x=left_up_pos[left_up_idx[i][1]].second;
			int trd_y=left_up_pos[left_up_idx[i][2]].first;
			int trd_x=left_up_pos[left_up_idx[i][2]].second;
			// left_up_idx[i][0]=fst, left_up_idx[i][1]=sed, left_up_idx[i][2]=trd
			// left_up_pos의 fst번째 idx, sed번째 idx, trd번째 idx를
			// picked의 0번째 idx, 1번째 idx, 2번째 idx에 적용
			for(int j=0;j<4;++j){
				for(int k=0;k<4;++k){
					for(int p=0;p<4;++p){
						board_init();
						v[0]={j,{fst_y,fst_x}};
						v[1]={k,{sed_y,sed_x}};
						v[2]={p,{trd_y,trd_x}};
						// v[1]
						turn(picked,v);
						int r_sum=0, b_sum=0, g_sum=0, y_sum=0;
						for(int y=0;y<5;++y){
							for(int x=0;x<5;++x){
								if(board[y][x].second=='R'){
									r_sum+=board[y][x].first;
								}
								if(board[y][x].second=='B'){
									b_sum+=board[y][x].first;
								}
								if(board[y][x].second=='G'){
									g_sum+=board[y][x].first;
								}
								if(board[y][x].second=='Y'){
									y_sum+=board[y][x].first;
								}
							}
						}
						ans=max(ans,7*r_sum+5*b_sum+3*g_sum+2*y_sum);
					}
				}
			}
		}
		return;
	}
	for(int i=0;i<n;++i){
		if(!visited[i]){
			visited[i]=1;
			picked.push_back(i);
			pick(idx+1);
			picked.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	left_up_pick();
	pick(0);
	cout<<ans;
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