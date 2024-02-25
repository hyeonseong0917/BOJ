#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

vector<int> B;
int N;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		B.push_back(a);
	}
}
void solve(){
	int cnt=0;
	while(1){
		bool flag=0;
		for(int i=0;i<B.size();++i){
			if(B[i]>1){
				flag=1;
				break;
			}
		}
		if(flag){
			++cnt;
			for(int i=0;i<B.size();++i){
				if(B[i]>1){
					if(B[i]%2==1){
						++cnt;
					}
					B[i]/=2;
				}
			}
		}else{
			break;
		}
	}
	for(int i=0;i<B.size();++i){
		if(B[i]==1){
			++cnt;
		}
	}
	cout<<cnt;
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