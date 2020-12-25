#include <bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define eps 1e-9
#define For(i,a,b) for(int i=a;i<=b;i++) 
#define Fore(i,a,b) for(int i=a;i>=b;i--) 
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define mkp make_pair
#define pb push_back
#define cr clear()
#define met(a,b) memset(a,b,sizeof(a))
#define iossy ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fre freopen
#define pi acos(-1.0)
#define inf 1e9+9
#define Vector Point
#define fir first
#define sec second
#define fxx(a) cout<<fixed<<setprecision(a)
#define flu cout.flush()
typedef pair<int,int> pii;
const int Mod=1000000007;
typedef unsigned long long ull;
typedef long long ll;
const int base=227;
const int base1=123;
const int maxn=2005;
struct node {
	char s1[10],s2[10];
	int flg;
	node () {}
	node (char *s1,char *s2){
		strcpy(this->s1,s1);
		strcpy(this->s2,s2);
		flg=0;
	}
	bool operator < (const node &a)const {
		return strcmp(s1,a.s1)<0;
	}
};
int n,rt;
set<node>ss;
node nd[50];
char s[50][50];
int vis[20],gg;
char sv[20],tmp;
char ans[20];
bool add(char *sp,int x) {
	if(x<=4) {
		For(i,4*x-3,4*x) {
			if(sv[i]!=sp[i-4*x+3] && sv[i]!='*') return 0;
			sv[i]=sp[i-4*x+3];
		}
	}else if(x>4) {
		x-=4;
		For(i,0,3) {
			if(sv[x+4*i]!=sp[i] && sv[x+4*i]!='*') return 0;
			sv[x+4*i]=sp[i];
		}
	}
	return 1;
}
void rev(char *tmp) {
	For(i,1,16) sv[i]=tmp[i];
}
void dfs(int x) {
//	cout<<x<<endl;
	if(x>=rt) {
		//cout<<sv+1<<"-----------------------"<<endl; 
		For(i,1,16) if(sv[i]=='*') sv[i]='A';
		if(gg) strcpy(ans+1,sv+1);	
		else {
			if(strcmp(ans+1,sv+1)>0) strcpy(ans+1,sv+1);
		}
		gg=0;
	}else {
		For(i,1,8) {
			if(!vis[i]) {
				char tmp[20];
				For(i,1,16) tmp[i]=sv[i];
				bool res=add(nd[x].s1,i);
				if(res) {
					vis[i]=1;
					dfs(x+1);
					rev(tmp);
					vis[i]=0;
				}else rev(tmp);
				if(nd[x].flg) {
					res=add(nd[x].s2,i);
					if(res) {
						vis[i]=1;
						dfs(x+1);
						rev(tmp);
						vis[i]=0;
					}else rev(tmp);
				}
		//		dfs(x+1);
			}
		}
	}
}
bool chk() {
	char rs[10];rt=0;ss.clear();
	For(i,1,n) {
		For(j,i+1,n) {
			For(k,0,3)  rs[k]=s[i][3-k];rs[4]='\0';
			if(strcmp(s[i],s[j])==0 || strcmp(rs,s[j])==0) {
				if(!ss.count(node(s[i],s[j])) && !ss.count(node(rs,s[j]))){
					ss.insert(node(s[i],rs));
					nd[rt++]=node(s[i],rs);
				}
			}
		}
	}
	For(i,1,n) {
		For(j,0,3) rs[j]=s[i][3-j];
		if(!ss.count(node(s[i],rs)) && !ss.count(node(rs,s[i]))){
			ss.insert(node(s[i],rs));
			nd[rt++]=node(s[i],rs);	
		}
	}
	return rt<=8;
}
void solve() {
	scanf("%d",&n);met(vis,0);gg=1;
	For(i,1,16) sv[i]='*';
	For(i,1,n)   scanf("%s",s[i]);
	if(!chk()) {
		puts("grid");
		puts("snot");
		puts("poss");
		puts("ible");
		return ;
	}
	For(i,1,rt) if(strcmp(nd[i-1].s1,nd[i-1].s2)==0) nd[i-1].flg=0;else nd[i-1].flg=1;
//	For(i,1,rt) cout<<nd[i-1].s1<<" "<<nd[i-1].s2<<endl;	
	dfs(0);
	if(gg) {
		puts("grid");
		puts("snot");
		puts("poss");
		puts("ible");
		return ;
	}else {
		For(i,1,16) {
			if(i-1 && (i-1)%4==0) puts("");
			printf("%c",ans[i]);
		}
	}puts("");
}
int main(){
	int t=1;
//	freopen("in.txt","r",stdin);
	scanf("%d",&t);
	For(i,1,t) {
		if(i-1) puts("");
		solve();
	}
	return 0;
}