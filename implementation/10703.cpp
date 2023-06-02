#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1425
const int MAX=3000+1;
char board[MAX][MAX];
char res[MAX][MAX];
int R,S;
void Input(){
	cin>>R>>S;
	for(int i=0;i<R;++i){
		for(int j=0;j<S;++j){
			cin>>board[i][j];
			res[i][j]=board[i][j];
		}
	}
}
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

void solve(){
	vector<pair<int,int>> s,w;
	for(int i=0;i<R;++i){
		for(int j=0;j<S;++j){
			if(board[i][j]=='X'){
				s.push_back({i,j});
				board[i][j]='.';
			}else if(board[i][j]=='#'){
				w.push_back({i,j});
			}
		}
	}	
	sort(s.begin(),s.end(),comp);
	sort(w.begin(),w.end(),cmp);
	bool check_s[3000+1]={0,};
	bool check_w[3000+1]={0,};
	vector<pair<int,int>> cur_s,cur_w;
	for(int i=0;i<s.size();++i){
		
		if(!check_s[s[i].second]){
			// cout<<s[i].second<<endl;
			check_s[s[i].second]=1;
			cur_s.push_back({s[i].first,s[i].second});
		}
	}
	for(int i=0;i<w.size();++i){
		if(!check_w[w[i].second]){
			// cout<<s[i].second<<endl;
			check_w[w[i].second]=1;
			cur_w.push_back({w[i].first,w[i].second});
		}
	}
	int minNum=122232421;
	for(int i=0;i<cur_s.size();++i){
		int y=cur_s[i].first;
		int x=cur_s[i].second;
		// cout<<y<<endl;
		for(int j=0;j<cur_w.size();++j){
			if(cur_w[j].second==x){
				minNum=min(minNum,cur_w[j].first-y);
				break;
			}
		}
	}
	minNum-=1;
	for(int i=0;i<s.size();++i){
		int y=s[i].first;
		int x=s[i].second;
		board[y+minNum][x]='X';
	}
	for(int i=0;i<R;++i){
		for(int j=0;j<S;++j){
			cout<<board[i][j];
		}cout<<"\n";
	}
	// cout<<minNum;
	// cout<<cur_w.size();
	
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}