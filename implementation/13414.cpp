#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int K,L;
map<string,int> m;
vector<string> wait_queue;
void Input(){
	cin>>K>>L;
	for(int i=0;i<L;++i){
		string a;
		cin>>a;
		wait_queue.push_back(a);
		++m[a];
	}
}
void solve(){
	vector<string> new_wait_queue;
	for(int i=0;i<wait_queue.size();++i){
		if(m[wait_queue[i]]==1){
			new_wait_queue.push_back(wait_queue[i]);
		}else{
			--m[wait_queue[i]];
		}
	}
	int new_qs=new_wait_queue.size();
	for(int i=0;i<min(K,new_qs);++i){
		cout<<new_wait_queue[i]<<"\n";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}