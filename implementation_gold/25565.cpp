#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long


int N,M,K;
const int MAX=2000+1;
int arr[MAX][MAX];
bool check[MAX][MAX];
bool tmp_check[MAX][MAX];
vector<pair<int,int>> ans;
vector<pair<int,int>> fst_seed, sed_seed;
map<pair<int,int>,int> m;
void Input(){
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){		
			cin>>arr[i][j];
			check[i][j]=0;
			tmp_check[i][j]=0;
			if(arr[i][j]){
				check[i][j]=1;
			}
		}
	}
}
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
// fst_seed를 채우는 방법: 0,0에서부터 1 발견 시 (가로 혹은 세로, check[좌표]=0)
// sed_seed를 채우는 방법: 0,0에서부터 1 발견 시 (가로 혹은 세로, check가 모두 0이면 clear, 아니면 다시 1로 채우기)

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}

void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(arr[i][j] && fst_seed.empty()){
				//가로
				if(j+K<=M){
					bool isHorizontal=1;	
					for(int p=j;p<j+K;++p){
						if(!arr[i][p]){
							isHorizontal=0;
							break;
						}
					}
					if(isHorizontal){
						for(int p=j;p<j+K;++p){
							check[i][p]=0;
							fst_seed.push_back({i,p});
						}	
					}
				}
				if(!fst_seed.empty()){
					break;
				}
				if(i+K<=N){
					bool isVertical=1;
					for(int p=i;p<i+K;++p){
						if(!arr[p][j]){
							isVertical=0;
							break;
						}
					}
					if(isVertical){

						for(int p=i;p<i+K;++p){
							check[p][j]=0;
							fst_seed.push_back({p,j});
						}
					}
				}
				
			}
			if(!fst_seed.empty()){
				break;
			}
		}
		if(!fst_seed.empty()){
			break;
		}
	}
	vector<pair<int,int>> tmp_pos;
	for(int i=N-1;i>=0;--i){
		for(int j=M-1;j>=0;--j){
			
			if(arr[i][j] && check[i][j] && sed_seed.empty()){
				if(j+1-K>=0){
					bool isHorizontal=1;	

					for(int p=j;p>=j-K+1;--p){
						if(!arr[i][p]){
							isHorizontal=0;
							break;
						}
					}
					// cout<<i<<" "<<j<<" "<<check[i][j]<<" "<<isHorizontal<<endl;
					if(isHorizontal){
						for(int p=j;p>=j-K+1;--p){
							check[i][p]=0;
							sed_seed.push_back({i,p});
						}	
					}
				}
				if(!sed_seed.empty()){
					break;
				}
				if(i-K+1>=0){
					bool isVertical=1;
					for(int p=i;p>=i-K+1;--p){
						if(!arr[p][j]){
							isVertical=0;
							break;
						}
					}
					if(isVertical){
						for(int p=i;p>=i-K+1;--p){
							check[p][j]=0;
							sed_seed.push_back({p,j});
						}
					}
				}
			}
			if(!sed_seed.empty()){
				break;
			}

		}
		if(!sed_seed.empty()){
			break;
		}
	}
	if(sed_seed.empty()){
		for(int i=0;i<fst_seed.size();++i){
			int y=fst_seed[i].first;
			int x=fst_seed[i].second;
			int flag=-1;
			for(int j=0;j<4;++j){
				int ny=y+dy[j];
				int nx=x+dx[j];
				if(!isRange(ny,nx)) continue;
				if(check[ny][nx]==1){
					flag=j;
					break;
				}
			}
			if(flag!=-1){
				sed_seed.push_back({y,x});
				for(int j=0;j<K;++j){
					sed_seed.push_back({y+dy[flag]*i,x+dx[flag]*i});
				}
			}
		}
		if(sed_seed.empty()){
			sed_seed=fst_seed;
		}
		
	}
	// cout<<sed_seed.size()<<endl;
	// for(int i=0;i<fst_seed.size();++i){
	// 	cout<<fst_seed[i].first<<" "<<fst_seed[i].second<<endl;
	// }
	// for(int i=0;i<sed_seed.size();++i){
	// 	cout<<sed_seed[i].first<<" "<<sed_seed[i].second<<endl;
	// }
	int cnt=0;
	for(int i=0;i<fst_seed.size();++i){
		m[fst_seed[i]]=1;
	}
	for(int i=0;i<sed_seed.size();++i){
		if(m[sed_seed[i]]){
			ans.push_back(sed_seed[i]);
		}
	}
	sort(ans.begin(),ans.end(),comp);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();++i){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
	}

}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}