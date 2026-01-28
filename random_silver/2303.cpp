#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
    int n;
    cin>>n;
    int sum=0;
    int max_num=0;
    for(int i=0;i<n;++i){
      vector<int> tmp(5,0);
      for(int j=0;j<5;++j){
        cin>>tmp[j];
      }
      for(int j=0;j<5;++j){
        for(int k=j+1;k<5;++k){
          for(int p=k+1;p<5;++p){
            // j k p
            if((tmp[j]+tmp[k]+tmp[p])%10>=sum){
              sum=(tmp[j]+tmp[k]+tmp[p])%10;
              max_num=i+1;
            }
          }
        }
      }
    }
    cout<<max_num;
	} 
	return 0;
}