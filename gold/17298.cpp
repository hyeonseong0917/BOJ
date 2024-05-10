#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	int t=1;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n,0), need(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		stack<int> st;
		vector<int> ans;
		int min_num=122232421;
		for(int i=0;i<n;++i){
			if(v[i]<=min_num){
				min_num=v[i];
				need[i]=0;
			}else{
				need[i]=1;
			}
		}
		for(int i=n-1;i>=0;--i){
			while(!st.empty()){
				if(v[i]<st.top()){
					break;
				}else{
					st.pop();
				}
			}
			if(st.empty()){
				ans.push_back(-1);
				st.push(v[i]);
			}else{
				ans.push_back(st.top());
				if(need[i]){
					st.push(v[i]);
				}
			}
		}
		reverse(ans.begin(),ans.end());
		for(int i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
		
	}
	return 0;
}