#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int a,b,c;
map<pair<pair<int,int>,int>,int> m;
// map<pair<pair<int,int>,int>,int> dp;
// int m[21][21][21];
int w(int a, int b, int c){
	if(a<=0 || b<=0 || c<=0 ){
		return 1;
	}
	if(a>20 || b>20 || c>20){
		return w(20,20,20);
	}
	if(m[{{a,b},c}]){
		return m[{{a,b},c}];
	}
	if(a<b && b<c){
		return m[{{a,b},c}]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	return m[{{a,b},c}]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		cin>>a>>b>>c;
		if(a==-1 && b==-1 && c==-1){
			break;
		}
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
	}

	return 0;
}