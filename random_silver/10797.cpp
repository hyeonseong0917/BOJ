#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		int a;
		cin>>a;
		int b,c,d,e,f;
		cin>>b>>c>>d>>e>>f;
		int ans=0;
		if(a==b){
			++ans;
		}
		if(a==c){
			++ans;
		}
		if(a==d){
			++ans;
		}
		if(a==e){
			++ans;
		}
		if(a==f){
			++ans;
		}
		cout<<ans;
	}
	

	

	return 0;
}