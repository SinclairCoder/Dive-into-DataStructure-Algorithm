#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> pre,post;
int mrrior;
void getPost(int root,int tail){
	if(root>tail) return ;
	int i = root+1, j = tail;
	if(!mrrior){
		while(i<=tail&&pre[i]<pre[root]) i++;
		while(j>root&&pre[j]>=pre[root]) j--;
	}
	else {
		while(i<=tail&&pre[i]>=pre[root]) i++;
		while(j>root&&pre[j]<pre[root]) j--;
	}
	if(i-j!=1) return ;
	getPost(root+1,j);
	getPost(i,tail);
	post.push_back(pre[root]);
}
int main(){
	int n;
	cin >> n;
	pre.resize(n);
	for(int i=0;i<n;i++){
		cin >> pre[i];
	}
	getPost(0,n-1);
	if(post.size()!=n){
		mrrior = 1;
		post.clear();
		getPost(0,n-1);
	}
	if(post.size()==n){
		cout << "YES\n" << post[0];
		for(int i=1;i<n;i++)
			cout << " " << post[i];
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct node{
//    int data;
//    node*left ,*right;
//};
//void bstinsert(node* & root,int t){
//    if(root==NULL) {
//    	root = new node;
//        root->data = t;
//        root->left = root->right = NULL;
//        return ;
//    }
//    if(t>=root->data) bstinsert(root->right,t);
//    else bstinsert(root->left,t);
//}
//void preorder(node*root, vector<int>&v){
//    if(root==NULL) return ;
//    v.push_back(root->data);
//    preorder(root->left,v);
//    preorder(root->right,v);
//}
//void preordermirror(node*root, vector<int>&v){
//    if(root==NULL) return ;
//    v.push_back(root->data);
//    preordermirror(root->right,v);
//    preordermirror(root->left,v);
//}
//void postorder(node* root,vector<int>& v){
//    if(root==NULL) return;
//    postorder(root->left,v);
//    postorder(root->right,v);
//    v.push_back(root->data);
//}
//void postordermirror(node* root,vector<int>& v){
//    if(root==NULL) return;
//    postordermirror(root->right,v);
//    postordermirror(root->left,v);
//    v.push_back(root->data);
//}
//vector<int> origin,pre,post,premirror,postmirror;
//int main(){
//    int n,t;
//    cin >> n;
//    node *root = NULL;
//    for(int i=0;i<n;i++){
//        cin >> t;
////        cout << t << endl;
//        bstinsert(root,t);
//        origin.push_back(t);
//    }
//    preorder(root,pre);
//    preordermirror(root,premirror);
//    if(origin==pre){
//        cout << "YES" << endl;
//        postorder(root,post);
//        for(int i=0;i<post.size();i++){
//            if(!i) cout << post[i] ;
//			else cout << " " << post[i]; 
//        }
//    }
//    else if(origin==premirror){
//    	cout << "YES" << endl;
//        postordermirror(root,postmirror);
//        for(int i=0;i<postmirror.size();i++){
//            if(!i) cout << postmirror[i] ;
//			else cout << " " << postmirror[i]; 
//        }
//	}
//    else {
//    	cout << "NO" << endl;
//	}
//    return 0;
//}
