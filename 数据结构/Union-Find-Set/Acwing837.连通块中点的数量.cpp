#include<iostream>

using namespace std;
const int N = 1e5+100;
int p[N],set_size[N]; // 每个集合里面元素的数量,只保证根节点的size有意义即可 
int n,m;
int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}
void Union(int a,int b){
	int fa = find(a), fb = find(b);
	if(fa==fb) return ;
	p[fa] = fb;
	set_size[fb] += set_size[fa];
} 
int main(){
	cin >> n >> m;	
	for(int i=1;i<=n;i++) {
		p[i] = i; set_size[i] = 1;
	} 
	char op[10]; int a,b;
	while(m--){
		scanf("%s",op);
		if(op[0]=='C') {
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		else if(op[1]=='1'){
			scanf("%d%d",&a,&b);
			if(find(a)==find(b)) puts("Yes");
			else puts("No");
		}
		else{
			scanf("%d",&a);
			printf("%d\n",set_size[find(a)]);
		}
	}
	return 0;
} 
