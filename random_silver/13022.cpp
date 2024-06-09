#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

string generate_wolf(int cnt){
	string t="";
	for(int i=0;i<cnt;++i){
		t+='w';
	}
	for(int i=0;i<cnt;++i){
		t+='o';
	}
	for(int i=0;i<cnt;++i){
		t+='l';
	}
	for(int i=0;i<cnt;++i){
		t+='f';
	}
	return t;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s;
	cin>>s;
	int idx=0;
	int n=s.size();
	bool flag=0;
	while(idx<n){
		flag=0;
		for(int i=1;i<=12;++i){
			string cur_wolf=generate_wolf(i);
			// cout<<cur_wolf<<endl;
			for(int j=1;j<=12;++j){
				if(idx+j*4>n){
					break;
				}
				string new_wolf=s.substr(idx,j*4);
				// cout<<new_wolf<<endl;
				if(cur_wolf.compare(new_wolf)==0){
					flag=1;
					idx+=j*4;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	if(flag){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
}