#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//1051
int N,M;
const int MAX=500+1;
int board[MAX][MAX];
bool comp(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
}
int main() {
	// your code goes here
	while(1){
		cin>>N>>M;
		if(N==0 && M==0){
			break;
		}
		for(int i=0;i<MAX;++i){
			for(int j=0;j<MAX;++j){
				board[i][j]=0;
			}
		}
		//
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin>>board[i][j];
			}
		}
		int num[10000+1]={0,};
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				++num[board[i][j]];
			}
		}
	
		bool check[10000+1]={0,};
		vector<pair<int,int>> v;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(!check[board[i][j]]){
					check[board[i][j]]=1;
					v.push_back({board[i][j],num[board[i][j]]});
				}
			}
		}
		sort(v.begin(),v.end(),comp);
		int secondNum=v[1].second;
		vector<int> res;
		for(int i=1;i<v.size();++i){
			if(v[1].second==v[i].second){
				res.push_back(v[i].first);
			}else{
				break;
			}
		}
		sort(res.begin(),res.end());
		for(int i=0;i<res.size();++i){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}