#include <iostream>
using namespace std;

int N,K;
const int MAX=100+1;
int schedule[MAX];
int plug[MAX];
int result=0;

void Input(){
	cin>>N>>K;
	for(int i=0;i<K;++i){
		cin>>schedule[i];
	}
}

void solve(){
	for(int i=0;i<K;++i){
		bool plugged=false;
		for(int j=0;j<N;++j){
			if(schedule[i]==plug[j]){
				plugged=true;
				break;
			}
		}
		if(plugged) continue;
		for(int j=0;j<N;++j){
			if(!plug[j]){
				plug[j]=schedule[i];
				plugged=true;
				break;
			}
		}
		if(plugged) continue;
		int idx=-1;
		int deviceIdx=-1;
		for(int j=0;j<N;++j){
			int lastIdx=0;
			for(int m=i+1;m<K;++m){
				if(plug[j]==schedule[m]){
					break;
				}
				lastIdx++;
			}
			if(lastIdx>deviceIdx){
				deviceIdx=lastIdx;
				idx=j;
			}
		}
		result++;
		plug[idx]=schedule[i];
		
	}
	
}

int main() {
	Input();
	solve();
	cout<<result;
}