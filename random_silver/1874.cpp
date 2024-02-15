#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr; // 입력받는 수열
stack<int> st; // 
vector<char> ans;
int main() {
	// your code goes here
	int N=0;
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		arr.push_back(a);
	}
	int cnt=1;
	for(int i=0;i<N;++i){
		int cur_num=arr[i];
		while(1){
			if(cnt>N){
				if(st.empty()){
					break;
				}
				if(st.top()==cur_num){
					st.pop();
					ans.push_back('-');
				}
				break;
			}
			if(st.empty()){
				st.push(cnt++);
				ans.push_back('+');
			}
			if(st.top()==cur_num){
				st.pop();
				ans.push_back('-');
				break;
			}else{
				st.push(cnt++);
				ans.push_back('+');
			}
			
		}
	}
	if(st.empty()){
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}
	}else{
		cout<<"NO"<<"\n";
	}
	return 0;
}