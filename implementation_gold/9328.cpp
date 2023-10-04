#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

// 빌딩의 문을 열려면 열쇠가 필요
// 일부 열쇠 이미 가지고 있거나 바닥에 있음
// 훔칠 수 있는 문서의 최대 개수

// $: 문서, *: 벽, 대문자: 문, 소문자: 열쇠, .: 빈 공간 
// 1. 어디서 출발할 수 있는가?
int t=0;
const int MAX=100+5;
vector<char> door_key;
vector<pair<int,int>> start_pos;
char board[MAX][MAX];
bool visited[MAX][MAX];
bool money_check[MAX][MAX];
map<char,int> isKeyExist;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int h,w;
bool check[MAX][MAX];
queue<pair<int,int>> door[26+1];

void Init(){
	door_key.clear();
	start_pos.clear();
	// isKeyExist.clear();
	for(int i=0;i<26;++i){
		isKeyExist['a'+i]=0;
		door[i]=queue<pair<int,int>>();
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]='.';
			visited[i][j]=0;
			money_check[i][j]=0;
			check[i][j]=0;
		}
	}
}
bool isRange(int y, int x){
	return (y>=1 && x>=1 && y<h-1 && x<w-1);
}
string capital_letter="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void get_start_pos(int y, int x){
	if(board[y][x]!='*'){
		if(board[y][x]=='.'){
			start_pos.push_back({y,x});
		}else{
			bool isCapital=0;
			for(int i=0;i<26;++i){
				if(capital_letter[i]==board[y][x]){
					isCapital=1;
					break;
				}
			}
			if(isCapital){
				start_pos.push_back({y,x});
			}else{
				start_pos.push_back({y,x});
				if(!isKeyExist[board[y][x]] && board[y][x]!='$'){
					isKeyExist[board[y][x]]=1;
					door_key.push_back(board[y][x]);
				}
				
			}
			
		}
	}
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0 || nx<0 || ny>h-1 || nx>w-1) continue;
		if(visited[ny][nx]) continue;
		if(ny==0 || nx==0 || ny==h-1 || nx==w-1){
			visited[ny][nx]=1;
			get_start_pos(ny,nx);
		}
	}
}
int max_num=0;

// 1. 테두리를 제외한 정점들
// 2. 열쇠를 주웠을 때 가지고 있는 문 좌표들 중 현재 열쇠와 해당하는 좌표가 있다면 해당 좌표로 이동
// 2-1. 방문한 지점들 중 문이 없다면 열쇠 가지고 있기
// 2-2. 문을 방문했을 때 열쇠가 없다면 방문하지 못했던 문 좌표 갖고있기
// 
// vector<int> tmp;

void bfs(int y, int x){
	queue<pair<int,int>> q;
	
	q.push({y,x});
	check[y][x]=1;
	int res=0;
	
	while(!q.empty()){
		int cy=q.front().first;
		int cx=q.front().second;
		// cout<<board[cy][cx]<<endl;
		q.pop();
		bool isOpen=1;
		if(board[cy][cx]=='$'){
			check[cy][cx]=1;
			// ++max_num;
			if(!money_check[cy][cx]){
				money_check[cy][cx]=1;
				++max_num;
				// cout<<cy<<" "<<cx<<endl;
			}
			
		}else if(board[cy][cx]!='.'){
			if(board[cy][cx]-'a'<0){
				// 대문자
				// 해당 문을 열 수 있는지?
				// cout<<board[cy][cx]<<endl;
				check[cy][cx]=1;
				bool flag=0;
				for(int i=0;i<door_key.size();++i){
					if(door_key[i]-'a'==board[cy][cx]-'A'){
						flag=1;
						break;
					}
				}
				if(!flag){
					isOpen=0;	
					door[board[cy][cx]-'A'].push({cy,cx});
					
				} 
				
				
			}else{
				//소문자
				if(!isKeyExist[board[cy][cx]]){
					isKeyExist[board[cy][cx]]=1;
					door_key.push_back(board[cy][cx]);
				}
				
				if(!door[board[cy][cx]-'a'].empty()){
					int ds=door[board[cy][cx]-'a'].size();
					for(int i=0;i<ds;++i){
						q.push(door[board[cy][cx]-'a'].front());
						door[board[cy][cx]-'a'].pop();
					}

				}
				check[cy][cx]=1;
			}
		}else{
			check[cy][cx]=1;
		}
		if(isOpen==0) continue;
		for(int i=0;i<4;++i){
			int ny=cy+dy[i];
			int nx=cx+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]=='*') continue;
			if(check[ny][nx]) continue;
			check[ny][nx]=1;
			q.push({ny,nx});
			
		}

	}
	
}



int main() {
	// your code goes here
	cin>>t;
	while(t--){
		Init();
		max_num=0;
		cin>>h>>w;
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				cin>>board[i][j];
			}
		}
		string cur_key;
		cin>>cur_key;
		if(cur_key!="0"){
			for(int i=0;i<cur_key.size();++i){
				door_key.push_back(cur_key[i])	;
			}
		}
		
		visited[0][0]=1;
		get_start_pos(0,0);
		if(start_pos.empty()){
			cout<<0<<"\n";	
			continue;
		}

		for(int i=0;i<start_pos.size();++i){
			int y=start_pos[i].first;
			int x=start_pos[i].second;
			bfs(y,x);
			// cout<<y<<" "<<x<<" "<<board[y][x]<<endl;
		}
		cout<<max_num<<endl;
		// for(int i=0;i<door_key.size();++i){
		// 	cout<<door_key[i]<<" ";
		// }

		
	}
	// cout<<bfs(v);
	return 0;
}