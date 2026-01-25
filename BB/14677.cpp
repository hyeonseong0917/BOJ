#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define MAX_TABLE (1000003)
#define MAX_NUM (1000001)
typedef unsigned long long int ull;
#define ll long long

ull myhash(const char *str)
{
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}
void mystrcpy(char *a, char *b){
    while(*a++=*b++);
}
int mystrcmp(const char *a, const char *b){
    while(*a && *a==*b) ++a, ++b;
    return *a-*b;
}
typedef struct st{
	char name[6];
	int in;
}DB;
typedef struct st2{
	DB* db;
	struct st2* next;
}HASH;
HASH HEAD[MAX_TABLE+1];
HASH POOL[MAX_NUM];
DB dbList[MAX_NUM];
DB enterList[MAX_NUM];
DB finalList[MAX_NUM];
int n;
void merge(int L, int R){
	int mid=(L+R)>>1;
	int i=L;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=R){
		if(mystrcmp(enterList[i].name,enterList[j].name)>0){
			finalList[k++]=enterList[j++];
		}else{
			finalList[k++]=enterList[i++];
		}
	}
	while(i<=mid) finalList[k++]=enterList[i++];
	while(j<=R) finalList[k++]=enterList[j++];
	for(int x=L;x<=R;++x){
		enterList[x]=finalList[x-L];
	}
}
void merge_sort(int L, int R){
	if(L==R) return;
	int mid=(L+R)>>1;
	merge_sort(L,mid);
	merge_sort(mid+1,R);
	merge(L,R);
}
void solve(){
	 // HEAD 배열 초기화 추가!
    // for(int i=0;i<MAX_TABLE;++i){
    //     HEAD[i].next=NULL;
    // }
	int p_cnt=0;
	int db_cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char cur_name[6];
		scanf("%s",cur_name);
		char cur_event[6];
		scanf("%s",cur_event);
		int cur_hash=myhash(cur_name);
		if(!mystrcmp(cur_event,"enter")){
			mystrcpy(dbList[db_cnt].name,cur_name);
			dbList[db_cnt].in=1;

			HASH *nd=&POOL[p_cnt++];
			nd->db=&dbList[db_cnt];

			nd->next=HEAD[cur_hash].next;
			HEAD[cur_hash].next=nd;
			++db_cnt;
		}else{
			// 삭제연산은?
			HASH *nd=&HEAD[cur_hash];
			while(nd->next){
				if(!mystrcmp(cur_name,nd->next->db->name)){
					// a->b->c 인데 b->c를 끊어야함
					nd->next->db->in=0;
					nd->next=nd->next->next;
					break;
				}
				nd=nd->next;
			}

		}
	}
	int enter_cnt=0;
	for(int i=0;i<db_cnt;++i){
		if(dbList[i].in){
			enterList[enter_cnt++]=dbList[i];
		}
	}
	merge_sort(0,enter_cnt-1);
	for(int i=enter_cnt-1;i>=0;--i){
		printf("%s\n",finalList[i].name);
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		solve();
	}
	return 0;
}