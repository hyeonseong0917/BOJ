#include <iostream>
#include <cstring>
using namespace std;
#define MAX_TABLE (1000003)
#define ll long long
#define pb push_back
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
int n;
typedef struct st{
	char cur_str[14];
}DB;
typedef struct st2{
	DB* db;
	struct st2* next;
}HASH;

HASH POOL[100+1];
HASH HEAD[MAX_TABLE];
DB dbList[100+1];
int p_cnt=0;
int d_cnt=0;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		scanf("%d",&n);
		bool flag=0;
		int password_len=0;
		char password_c;
		for(int i=0;i<n;++i){
			char s[14];
			scanf("%s",s);
			if(flag) continue;
			int sl=strlen(s);
			// // s를 추가하고, 역순이 있는지도 체크
			int cur_hash_num=myhash(s);
			HASH *nd=&POOL[p_cnt++];
			nd->db=&dbList[d_cnt++];
			mystrcpy(nd->db->cur_str,s);
			nd->next=HEAD[cur_hash_num].next;
			HEAD[cur_hash_num].next=nd;

			char reversed_s[14];
			int r_idx=0;
			for(int j=sl-1;j>=0;--j){
				reversed_s[r_idx++]=s[j];
			}
			reversed_s[r_idx] = '\0';  // ✅ null terminator 추가!
			int reversed_hash_num=myhash(reversed_s);
			HASH *h=HEAD[reversed_hash_num].next;
			while(h){
				if(!mystrcmp(h->db->cur_str,reversed_s)){
					password_len=sl;
					password_c=s[sl/2];
					flag=1;
					break;
				}
				h=h->next;
			}
		}
		printf("%d %c",password_len,password_c);
	} 
	return 0;
}