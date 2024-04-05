#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
#define ll long long

char board[5+1][5+1];
void Input(){
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cin>>board[i][j];
		}
	}
}
vector<pair<int,int>> v;
map<vector<pair<int,int>>,int> m;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<5 && x<5);
}
bool visited[5+1][5+1];
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
int ans=0;
void pick(int y, int x){
	if(v.size()==7){
		
		int y_cnt=0;
		for(int i=0;i<v.size();++i){
			if(board[v[i].first][v[i].second]=='Y'){
				++y_cnt;
			}
		}
		if(y_cnt>=4){
			return;
		}
		// for(int i=0;i<v.size();++i){
		// 	cout<<"("<<v[i].first<<" "<<v[i].second<<"),";
		// }cout<<endl;
		sort(v.begin(),v.end(),comp);
		if(m[v]){
			return;
		}
		++m[v];

		// v의 좌표들이 이어져 있는지?
		queue<pair<int,int>> q;
		bool check[5+1][5+1];
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j){
				check[i][j]=0;
			}
		}
		q.push(v[0]);
		check[v[0].first][v[0].second]=1;
		int cnt=1;
		while(!q.empty()){
			// a=1;
			int y=q.front().first;
			int x=q.front().second;
			q.pop();
			for(int i=0;i<4;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(!isRange(ny,nx)) continue;
				if(check[ny][nx]) continue;
				check[ny][nx]=1;
				bool flag=0;
				for(int j=1;j<7;++j){
					if(make_pair(ny,nx)==v[j]){
						flag=1;
						break;
					}
				}
				if(flag){
					++cnt;
					q.push({ny,nx});
				}
			}
		}
		
		if(cnt==7){
			int s_cnt=0;
			for(int i=0;i<v.size();++i){
				// cout<<v[i].first<<" "<<v[i].second<<endl;
				if(board[v[i].first][v[i].second]=='S'){
					++s_cnt;
				}
			}
			if(s_cnt>=4){
				++ans;
			}
		}
		return;
	}
	// if(y==4 && x==4){
	// 	cout<<"he";
	// }
	if(x+1==5){
		if(y+1!=5){
			pick(y+1,0);
		}else{
			if(v.size()!=6){
				return;
			}
		}
	}else{
		pick(y,x+1);	
	}
	// if(y==4 && x==4){
	// 	cout<<"he";
	// }
	v.push_back({y,x});
	if(v.size()==7){
		// if(y==4 && x==4){
		// 	cout<<"he";
		// }
		// cout<<y<<" "<<x<<endl;
		pick(y,x);
	}else{
		if(x+1==5){
			if(y+1!=5){
				pick(y+1,0);
			}
		}else{
			pick(y,x+1);	
		}	
	}
	v.pop_back();
}

int main() {
	// your code goes here
	Input();
	pick(0,0);
	cout<<ans;
	return 0;
}