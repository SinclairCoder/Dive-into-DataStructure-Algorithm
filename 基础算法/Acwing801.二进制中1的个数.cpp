#include<iostream>

using namespace std;
int n,x;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        int res = 0;
        while(x) x -= x&(-x), res++;
        cout << res << " ";
    }
    return 0;
}
