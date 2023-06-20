#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


//1509
int N=0;
vector<int> v;
vector<int> res;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		res.push_back(a);
		v.push_back(i+1);
	}
}
int maxK=0;
void mixCard(int K){
	bool flag=0;
	vector<int> pre_move;
	vector<int> cur_choice;
	vector<int> new_v;
	while(K>=0){
		if(flag==0){
			flag=1;
			int back_choice=pow(2,K);
			cur_choice.clear();
			new_v.clear();
			for(int i=0;i<back_choice;++i){
				cur_choice.push_back(v[N-1-i]);
			}
			reverse(cur_choice.begin(),cur_choice.end());
			pre_move=cur_choice;
			for(int i=0;i<cur_choice.size();++i){
				new_v.push_back(cur_choice[i]);
			}
			for(int i=0;i<N-pow(2,K);++i){
				new_v.push_back(v[i]);
			}
			v=new_v;
			// for(int i=0;i<N;++i){
			// 	cout<<v[i]<<" ";
			// }cout<<endl;
			--K;
		}else{
			int back_choice=pow(2,K);
			int kIdx=0;
			cur_choice.clear();
			new_v.clear();
			map<int,int> m;
			for(int i=0;i<back_choice;++i){
				int curNum=pre_move[pre_move.size()-1-i];
				cur_choice.push_back(curNum);
				m[curNum]=1;
			}
			reverse(cur_choice.begin(),cur_choice.end());
			pre_move=cur_choice;
			new_v=cur_choice;
			for(int i=0;i<v.size();++i){
				if(m[v[i]]==0){
					new_v.push_back(v[i]);
				}
			}
			v=new_v;
			// for(int i=0;i<N;++i){
			// 	cout<<v[i]<<" ";
			// }cout<<endl;
			--K;
		}
	}
	
}
void solve(){
	for(int i=0;i<N;++i){
		if(pow(2,i)>=N){
			maxK=i-1;
			break;
		}
	}
	// cout<<maxK;
	// mixCard(2);
	for(int i=1;i<=maxK;++i){
		for(int j=1;j<=maxK;++j){
			v.clear();
			for(int m=1;m<=N;++m){
				v.push_back(m);
			}
			mixCard(i);
			mixCard(j);
			bool flag=1;
			for(int m=0;m<N;++m){
				if(res[m]!=v[m]){
					flag=0;
					break;
				}
			}
			if(flag==1){
				cout<<i<<" "<<j;
				return;
			}
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}