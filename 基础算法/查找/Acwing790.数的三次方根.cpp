#include<iostream>

using namespace std;

const double eps = 1e-8;
int main(){
    double n;
    scanf("%lf",&n);
    double l = 0, r = n;
    // 要考虑负数的情况....
    if(n<0) l = n, r = 0;
    while(r-l>eps){
        double mid = (l+r)/2;
        if(mid*mid*mid>=n) r = mid;
        else l = mid;
    }
    printf("%.6lf",l);
    
    return 0;
}
