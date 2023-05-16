#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX=20+1;
int board[MAX][MAX]={0,};
int N=0;
vector<int> v;
vector<bool> visited(MAX,0);
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
		v.push_back(i);
	}
}

int res=122232421;
void pick(int idx, int cnt){
	if(cnt==(N/2)){
		int pickSum=0;
		int npickSum=0;
		vector<int> p;
		vector<int> np;
		for(int i=0;i<N;++i){
			if(visited[i]){
				p.push_back(i);
			}else{
				np.push_back(i);
			}
		}
		for(int i=0;i<p.size();++i){
			for(int j=0;j<p.size();++j){
				if(i==j){
					continue;
				}
				pickSum+=board[p[i]][p[j]];
			}
		}
		for(int i=0;i<np.size();++i){
			for(int j=0;j<np.size();++j){
				if(i==j){
					continue;
				}
				npickSum+=board[np[i]][np[j]];
			}
		}
		res=min(res,abs(pickSum-npickSum));
	}
	if(idx==N){
		return;
	}
	
	for(int i=idx;i<N;++i){
		if(!visited[i]){
			visited[i]=1;
			pick(i,cnt+1);
			visited[i]=0;
		}
	}
}

int main() {
	// your code goes here
	Input();
	pick(0,0);
	cout<<res;
	return 0;
}