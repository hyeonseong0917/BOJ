#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


const int MAX=10000+1;
vector<int> v;
vector<int> ans;
int a;
void post(int start_num, int fin_num){
	if(start_num>=fin_num) return;
	int b=0;
	for(int i=start_num+1;i<fin_num;++i){
		b=i;
		if(v[start_num]<v[i]){
			break;
		}
	}
	post(start_num+1,b);
	post(b,fin_num);
	ans.push_back(v[start_num]);
	return;
}

int main() {
	// your code goes here
	int o=1;
	while(o--){
		v=vector<int>(MAX,0);
		while(cin>>a){
			v.push_back(a);
		}
		int n=v.size();
		post(0,n);
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<"\n";
		}

	}

	return 0;
}