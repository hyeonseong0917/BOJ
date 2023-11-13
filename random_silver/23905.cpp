#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

vector<int> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	int b=1;
	while(t--){
		int N,K;
		cin>>N>>K;
		v.clear();
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		int cnt=0;
		for(int i=0;i<N;){
			if(v[i]==K){
				bool flag=1;
				int tmp=K;
				for(int j=i;j<N;++j){
					if(v[j]==tmp){
						--tmp;
						if(tmp==0){
							break;
						}
					}else{
						flag=0;
						break;
					}
				}
				if(flag && tmp==0) ++cnt;
				i+=K-tmp;
			}else{
				++i;
			}
		}
		cout<<"Case #"<<b<<": "<<cnt<<endl;
		++b;
	}
	return 0;
}