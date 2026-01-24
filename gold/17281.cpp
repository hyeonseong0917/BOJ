#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

// 1941
// 이닝 수 n이 주어짐. 각 선수가 각 이닝에서 얻는 결과들
// 1번선수를 4번타자로
// arr[i]: i번째 타자는 arr[i]번 선수
int arr[11];
// res[i][j]: i번 이닝에 j번 선수의 결과
int res[51][11];
bool visited[11];
int n;
int ans=0;
// 일단 1번~9번까지 선수의 순서를 정하고, 이닝을 진행한 결과에 따라 ans를 갱신
void dfs(int idx){
	if(idx==4){
		dfs(idx+1);
		return;
	}
	if(idx==10){
		// 이닝을 진행함
		// arr[i]: i번째 타자는 arr[i]번 선수
		bool flag=0;
		int cur_score=0;
		int cur_num=1;
		// base[i]: i루에 사람이 있다면 1
		int base[4]={0,0,0,0};
		for(int i=1;i<=n;++i){
			// i번째 이닝에 대해
			// 아웃카운트 3개면 종료
			// cur_num이 10이라면 1번부터 다시 시작
			if(cur_num==10){
				cur_num=1;
			}
			int out_cnt=0;
			while(1){
				if(out_cnt==3) break;
				// cur_num번째가 "가리키는" 선수가 진행한 결과가 cur_res임
				if(cur_num==10){
					cur_num=1;
				}
				int cur_player=arr[cur_num++];
				int cur_res=res[i][cur_player];
				if(cur_res==0){
					++out_cnt;
				}else if(cur_res==1){
					// 안타
					for(int j=3;j>=1;--j){
						if(j==3){
							if(base[j]){
								base[j]=0;
								++cur_score;
							}
							continue;
						}
						if(base[j]){
							++base[j+1];
							base[j]=0;
						}
					}
					++base[1];
				}else if(cur_res==2){
					// 2루타
					for(int j=3;j>=1;--j){
						if(j>=2){
							if(base[j]){
								base[j]=0;
								++cur_score;
							}
							continue;
						}
						if(base[j]){
							++base[j+2];
							base[j]=0;
						}
					}
					++base[2];
				}else if(cur_res==3){
					// 3루타
					for(int j=3;j>=1;--j){
						if(j>=1){
							if(base[j]){
								base[j]=0;
								++cur_score;
							}
							continue;
						}
						if(base[j]){
							++base[j+3];
							base[j]=0;
						}
					}
					base[3]=1;
				}else{
					// 홈런
					for(int j=3;j>=1;--j){
						if(j>=1){
							if(base[j]){
								base[j]=0;
								++cur_score;
							}
							continue;
						}
						base[j]=0;
					}
					++cur_score;
				}
			}
			// 이닝 종료되면 base초기화
			for(int j=1;j<=3;++j){
				base[j]=0;
			}
		}
		ans=max(ans,cur_score);
		return;
	}
	for(int i=2;i<=9;++i){
		if(visited[i]) continue;
		// i번째 선수를 몇 번째 타자로 배치?
		visited[i]=1;
		arr[idx]=i;
		dfs(idx+1);
		arr[idx]=0;
		visited[i]=0;
	}

}
void Input(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=9;++j){
			cin>>res[i][j];
		}
	}
}
void Init(){
	ans=0;
	for(int i=1;i<=10;++i){
		arr[i]=0;
		visited[i]=0;
	}
	// 4번 타자는 1번임
	arr[4]=1;
	visited[1]=4;
	for(int i=0;i<=50;++i){
		for(ll j=0;j<=10;++j){
			res[i][j]=0;
		}
	}
}
void Solve(){
	dfs(1);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Init();
		Input();
		Solve();
		cout<<ans;
	}
	return 0;
}