#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long
int N;
int arr[10+1]={6,2,5,5,4,5,6,3,7,6};
int get_num(int num){
	if(num<10){
		return arr[0]+arr[num];
	}else{
		return arr[num/10]+arr[num%10];
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	cin>>N;
	N-=4;
	if(N<=0){
		cout<<"impossible";
	}else{
		bool flag=0;
		int fst_num,sed_num,trd_num;
		for(int i=0;i<=99;++i){
			for(int j=0;j<=99;++j){
				for(int k=0;k<=99;++k){
					// if(i==0 && j==11 && k==11){
					// 	cout<<get_num(i)<<" "<<get_num(j)<<" "<<get_num(k)<<"\n";
					// 	cout<<N<<endl;
					// }
					if(i+j==k){
						if(get_num(i)+get_num(j)+get_num(k)==N){
							fst_num=i;
							sed_num=j;
							trd_num=k;
							flag=1;
							break;
						}
					}
				}
			}
		}
		if(flag){
			string fst_str="",sed_str="",trd_str="";
			if(fst_num/10<1){
				fst_str+='0';
			}
			if(sed_num/10<1){
				sed_str+='0';
			}
			if(trd_num/10<1){
				trd_str+='0';
			}
			// cout<<fst_num<<" "<<sed_num<<" "<<trd_num<<endl;
			fst_str+=to_string(fst_num);
			sed_str+=to_string(sed_num);
			trd_str+=to_string(trd_num);
			cout<<fst_str<<"+"<<sed_str<<"="<<trd_str;
		}else{
			cout<<"impossible";
		}
	}

	return 0;
}