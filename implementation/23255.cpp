#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}

int main() {
	// your code goes here
	int N,M=0;
	cin>>N>>M;
	const int MAX=100000+1;
	vector<int> graph[MAX];
	int color[MAX]={0,};
	for(int i=0;i<M;++i){
		int a=0,b=0;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=1;i<=N;++i){
		vector<int> near;
		map<int,int> m;
		for(int j=0;j<graph[i].size();++j){
			int curNum=color[graph[i][j]];
			if(m[curNum]==0){
				m[curNum]=1;
				near.push_back(curNum);
			}
		}
		sort(near.begin(),near.end());
		int cnt=1;
		if(near[0]==0){
			
			for(int j=1;j<near.size();++j){
				if(near[j]==cnt){
					++cnt;
				}else{
					break;
				}
			}
		}else{
			
			for(int j=0;j<near.size();++j){
				if(near[j]==cnt){
					++cnt;
				}else{
					break;
				}
			}
		}
		color[i]=cnt;
	}
	for(int i=1;i<=N;++i){
		cout<<color[i]<<" ";
	}
	
	return 0;
}