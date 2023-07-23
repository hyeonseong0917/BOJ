#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,K;
int R,C;
const int MAX=100+1;
vector<vector<vector<int>>> v;
int board[MAX][MAX];
void Input(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	cin>>N>>M>>K;
	for(int i=0;i<K;++i){
		int r,c;
		cin>>r>>c;
		vector<vector<int>> tmp_v;
		for(int j=0;j<r;++j){
			vector<int> tmp_tmp_v;
			for(int k=0;k<c;++k){
				int a=0;
				cin>>a;
				tmp_tmp_v.push_back(a);
			}
			tmp_v.push_back(tmp_tmp_v);
		}
		v.push_back(tmp_v);
	}
}

bool stick(vector<vector<int>> cur_sticker,int r,int c){
	bool flag=0;
	for(int i=0;i<N;++i){
		if(i+r>N){
			break;
		}
		if(flag==1) break;
		for(int j=0;j<M;++j){
			if(j+c>M){
				break;
			}
			//i,j에서 스티커를 붙일 수 있는지
			
			bool isStick=1;
			for(int k=i;k<i+r;++k){
				for(int q=j;q<j+c;++q){
					if(cur_sticker[k-i][q-j]==1){
						if(board[k][q]==0){
							// board[k][q]=1;
						}else{
							isStick=0;
							break;
						}
					}
				}
				if(isStick==0){
					break;
				}
			}
			if(isStick==1){
				for(int k=i;k<i+r;++k){
					for(int q=j;q<j+c;++q){
						if(cur_sticker[k-i][q-j]==1){
							board[k][q]=1;
						}
					}
				}
				flag=1;
				break;
			}
			
		}
	
	}
	return flag;
	
}
vector<vector<int>> turn_sticker(vector<vector<int>> cur_sticker){
	vector<vector<int>> new_sticker;
	for(int i=0;i<cur_sticker[0].size();++i){
		vector<int> new_tmp_sticker;
		for(int j=cur_sticker.size()-1;j>=0;--j){
			new_tmp_sticker.push_back(cur_sticker[j][i]);
		}
		new_sticker.push_back(new_tmp_sticker);
	}
	return new_sticker;
	
}
void solve(){
	for(int i=0;i<v.size();++i){
		vector<vector<int>> cur_sticker=v[i];
		bool first_flag=stick(cur_sticker,cur_sticker.size(),cur_sticker[0].size());
		if(first_flag==1) continue;
		//90
		cur_sticker=turn_sticker(cur_sticker);
		bool second_flag=stick(cur_sticker,cur_sticker.size(),cur_sticker[0].size());
		if(second_flag==1) continue;

		//180
		cur_sticker=turn_sticker(cur_sticker);
		bool third_flag=stick(cur_sticker,cur_sticker.size(),cur_sticker[0].size());
		if(third_flag==1) continue;

		//270
		cur_sticker=turn_sticker(cur_sticker);
		bool fourth_flag=stick(cur_sticker,cur_sticker.size(),cur_sticker[0].size());
		if(fourth_flag==1) continue;
	}
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(board[i][j]==1){
				++cnt;
			}
		}
	}
	cout<<cnt;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}