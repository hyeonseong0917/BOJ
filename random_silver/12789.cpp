#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

queue<int> q;
stack<int> st;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		q.push(a);
	}
	int cnt=1;
	while(!q.empty()){
		int cur_num=q.front();
		if(cur_num==cnt){
			q.pop();
			++cnt;
		}else{
			if(!st.empty()){
				int wait_num=st.top();
				if(wait_num==cnt){
					st.pop();
					++cnt;
				}else{
					st.push(cur_num);
					q.pop();	
				}
			}else{
				st.push(cur_num);
				q.pop();
			}

		}
	}
	bool flag=1;
	while(!st.empty()){
		int cur_num=st.top();
		if(cur_num==cnt){
			++cnt;
			st.pop();
		}else{
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<"Nice";
	}else{
		cout<<"Sad";
	}
	
	return 0;
}