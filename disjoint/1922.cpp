#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
const int MAX=1000+1;
vector<pair<int,pair<int,int>>> v;
int sum=0;
int parent[MAX];
int mst_cnt=0;
void Input(){
	cin>>N;
	cin>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==b) continue;
		v.push_back({c,{a,b}});
	}

}
int find_root(int x){
	if(x==parent[x]) return x;
	return  parent[x]=find_root(parent[x]);
}
void union_root(int x, int y){
	x=find_root(x);
	y=find_root(y);
	if(x!=y) parent[y]=x;
}

void solve(){
	for(int i=1;i<MAX;++i){
		parent[i]=i;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		int cur_dist=v[i].first;
		int cur_from=v[i].second.first;
		int cur_to=v[i].second.second;
		if(mst_cnt==N-1){
			break;
		}
		if(find_root(cur_from)==find_root(cur_to)) continue;
		union_root(cur_from, cur_to);
		++mst_cnt;
		sum+=cur_dist;
	}
	cout<<sum<<endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}