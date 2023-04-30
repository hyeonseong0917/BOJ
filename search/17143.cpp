#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int R,C,M;
const int MAX=100+1;
int board[MAX][MAX];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
//1156
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
vector<pair<pair<int,int>,pair<pair<int,int>,int>>> v;
// {{y,x},{{s,d},z}}
void Input(){
	cin>>R>>C>>M;
	for(int i=0;i<M;++i){
		int a,b,c,d,e=0;
		cin>>a>>b>>c>>d>>e;
		v.push_back({{a-1,b-1},{{c,d-1},e}});
	}
}
bool comp(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}
int sum=0;
void solve(){
	int curIdx=-1;
	while(1){
		++curIdx;
		if(curIdx==C){
			break;
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				board[i][j]=0;
			}
		}
		vector<pair<int,int>> del_whale;
		for(int i=0;i<v.size();++i){
			if(v[i].first.second==curIdx){
				del_whale.push_back({v[i].first.first,curIdx});
			}
		}
		
		if(del_whale.size()){
			sort(del_whale.begin(),del_whale.end(),comp);
			pair<int,int> to_del=del_whale[0];	
			vector<pair<pair<int,int>,pair<pair<int,int>,int>>> p;
			
			for(int i=0;i<v.size();++i){
				if(make_pair(v[i].first.first, v[i].first.second)==to_del){
					sum+=v[i].second.second;
					continue;	
				} 
				p.push_back(v[i]);
			}
			// cout<<p.size();
			v.clear();
			v=p;
			// cout<<v.size();
		}
		vector<pair<int,int>> multi_whale;
		for(int i=0;i<v.size();++i){
			int y=v[i].first.first;
			int x=v[i].first.second;
			int s=v[i].second.first.first;
			int d=v[i].second.first.second;
			int z=v[i].second.second;
			if(d==2 || d==3){
				s%=((C-1)*2);
			}else if(d==0 || d==1){
				s%=((R-1)*2);
			}
			//이동
			while(s){
				--s;
				y+=dy[d];
				x+=dx[d];
				if(!isRange(y,x)){
					y-=dy[d];
					x-=dx[d];
					if(d==0){
						d=1;
					}else if(d==1){
						d=0;
					}else if(d==2){
						d=3;
					}else if(d==3){
						d=2;
					}
					y+=dy[d];
					x+=dx[d];
				}
			}
			v[i].first.first=y;
			v[i].first.second=x;
			++board[y][x];
			if(board[y][x]>=2){
				multi_whale.push_back({y,x});
			}
			v[i].second.first.second=d;
		}
		vector<int> whale_size;
		vector<pair<pair<int,int>,pair<pair<int,int>,int>>> tmp;
		for(int i=0;i<multi_whale.size();++i){
			whale_size.clear();
			tmp.clear();
			int cy=multi_whale[i].first;
			int cx=multi_whale[i].second;
			
			for(int k=0;k<v.size();++k){
				if(v[k].first.first==cy && v[k].first.second==cx){
					whale_size.push_back(v[k].second.second);
				}
			}
			sort(whale_size.begin(),whale_size.end());
			reverse(whale_size.begin(),whale_size.end());
			for(int k=0;k<v.size();++k){
				if(v[k].first.first==cy && v[k].first.second==cx){
					if(v[k].second.second==whale_size[0]){
						tmp.push_back(v[k]);
					}
				}else{
					tmp.push_back(v[k]);
					}
			}
			v.clear();
			v=tmp;	
		}
		
		// break;
	}
	cout<<sum;
	// for(int i=0;i<v.size();++i){
	// 	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second.first.second<<endl;
	// }
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}