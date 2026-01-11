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
ll is_prime(ll cur_num){
  ll flag=1;
  if(cur_num==1){
    flag=0;
  }else{
    if(cur_num==2 || cur_num==3){
      flag=1;
    }else{
      for(ll i=2;i*i<=cur_num;++i){
        if(cur_num%i==0){
          flag=0;
          break;
        }
      }
    }
  }
  return flag;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
        ll n;
        cin>>n;
        while(n--){
            ll cur_num;
            cin>>cur_num;
            // cur_num이 소수일지?
            while(!is_prime(cur_num)){
               ++cur_num;
            }
            if(cur_num==0){
                cur_num=2;
                }
            cout<<cur_num<<"\n";
        }
	} 
	return 0;
}