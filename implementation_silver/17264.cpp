#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int N,P;
	cin>>N>>P;
	int W,L,G;
	cin>>W>>L>>G;
	map<string,int> m; 
	vector<string> can_win_player;
	vector<string> game;
	for(int i=0;i<P;++i){
		string s;
		char c;
		cin>>s>>c;
		if(c=='W'){
			m[s]=1;
			can_win_player.push_back(s);
		}
	}
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		game.push_back(s);
	}
	bool flag=0;
	int sum=0;
	for(int j=0;j<N;++j){
		if(m[game[j]]==1){
			sum+=W;
		}else{
			sum=max(sum-L,0);
		}
		if(sum>=G){
			flag=1;
		}
	}
	if(flag==1){
		cout<<"I AM NOT IRONMAN!!";
	}else{
		cout<<"I AM IRONMAN!!";
	}

	return 0;
}