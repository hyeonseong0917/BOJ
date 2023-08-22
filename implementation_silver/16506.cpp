#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N=0;
vector<string> opcode;
vector<int> rd;
vector<int> ra;
vector<int> rbc;
void Input(){
	cin>>N;
	for(int i=0;i<N*4;++i){
		string s="";
		cin>>s;
		if(i%4==0){
			opcode.push_back(s);
		}else if(i%4==1){
			rd.push_back(stoi(s));
		}else if(i%4==2){
			ra.push_back(stoi(s));
		}else if(i%4==3){
			rbc.push_back(stoi(s));
		}
	}
}
string bit_cal(int num){
	if(num==0){
		return "000";
	}else if(num==1){
		return "001";
	}else if(num==2){
		return "010";
	}else if(num==3){
		return "011";
	}
	string res="";
	while(num>0){
		res+=((num%2)+'0');
		num/=2;
	}
	reverse(res.begin(),res.end());
	return res;
}
void solve(){
	for(int i=0;i<N;++i){
		string cur_str="";
		string cur_op=opcode[i];
		int cur_rd=rd[i];
		int cur_ra=ra[i];
		int cur_rbc=rbc[i];
		if(cur_op=="ADD" || cur_op=="ADDC"){
			cur_str+="0000";
		}else if(cur_op=="SUB" || cur_op=="SUBC"){
			cur_str+="0001";
		}else if(cur_op=="MOV" || cur_op=="MOVC"){
			cur_str+="0010";
		}else if(cur_op=="AND" || cur_op=="ANDC"){
			cur_str+="0011";
		}else if(cur_op=="OR" || cur_op=="ORC"){
			cur_str+="0100";
		}else if(cur_op=="NOT"){
			cur_str+="0101";
		}else if(cur_op=="MULT" || cur_op=="MULTC"){
			cur_str+="0110";
		}else if(cur_op=="LSFTL" || cur_op=="LSFTLC"){
			cur_str+="0111";
		}else if(cur_op=="LSFTR" || cur_op=="LSFTRC"){
			cur_str+="1000";
		}else if(cur_op=="ASFTR" || cur_op=="ASFTRC"){
			cur_str+="1001";
		}else if(cur_op=="RL" || cur_op=="RLC"){
			cur_str+="1010";
		}else if(cur_op=="RR" || cur_op=="RRC"){
			cur_str+="1011";
		}
		bool flag=0;
		if(cur_op[cur_op.size()-1]=='C'){
			cur_str+='1';
			flag=1;
		}else{
			cur_str+='0';
		}
		cur_str+='0';
		// cout<<cur_str<<endl;
		cur_str+=bit_cal(cur_rd);
		cur_str+=bit_cal(cur_ra);
		if(cur_rbc<8 && flag==1){
			cur_str+='0';
		}
		cur_str+=bit_cal(cur_rbc);
		if(flag==0){
			cur_str+='0';
		}
		cout<<cur_str<<endl;
	}	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}