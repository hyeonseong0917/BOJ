#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N=0;
const int MAX=11+1;
vector<int> g[MAX];
int num[MAX];
int d[MAX][MAX];
bool visited[MAX];
bool check[MAX];
vector<int> v;
vector<int> r;
int totalSum=0;
int minNum=122232421;
void Input(){
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			d[i][j]=0;
		}
	}
	for(int i=1;i<=N;++i){
		cin>>num[i];
	}
	for(int i=1;i<=N;++i){
		int s=0;
		cin>>s;
		for(int j=0;j<s;++j){
			int a=0;
			cin>>a;
			g[i].push_back(a);
			d[i][a]=1;
			d[a][i]=1;
		}
	}
	// cout<<g[4][1];
}
void dfs(int curNum){
	for(int i=1;i<=N;++i){
		if(check[i]==1 && d[curNum][i]){
			check[i]=0;
			dfs(i);
		}
	}
}
void pick(int cnt, int idx){
	if(cnt==0){
		for(int i=1;i<=N;++i){
			check[i]=0;
		}
		for(int i=0;i<v.size();++i){
			check[v[i]]=1;
		}
		check[v[0]]=0;
		dfs(v[0]);
		bool flag=0;
		for(int i=0;i<v.size();++i){
			if(check[v[i]]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			return;
		}
		r.clear();
		for(int i=1;i<=N;++i){
			check[i]=0;
		}
		for(int i=0;i<v.size();++i){
			check[v[i]]=1;
		}
		for(int i=1;i<=N;++i){
			if(!check[i]){
				r.push_back(i);
			}
		}
		for(int i=0;i<v.size();++i){
			check[v[i]]=0;
		}
		for(int i=0;i<r.size();++i){
			check[r[i]]=1;
		}
		check[r[0]]=0;
		dfs(r[0]);
		for(int i=0;i<r.size();++i){
			if(check[r[i]]){
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			return;
		}
		
		int firstNum=0, secondNum=0;
		for(int i=0;i<v.size();++i){
			firstNum+=num[v[i]];
		}
		for(int i=0;i<r.size();++i){
			secondNum+=num[r[i]];
		}
		minNum=min(minNum,abs(firstNum-secondNum));
		// cout<<endl;
		return;
	}
	if(idx>=N){
		return;
	}
	for(int i=idx;i<=N;++i){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			pick(cnt-1,i);
			visited[i]=0;
			v.pop_back();
		}
	}
}
void solve(){
	for(int i=1;i<=N-1;++i){
		for(int j=1;j<=N;++j){
			visited[j]=0;
		}
		v.clear();
		pick(i,1);
	}
	if(minNum==122232421){
		minNum=-1;
	}
	cout<<minNum;
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}