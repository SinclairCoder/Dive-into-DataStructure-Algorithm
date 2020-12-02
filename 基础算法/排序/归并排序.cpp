#include<bits/stdc++.h>

using namespace std;

/*
	归并排序 (求逆序对) 
*/ 
int res = 0;
void Merge(int a[],int low,int mid,int high){
	int i = low,j = mid + 1, k = 0;
	int* tmpa = (int *)malloc((high-low+1)*sizeof(int));
	while(i<=mid&&j<=high){
		if(a[i]<=a[j]){
			tmpa[k++] = a[i++];
		}
		else {
			tmpa[k++] = a[j++];
//			res += (mid-i)+1; // 是mid-i+1 而非j-i 
		}
	}
	while(i<=mid){
		tmpa[k++] = a[i++];
	}
	while(j<=high){
		tmpa[k++] = a[j++];
	}
	for(k=0,i=low;i<=high;k++,i++){
		a[i] = tmpa[k];
	}
	free(tmpa);
} 


void MergeSort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	MergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
	cout << res << endl;
	return 0;
}
