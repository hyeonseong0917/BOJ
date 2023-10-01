#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int N,S,R;
	cin>>N>>S>>R;
	map<int,int> damaged; //손상된 팀의 번호
	map<int,int> rest; //여분 가져온 팀의 번호
	for(int i=0;i<S;++i){
		int a=0;
		cin>>a;
		// damaged.push_back(a);
		damaged[a]=1;
	}
	for(int i=0;i<R;++i){
		int a=0;
		cin>>a;
		// rest.push_back(a);
		rest[a]=1;
	}
	for(int i=1;i<=N;++i){
		if(rest[i] && damaged[i]){
			rest[i]=0;
			damaged[i]=0;
		}
	}
	int cnt=0; //출발이 가능한 팀
	for(int i=1;i<=N;++i){
		if(damaged[i]){
			bool flag=0;
			if(i-1>=1){
				if(rest[i-1]){
					rest[i-1]=0;
					flag=1;
				}
			}
			if(flag==0){
				if(i+1<=N){
					if(rest[i+1]){
						rest[i+1]=0;
						flag=1;
					}
				}
			}
			if(flag==0){
				++cnt;
			}
		}
	}
	cout<<cnt;
	// 
	// 최소의 팀이 출발하지 못해야함=최대한 많이 출발해야함
	return 0;
}