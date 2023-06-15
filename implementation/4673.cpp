#include <iostream>

using namespace std;

//1529
bool visited[15000+1]={0,};
int d(int num){
	int sum=0;
	string num_str=to_string(num);
	for(int i=0;i<num_str.size();++i){
		sum+=num_str[i]-'0';
	}
	return num+sum;
}
int main() {
	// your code goes here
	// cout<<d(18);
	int a=1;
	while(1){
		int cur_d=d(a);
		if(cur_d>10026){
			break;
		}
		++a;
		visited[cur_d]=1;
	}
	for(int i=1;i<=10000;++i){
		if(!visited[i]){
			cout<<i<<"\n";
		}
	}
	return 0;
}