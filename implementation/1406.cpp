#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string cur_str;
int N=0;
int cursor=0;
vector<pair<char,char>> edit_order;
stack<char> L,R;
void Input(){
	getline(cin,cur_str);
	string num="";
	getline(cin,num);
	N=stoi(num);
	cursor=cur_str.size();
	for(int i=0;i<cur_str.size();++i){
		L.push(cur_str[i]);
	}
	for(int i=0;i<N;++i){
		char order, target;
		cin>>order;
		if(order=='P'){
			cin>>target;
		}
		edit_order.push_back({order,target});
	}
}
void solve(){
	
	for(int i=0;i<N;++i){
		char cur_order=edit_order[i].first;
		char cur_target=edit_order[i].second;
		if(cur_order=='P'){
			L.push(cur_target);
		}else if(cur_order=='B'){
			if(!L.size()) continue;
			L.pop();
		}else if(cur_order=='L'){
			if(!L.size()) continue;
			int left_top=L.top();
			L.pop();
			R.push(left_top);
		}else if(cur_order=='D'){
			if(!R.size()) continue;
			int right_top=R.top();
			R.pop();
			L.push(right_top);
		}
		
	}
	while(!L.empty()){
		R.push(L.top());
		L.pop();
	}
	while(!R.empty()){
		cout<<R.top();
		R.pop();
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