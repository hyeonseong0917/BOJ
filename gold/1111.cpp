#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<"A"; 
			break;	
		} 
		int cnt=0;
		int ans=0;
		vector<int> tmp;
		for(int a=-200;a<=200;++a){
			for(int b=-20000;b<=20000;++b){
				bool flag=0;
				for(int i=1;i<n;++i){
					if(v[i]!=v[i-1]*a+b){
						flag=1;
						break;
					}
				}
				if(!flag){
					++cnt;
					ans=v[n-1]*a+b;
					if(tmp.empty()){
						tmp.push_back(ans);
					}else{
						if(tmp[0]!=ans){
							tmp.push_back(ans);
						}
					}
				}
			}
		}
		if(cnt==0){
			cout<<"B";
		}else if(cnt==1){
			cout<<ans;
		}else{
			if(tmp.size()==1){
				cout<<tmp[0];
			}else{
				cout<<"A";	
			}
		}
	}

	return 0;
}