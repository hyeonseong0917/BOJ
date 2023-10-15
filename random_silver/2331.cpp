#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

bool isRange(int y, int x){
	return (y>=1 && x>=0 && y<=6 && x<=5);
}

int dy[8]={-2,-2,2,2,-1,1,-1,1};
int dx[8]={-1,1,-1,1,-2,-2,2,2};
bool visited[10+1][10+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string pos="";
	string init_pos="";
	bool ans=1;
	map<string,int> m;
	for(int i=0;i<37;++i){
		string s;
		if(i<36){
			cin>>s;	
			if(!m[s]){
				m[s]=1;
			}else{
				ans=0;
			}
		}else{
			s=init_pos;
		}
		if(i==0){
			
			init_pos=s;
			pos=s;
		}else{
			//pos에서 s갈 수 있는지?
			bool can_go=0;
			int y=pos[1]-'0';
			int x=pos[0]-'A';
			for(int i=0;i<8;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(!isRange(ny,nx)) continue;
				if(ny==(s[1]-'0') && nx==(s[0]-'A')){
					can_go=1;
				}
			}
			if(!can_go){
				ans=0;
			}
			pos=s;
		}
	}
	if(!ans){
		cout<<"Invalid";
	}else{
		cout<<"Valid";
	}
	return 0;
}