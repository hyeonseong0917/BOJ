#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1232
string s;
int K;
const int MAX=10000+1;
vector<int> v[MAX];
void solve(){
	for(int i=0;i<s.size();++i){
		char c=s[i];
		v[c-'a'].push_back(i);
	}
	int minSum=12232421;
	int maxSum=-1;
	bool flag=0;
	for(int i=0;i<26;++i){
		char c='a'+i;
		if(v[c-'a'].size()>=K){
			flag=1;
			for(int j=0;j<=v[c-'a'].size()-K;++j){
				int curSum=0;
				int lastNum=v[c-'a'][j];
				for(int k=1;k<K;++k){
					curSum+=v[c-'a'][j+k]-lastNum;
					lastNum=v[c-'a'][j+k];
				}
				// cout<<c<<" "<<curSum+1<<endl;
				minSum=min(curSum+1,minSum);
				maxSum=max(curSum+1,maxSum);
			}
		}
	}
	if(!flag){
		cout<<-1<<endl;
		return;
	}
	cout<<minSum<<" "<<maxSum<<endl;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		for(int i=0;i<MAX;++i){
			v[i].clear();
		}
		cin>>s;
		cin>>K;	
		solve();
	}
	return 0;
}