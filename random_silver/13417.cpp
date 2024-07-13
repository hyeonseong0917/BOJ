#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		deque<char> dq;
		for(int i=0;i<n;++i){
			char a=0;
			cin>>a;
			if(i==0){
				dq.push_back(a);
			}else{
				char L=dq.front();
				if(a<=L){
					dq.push_front(a);
				}else{
					dq.push_back(a);
				}
			}
		}
		while(!dq.empty()){
			cout<<dq.front();
			dq.pop_front();
		}
		cout<<"\n";
	}
	return 0;
}