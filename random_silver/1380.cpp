#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int cnt=1;
	while(1){
		int N;
		cin>>N;
		cin.ignore();
		if(N==0){
			break;
		}
		vector<string> name;
		for(int i=0;i<N;++i){
			string s;
			getline(cin,s);
			name.push_back(s);
		}	
		map<int,int> m;
		for(int i=0;i<2*N-1;++i){
			int a;
			char c;
			cin>>a>>c;
			++m[a];
		}
		for(int i=1;i<=N;++i){
			if(m[i]!=2){
				cout<<cnt<<" "<<name[i-1]<<"\n";
				cnt++;
				break;
			}
		}

	}
	

	

	return 0;
}