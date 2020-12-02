#include<iostream>

using namespace std;
const int N = 1e5+100;
// son数组表示当前节点的孩子节点的下标，son[1][0]=2表示1结点的一个值为a的子结点为结点2
// cnt表示某一下标 对应的字符串的个数，以“abc”字符串为例，最后一个字符---‘c’对应的idx作为cnt数组的下标。数组的值是该idx对应的个数。
// idx 用来表示下标
// 下标为0的点，即是根节点，又是空节点
int son[N][26], cnt[N],idx;
char str[N];

void insert(char str[]){
    int p = 0; // 从根节点走，没有节点就创建节点
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin >> n;
    char op;
    while(n--){
        cin >> op >> str;
        if(op=='I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}
