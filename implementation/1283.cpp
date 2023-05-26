#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//1523
int N=0;
vector<string> v;
int check[26+1];
void Input(){
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;++i){
		string s="";
		getline(cin,s);
		// cout<<s<<endl;	
		v.push_back(s);
	}
	for(int i=0;i<26+1;++i){
		check[i]=0;
	}
	// cout<<v[0]<<endl;
}
void solve(){
	int a='A'; //'A'=65
	int b='a'; //'a'=97
	for(int i=0;i<N;++i){
		string cur_string=v[i];
		char first_char=cur_string[0];
		int first_char_num=cur_string[0];
		string new_str="";
		if(1){
			int checkNum=0;
			if(first_char_num>=97){
				checkNum=first_char-'a';
			}else{
				checkNum=first_char-'A';
			}
			//소문자
			if(!check[checkNum]){
				// cout<<"he";
				check[checkNum]=1;
				new_str='['+cur_string.substr(0,1)+']'+cur_string.substr(1);
				cout<<new_str<<endl;
			}else{
				bool second_flag=0;
			
				vector<string> space_split;
				string target="";
				for(int j=0;j<cur_string.size();++j){
					if(cur_string[j]==' '){
						space_split.push_back(target);
						target="";
					}else{
						target+=cur_string[j];	
					}
					
				}
				space_split.push_back(target);
				
				for(int j=0;j<space_split.size();++j){
					string cur_split=space_split[j];
					// if(i==3){
					// 	cout<<cur_split<<endl;
					// }
					if(cur_split[0]-'a'<0){
						//대문자
						if(!check[cur_split[0]-'A']){
							check[cur_split[0]-'A']=1;
							space_split[j]='['+cur_split.substr(0,1)+']'+cur_split.substr(1);
							second_flag=1;
							break;
						}
					}else{
						//소문자
						if(!check[cur_split[0]-'a']){
							check[cur_split[0]-'a']=1;
							space_split[j]='['+cur_split.substr(0,1)+']'+cur_split.substr(1);
							second_flag=1;
							break;
						}
					}
			
				}
				// if(i==3){
				// 	cout<<check['a'-'a']<<" "<<check['b'-'a']<<" "<<check['c'-'a']<<endl;
				// }
				if(second_flag==1){
					new_str="";
					for(int j=0;j<space_split.size();++j){
						new_str+=space_split[j];
						if(j!=space_split.size()-1){
							new_str+=" ";
						}
					}
					cout<<new_str<<endl;	
				}else{
					bool third_flag=0;
					for(int j=0;j<cur_string.size();++j){
						char cur_char=cur_string[j];
						if(cur_char==' '){
							continue;
						}
						// cout<<cur_char<<endl;
						// cout<<check[cur_char-'a']<<endl;
						int num=cur_char-'a';
						if(num<0){
							if(!check[cur_char-'A']){
								check[cur_char-'A']=1;
								cur_string=cur_string.substr(0,j)+'['+cur_string.substr(j,1)+']'+cur_string.substr(j+1);
								cout<<cur_string<<endl;
								third_flag=1;
								break;
							}
							
						}else{
							if(!check[cur_char-'a']){
								check[cur_char-'a']=1;
								cur_string=cur_string.substr(0,j)+'['+cur_string.substr(j,1)+']'+cur_string.substr(j+1);
								cout<<cur_string<<endl;
								third_flag=1;
								break;
							}
						}
					}
					// cout<<third_flag<<endl;
					if(!third_flag){
						cout<<cur_string<<endl;
					}
				}
				
			}
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}