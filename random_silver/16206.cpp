#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long
vector<int> fst_num, sed_num;
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int N,M;
	cin>>N>>M;
	int cnt=0;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		if(a%10==0){
			fst_num.push_back(a);
		}else{
			sed_num.push_back(a);
		}
	}
	sort(sed_num.begin(),sed_num.end());
	sort(fst_num.begin(),fst_num.end());
	for(int i=0;i<fst_num.size();++i){
		if(fst_num[i]==10){
			++cnt;
		}else{
			if(M<(fst_num[i]/10)-1){
				cnt+=M;
				M=0;
			}else{
				M-=(fst_num[i]/10)-1;
				cnt+=(fst_num[i]/10);
			}
		}
	}
	for(int i=0;i<sed_num.size();++i){
		if(sed_num[i]>10){
			if(M<sed_num[i]/10){
				cnt+=M;
				M=0;
			}else{
				M-=(sed_num[i]/10);
				cnt+=(sed_num[i]/10);
			}
		}
	}
	cout<<cnt;
	
	return 0;
}