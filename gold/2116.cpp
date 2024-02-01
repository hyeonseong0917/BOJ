#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int N;
const int MAX=10000+1;
vector<int> d[MAX];
vector<int> s[MAX];
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<6;++j){
			int a=0;
			cin>>a;
			d[i].push_back(a);
		}
	}
}
int transform_dice_idx(int idx){
	if(idx==0){
		return 5;
	}else if(idx==1){
		return 3;
	}else if(idx==2){
		return 4;
	}else if(idx==3){
		return 1;
	}else if(idx==4){
		return 2;
	}else if(idx==5){
		return 0;
	}
	return -1;
}
int turn_dice(int idx){
	for(int i=0;i<N;++i){
		s[i].clear();
	}
	int down_num, up_num;
	for(int i=0;i<N;++i){
		if(i==0){
			down_num=d[0][idx];
			up_num=d[0][transform_dice_idx(idx)];
			for(int j=0;j<6;++j){
				if(d[i][j]!=down_num && d[i][j]!=up_num){
					s[i].push_back(d[i][j]);
				}
			}
		}else{
			int cur_down_num=up_num;
			int down_idx=0, up_idx=0;
			for(int j=0;j<6;++j){
				if(d[i][j]==cur_down_num){
					down_idx=j;
					up_idx=transform_dice_idx(down_idx);
					break;
				}
			}
			up_num=d[i][up_idx];
			for(int j=0;j<6;++j){
				if(j!=down_idx && j!=up_idx){
					s[i].push_back(d[i][j]);
				}
			}
		}
	}
	int sum=0;
	for(int i=0;i<N;++i){
		int max_num=0;
		for(int j=0;j<s[i].size();++j){
			max_num=max(max_num,s[i][j]);
		}
		sum+=max_num;
	}
	return sum;
	// cout<<sum;
	
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	int ans=0;
	for(int i=0;i<6;++i){
		ans=max(ans,turn_dice(i));
	}
	cout<<ans;
	
	
	return 0;
}