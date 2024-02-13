#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int N,K;
const int MAX=9+1;
int arr[MAX][MAX];
vector<int> k,m;
void Input(){
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<20;++i){
		int a=0;
		cin>>a;
		k.push_back(a);
	}
	for(int i=0;i<20;++i){
		int a=0;
		cin>>a;
		m.push_back(a);
	}
}
vector<int> jiwoo;
bool visited[MAX];
bool game(){
	int j_cnt=0; // 0
	int k_cnt=0; // 1
	int m_cnt=0; // 2
	int idx=0;
	int j_idx=0, k_idx=0, m_idx=0;
	bool check=0;
	int cur_num=0;
	int next_num=1;
	while(1){
		// cur_num과 next_num싸움
		if(j_idx==N || j_idx==20 || k_idx==20){
			break;
		}
		if(cur_num==0){
			// 0과 1
			if(next_num==1){
				int num=arr[jiwoo[j_idx++]][k[k_idx++]];
				if(num==2){
					++j_cnt;
					next_num=2;
				}else if(num==1){
					++k_cnt;
					cur_num=next_num;
					next_num=2;
				}else{
					++k_cnt;
					cur_num=next_num;
					next_num=2;
				}
			}else{
				// 0과 2
				int num=arr[jiwoo[j_idx++]][m[m_idx++]];
				if(num==2){
					++j_cnt;
					next_num=1;
				}else if(num==1){
					++m_cnt;
					cur_num=next_num;
					next_num=1;
				}else{
					++m_cnt;
					cur_num=next_num;
					next_num=1;
				}
			}
		}else if(cur_num==1){
			if(next_num==0){
				// 1과 0
				int num=arr[k[k_idx++]][jiwoo[j_idx++]];
				if(num==2){
					++k_cnt;
					next_num=2;
				}else if(num==1){
					++k_cnt;
					next_num=2;
				}else{
					++j_cnt;
					cur_num=next_num;
					next_num=2;
				}
			}else{
				// 1과 2
				int num=arr[k[k_idx++]][m[m_idx++]];
				if(num==2){
					++k_cnt;
					next_num=0;
				}else if(num==1){
					++m_cnt;
					cur_num=next_num;
					next_num=0;
				}else{
					++m_cnt;
					cur_num=next_num;
					next_num=0;
				}
			}
		}else if(cur_num==2){
			// 0과 2
			if(next_num==0){
				int num=arr[m[m_idx++]][jiwoo[j_idx++]];
				if(num==2){
					++m_cnt;
					next_num=1;
				}else if(num==1){
					++m_cnt;
					next_num=1;
				}else{
					++j_cnt;
					cur_num=next_num;
					next_num=1;
				}
			}else{
				int num=arr[m[m_idx++]][k[k_idx++]];
				if(num==2){
					++m_cnt;
					next_num=0;
				}else if(num==1){
					++m_cnt;
					next_num=0;
				}else{
					++k_cnt;
					cur_num=next_num;
					next_num=0;
				}
			}
		}
		++idx;
		// cout<<k_idx<<" "<<m_idx<<" "<<k_idx<<" "<<cur_num<<" "<<next_num<<endl;
		// cout<<j_cnt<<" "<<k_cnt<<" "<<m_cnt<<" "<<idx<<endl;
		if(j_cnt==K || k_cnt==K || m_cnt==K){
			// for(int i=0;i<N;++i){
			// 	cout<<jiwoo[i]<<" ";
			// }cout<<endl;
			
			break;
		}
	}
	if(j_cnt==K){
		// cout<<idx<<endl;
		return 1;
	}else{
		return 0;
	}
}
bool flag=0;
void pick(){
	if(jiwoo.size()==N){
		if(flag) return;
		// for(int i=0;i<jiwoo.size();++i){
		// 	cout<<jiwoo[i];
		// }cout<<endl;
		if(game()){
			flag=1;
		}
		return;
	}
	for(int i=1;i<=N;++i){
		if(!visited[i]){
			visited[i]=1;
			jiwoo.push_back(i);
			pick();
			visited[i]=0;
			jiwoo.pop_back();
		}
	}
}

void solve(){
	pick();
	cout<<flag;
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