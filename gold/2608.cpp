#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

string s;
int char_to_int(char c){
	if(c=='I'){
		return 1;
	}else if(c=='V'){
		return 5;
	}else if(c=='X'){
		return 10;
	}else if(c=='L'){
		return 50;
	}else if(c=='C'){
		return 100;
	}else if(c=='D'){
		return 500;
	}else if(c=='M'){
		return 1000;
	}
	return -1;
}
int str_to_int(string s){
	int N=s.size();
	int num=0;
	int idx=0;
	while(idx<N-1){
		if(char_to_int(s[idx])>=char_to_int(s[idx+1])){
			num+=char_to_int(s[idx]);
			++idx;
		}else{
			num+=(char_to_int(s[idx+1])-char_to_int(s[idx]));
			idx+=2;
		}
	}
	if(idx==N-1){
		num+=char_to_int(s[idx]);
	}
	return num;
	
}
string int_to_str(int sum){
	string cur_str="";
	for(int i=0;i<sum/1000;++i){
		cur_str+='M';
	}
	sum%=1000;
	if(sum/100==4 || sum/100==9){
		if(sum/100==4){
			cur_str+="CD";
		}else{
			cur_str+="CM";
		}
	}else{
		if(sum/100<5){
			for(int i=0;i<sum/100;++i){
				cur_str+='C';
			}
		}else{
			cur_str+='D';
			sum-=500;
			for(int i=0;i<sum/100;++i){
				cur_str+='C';
			}
		}
	}
	sum%=100;
	if(sum/10==4 || sum/10==9){
		if(sum/10==4){
			cur_str+="XL";
		}else{
			cur_str+="XC";
		}
	}else{
		if(sum/10<5){
			for(int i=0;i<sum/10;++i){
				cur_str+='X';
			}
		}else{
			cur_str+='L';
			sum-=50;
			for(int i=0;i<sum/10;++i){
				cur_str+='X';
			}
		}
	}
	sum%=10;
	if(sum==4 || sum==9){
		if(sum==4){
			cur_str+="IV";
		}else{
			cur_str+="IX";
		}
	}else{
		if(sum<5){
			for(int i=0;i<sum;++i){
				cur_str+="I";	
			}
		}else{
			cur_str+="V";
			sum-=5;
			for(int i=0;i<sum;++i){
				cur_str+="I";
			}
		}
	}
	return cur_str;

}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s1,s2;
	cin>>s1;
	cin>>s2;
	// cout<<str_to_int(s1)<<" "<<str_to_int(s2);
	int sum=0;
	sum=str_to_int(s1)+str_to_int(s2);
	string ans=int_to_str(sum);
	cout<<sum<<"\n";
	cout<<ans;
	return 0;
}