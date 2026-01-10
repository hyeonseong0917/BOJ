#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// ##1: 문제 해석
		// 사전에는 N개의 단어
		// 단어 안에 있는 모든 단어를 알 때, 그 단어를 "안다"
		// 1 x: 알파벳 x를 잊는다
		// 2 x: 알파벳 x를 기억해 낸다
		// 초기: 모든 알파벳 기억중, 모음은 잊지 않음
		// 각 쿼리를 실행했을 때마다 그 시점에서 완전히 알고 있는 단어의 개수

		// ##2: 입력 및 출력
		// 입력: N(영어 단어의 개수), M(정수 o와 문자 x로 이루어진 쿼리의 개수)
		// N<=10^4, 문자의 길이 10^3, M<=5*(10^4), 제한시간 4초 O(N*M)은 불가
		// 출력: M줄의 각 쿼리마다 현재 상태에서 알고 있는 단어의 수 출력

		// ##3: 해결
		// (1) 1 x만 있는 경우
		// 알파벳 x를 잊음 -> x를 잊었는데도 알고 있는 단어의 개수는 몇 개인지?
		// -> x를 포함한 단어는 모두 제거? 단순히 x만 제거한다면 기존에 제거된게 중복 제거가능
		// 1 x 처리를 어떻게 해야 할지? + 기억하고 있는 단어들을 어떻게 처리할지?
		// 일단은 고유한 문자로 이루어진 문자열만 입력으로 받도록 함
		// one_cnt[x]: x문자를 가진 문자열의 개수
		// comb_cnt[x][y]: x문자와 y문자를 가진 문자열의 개수
		// forget[]: 잊어버린 문자들의 배열
		// total_cnt: 현재 외우고 있는 전체 문자열 개수
		// 1 x -> total_cnt - one_cnt[x] + (comb_cnt[x][f1]+comb_cnt[x][f2]..)
		// 2 x -> total_cnt + one_cnt[x] - (comb_cnt[x][f1]+comb_cnt[x][f2]...)
		// 이 경우 시간복잡도: M*(26)

		int n,m;
		cin>>n>>m;
		vector<int> one_cnt(26,0);
		vector<vector<int>> comb_cnt(26,vector<int>(26,0));
		for(int i=0;i<n;++i){
			string a;
			cin>>a;
			// a에서 고유한 문자를 찾는다
			vector<int> visited(26,0);
			int as=a.size();
			for(int j=0;j<as;++j){
			++visited[a[j]-'a'];
			}
			// 1. one_cnt 값을 처리하기
			for(int j=0;j<26;++j){
			if(visited[j]){
				++one_cnt[j];
			}
			}
			for(int j=0;j<26;++j){
			for(int k=0;k<26;++k){
				if(j==k) continue;
				if(visited[j] && visited[k]){
				++comb_cnt[j][k];
				}
			}
			}
		}
		// forget[]: 잊어버린 문자들의 배열
		// total_cnt: 현재 외우고 있는 전체 문자열 개수
		// 1 x -> total_cnt - one_cnt[x] + (comb_cnt[x][f1]+comb_cnt[x][f2]..)
		// 2 x -> total_cnt + one_cnt[x] - (comb_cnt[x][f1]+comb_cnt[x][f2]...)
		int total_cnt=n;
		vector<int> forget;
		vector<int> answer;
		for(int i=0;i<m;++i){
			int a;
			char b;
			cin>>a;
			cin>>b;
			int c=b-'a';
			int fs=forget.size();
			if(a==1){
			total_cnt-=one_cnt[c];
			for(int j=0;j<fs;++j){
				total_cnt+=comb_cnt[c][forget[j]];
			}
			forget.push_back(c);
			}else{
			total_cnt+=one_cnt[c];
			vector<int> tmp;
			for(int j=0;j<fs;++j){
				total_cnt-=comb_cnt[c][forget[j]];
				if(forget[j]!=c){
				tmp.push_back(forget[j]);
				}
			}
			forget.clear();
			for(int j=0;j<tmp.size();++j){
				forget.push_back(tmp[j]);
			}
			}
			answer.push_back(total_cnt);
		}
		for(int i=0;i<answer.size();++i){
			cout<<answer[i]<<"\n";
		}

	}
	return 0;
}
