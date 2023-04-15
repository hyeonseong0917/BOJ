#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

//1:35
// 질량, 방향, 위치(y,x), 속력,
//{{{질량, 방향},{y,x}},속력}
int N,M,K=0;
const int MAX=51+1;
int board[MAX][MAX]={0,}; //N*N
vector<int> r,c,m,s,d,flag;
// r:y, c:x, m:질량, s:속력, d:방향
void Input(){
	cin>>N>>M>>K;
	for(int i=0;i<M;++i){
		int rr,cc,mm,ss,dd;
		cin>>rr>>cc>>mm>>ss>>dd;
		r.push_back(rr);
		c.push_back(cc);
		m.push_back(mm);
		s.push_back(ss);
		d.push_back(dd);
		flag.push_back(1);
	}
	
}
bool isRange(int y, int x){
	return (y>=1 && x>=1 && y<=N && x<=N);
}

int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
// N==4
// 0 0 0 0
// 0 0 0 0 t
// 0 0 0 0
// 0 0 0 0
// 3,4 => 2,5 == 2,1 => 1,2 => 4,3 =>3,4
// r=y c=x
// board는 무엇인가? 점들의 위치를 ++하면서 저장

void solve(){
	while(K--){
		int cur_size=flag.size();
		int check[MAX][MAX]={0,};
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				check[i][j]=0;
			}
		}
		for(int i=0;i<cur_size;++i){
			if(flag[i]==0) continue;
			int y=r[i];
			int x=c[i];
			int dir=d[i];
			int move=s[i]%N;
			int ny=y+dy[dir]*move;
			int nx=x+dx[dir]*move;
			if(!isRange(ny,nx)){
				if(ny>N){
					ny-=N;
				}
				if(ny<1){
					ny+=N;
				}
				if(nx>N){
					nx-=N;
				}
				if(nx<1){
					nx+=N;
				}
			}
			r[i]=ny;
			c[i]=nx;
			
		}	
		vector<pair<int,int>> v;
		vector<pair<pair<int,int>,int>> tmp;
		bool visited[MAX][MAX]={0,};
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				visited[i][j]=0;
			}
		}
		for(int i=0;i<cur_size;++i){
			if(flag[i]==0) continue;
			++check[r[i]][c[i]];
			if(check[r[i]][c[i]]==2 && visited[r[i]][c[i]]==0){
				visited[r[i]][c[i]]=1;
				v.push_back({r[i],c[i]});
			}
			if(check[r[i]][c[i]]>=2){
				tmp.push_back({{r[i],c[i]},i});
			}
		}
		int vs=v.size();
		// cout<<"ge"<<vs<<endl;;
		for(int i=0;i<vs;++i){
			int y=v[i].first;
			int x=v[i].second;
			int msum=0, ssum=0, fsum=0;
			vector<int> dir;
			for(int j=0;j<tmp.size();++j){
				int cy=tmp[j].first.first;
				int cx=tmp[j].first.second;
				int cidx=tmp[j].second;
				if( cy==y &&  cx== x){
					
				}
			}
			// for(int j=0;j<cur_size;++j){
			// 	if(r[j]==y && c[j]==x && flag[j]==1){
			// 		flag[j]=0;
			// 		--check[y][x];
			// 		msum+=m[j];
			// 		ssum+=s[j];
			// 		++fsum;
			// 		dir.push_back(d[j]);
			// 	}
			// }
			int curm=msum/5;
			
			int curs=ssum/fsum;
			if(curm>0){
				bool isOdd=1, isEven=1;
				for(int j=0;j<dir.size();++j){
					if(dir[j]%2==0){
						isOdd=0;
						break;
					}
				}
				for(int j=0;j<dir.size();++j){
					if(dir[j]%2==1){
						isEven=0;
						break;
					}
				}
				if(isOdd==1 || isEven==1){
					int curDir[4]={0,2,4,6};
					for(int j=0;j<4;++j){
						r.push_back(y);
						c.push_back(x);
						m.push_back(curm);
						s.push_back(curs);
						d.push_back(curDir[j]);
						flag.push_back(1);
					}
				}else{
					int curDir[4]={1,3,5,7};
					for(int j=0;j<4;++j){
						r.push_back(y);
						c.push_back(x);
						m.push_back(curm);
						s.push_back(curs);
						d.push_back(curDir[j]);
						flag.push_back(1);
					}
				}
			}
			
		}
		// cout<<flag.size()<<endl;	
	}
	int ans=0;
	
	for(int i=0;i<flag.size();++i){
		if(flag[i]==1){
			// cout<<i<<" "<<m[i]<<endl;
			ans+=m[i];
		}
	}
	cout<<ans;
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}