#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,P,new_score=0;
vector<pair<int,int>> v;
int idx=0;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}
void Input(){
	cin>>N>>new_score>>P;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		v.push_back({i,a});
	}
	idx=v.size();
	v.push_back({idx,new_score});
	sort(v.begin(),v.end(),comp);
}
void solve(){
	
	vector<pair<int,int>> new_score;
	for(int i=0;i<v.size();++i){
		new_score.push_back(v[i]);
		if(new_score.size()==P){
			break;
		}
	}
	bool flag=0;
	for(int i=0;i<new_score.size();++i){
		if(new_score[i].first==idx){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<-1;
		return;
	}
	int same_num=1;
	int pre_score=-1;
	int rank=0;
	for(int i=0;i<new_score.size();++i){
		// cout<<new_score[i].second<<endl;
		if(new_score[i].second==pre_score){
			++same_num;
		}else{
			rank+=same_num;
			pre_score=new_score[i].second;
			if(pre_score!=-1){
				same_num=1;
			}else{
				same_num=0;
			}
		}
		// cout<<rank<<endl;
		if(new_score[i].first==idx){
			cout<<rank;
			break;
		}
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}