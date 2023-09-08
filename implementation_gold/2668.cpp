#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

int N;
const int MAX=100+1;
bool visited[MAX];
int arr[MAX];
vector<int> ans;
vector<int> tmp;
map<int,int> m;

void Input(){
	for(int i=0;i<MAX;++i){
		arr[i]=0;
	}
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
}

void dfs(int init_num, int cur_num, bool is_init){
	if(cur_num==init_num && !is_init){
		for(int i=0;i<tmp.size();++i){
			if(!m[tmp[i]]){
				m[tmp[i]]=1;
				ans.push_back(tmp[i]);
			}
			
		}
		return;
	}
	int next_num=arr[cur_num];
	if(!visited[next_num] && next_num!=0){
		if(next_num!=init_num){
			tmp.push_back(next_num);
		}
		
		visited[next_num]=1;
		dfs(init_num,next_num,0);
	}
}

void solve(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			visited[j]=0;
		}
		tmp.clear();
		tmp.push_back(i);
		dfs(i,i,1);
	}
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<"\n";
	}
}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	// cout<<bfs(v);
	return 0;
}