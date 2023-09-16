#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool isMapEqual(map<char,int> first_map, map<char,int> second_map){
	for(int i=0;i<26;++i){
		char d='A'+i;
		if(first_map[d]!=second_map[d]){
			return 0;
		}
	}
	return 1;
}

bool isAlike(string first_str, string second_str){
	map<char,int> first_map,second_map;
	first_map.clear();
	second_map.clear();
	for(int i=0;i<first_str.size();++i){
		++first_map[first_str[i]];
	}
	for(int j=0;j<second_str.size();++j){
		++second_map[second_str[j]];
	}
	bool flag=0;
	if(isMapEqual(first_map, second_map)){
		return 1;
	}
	//문자를 더해보기
	for(int k=0;k<26;++k){
		map<char,int> tmp=second_map;
		char c='A'+k;
		++second_map[c];
		if(isMapEqual(first_map, second_map)){
			return 1;
		}
		second_map=tmp;
	}
	//second_str을 빼서 first_map과 second_map이 동일할 수 있는지?
	for(int j=0;j<second_str.size();++j){
		map<char,int> tmp=second_map;
		char c=second_str[j];
		//임의의 문자를 빼보기
		--second_map[c];
		if(isMapEqual(first_map, second_map)){
			return 1;
		}
		second_map=tmp;
	}
	//second_str을 교체 first_map과 second_map이 동일할 수 있는지?
	for(int j=0;j<second_str.size();++j){
		map<char,int> tmp=second_map;
		char c=second_str[j];
		//임의의 문자를 빼보기
		--second_map[c];
		// if(c=='B'){
		// 	cout<<j<<" "<<second_map[j]<<endl;
		// }
		for(int k=0;k<26;++k){
			char t='A'+k;
			++second_map[t];
			
			if(isMapEqual(first_map, second_map)){
				return 1;
			}
			// s
			--second_map[t];
		}
		
		second_map=tmp;
		// cout<<first_map['D']<<first_map['O']<<first_map['G']<<endl;
		// cout<<second_map['D']<<second_map['O']<<second_map['B']<<endl;
		// cout<<endl;
		// break;
	}
	return 0;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0;
	cin>>N;
	vector<string> v;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		v.push_back(s);
	}
	int cnt=0;
	// cout<<isAlike(v[0],v[1])<<endl;
	// cout<<isAlike(v[0],v[2]);
	for(int i=1;i<v.size();++i){
		if(isAlike(v[0],v[i])){
			++cnt;
		}
	}
	cout<<cnt;
	return 0;
}