#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N=0;
vector<pair<pair<int,int>,pair<pair<int,int>,int>>> food;
bool visited[15+1]={0,};
int mp,mf,ms,mv;
void Input(){
	cin>>N;
	cin>>mp>>mf>>ms>>mv;
	for(int i=0;i<N;++i){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		food.push_back({{a,b},{{c,d},e}});
	}
}
//a벡터가 더 빠른지?
bool isFirstFast(vector<int> a, vector<int> b){
	for(int i=0;i<a.size();++i){
		int curA=a[i];
		int curB=b[i];
		if(curA<curB){
			return 1;
		}
		if(curB<curA){
			return 0;
		}
	}
	return 1;
}
vector<int> ans;
vector<int> pick_idx;
int cost=122232421;

void dfs(int cnt, int idx){
	if(cnt!=0){
		pick_idx.clear();
		int p=0,f=0,s=0,v=0;
		int cur_cost=0;
		for(int i=0;i<N;++i){
			if(visited[i]==1){
				pick_idx.push_back(i);
				// cout<<i<<" ";
				p+=food[i].first.first;
				f+=food[i].first.second;
				s+=food[i].second.first.first;
				v+=food[i].second.first.second;
				cur_cost+=food[i].second.second;
			}
		}
		if(p>=mp && f>=mf && s>=ms && v>=mv && cur_cost<=cost){
			if(cur_cost<cost){
				ans.clear();
				ans=pick_idx;
			}else{
				if(ans.size()==0){
					ans=pick_idx;
				}else{
					if(isFirstFast(pick_idx,ans)){
						ans=pick_idx;
					}	
				}
				
			}
			cost=cur_cost;
		}
	}
	if(cnt>=N){
		return;
	}
	
	for(int i=idx;i<N;++i){
		if(!visited[i]){
			visited[i]=1;
			dfs(cnt+1,i);
			visited[i]=0;
		}
	}
	
}
void solve(){
	// dfs(3,0);
	// for(int i=1;i<=N;++i){
	// 	for(int j=0;j<16;++j){
	// 		visited[j]=0;
	// 	}
	// 	dfs(i,0);
	// }
	dfs(0,0);
	if(cost!=122232421){
		cout<<cost<<endl;
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]+1<<" ";
		}	
	}else{
		cout<<-1;
	}
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}