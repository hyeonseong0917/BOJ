#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N,K;
void Input(){
	cin>>N>>K;
}
void solve(){
	//N개의 공을 K개의 바구니에 넣기
	int sum=0;
	vector<int> ans;
	for(int i=1;i<=K;++i){
		sum+=i;
		ans.push_back(i);
	}
	if(N<sum){
		cout<<-1;
		return;
	}
	N-=sum;
	bool flag=0;
	while(!flag){
		for(int i=ans.size()-1;i>=0;--i){
			if(N){
				ans[i]+=1;
				N-=1;	
			}else{
				flag=1;
				break;
			}
			
		}	
	}
	cout<<ans[ans.size()-1]-ans[0];
	
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}