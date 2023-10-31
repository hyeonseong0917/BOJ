#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int max_num=-1;
	int cur_num=0;
	for(int i=0;i<10;++i){
		int a,b;
		cin>>a>>b;
		cur_num-=a;
		cur_num+=b;
		max_num=max(max_num,cur_num);
	}
	cout<<max_num;

	return 0;
}