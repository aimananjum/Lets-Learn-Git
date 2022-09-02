#include <bits/stdc++.h>
using namespace std;

int countsubsetsum(int a[],int sum,int n){
	int t[n+1][sum+1];
	for(int i=0;i<n+1;i++){
		t[i][0]=1;
	}
	for(int i=1;i<sum+1;i++){
		t[0][i]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(a[i-1]<=j){
				t[i][j]=(t[i-1][j]+t[i-1][j-a[i-1]]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

int countsubsetdiff(int a[],int diff,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	int resum=(diff+sum)/2;
	return countsubsetsum(a,resum,n);
}

int main(){
	int n,diff;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>diff;
	int ans = countsubsetdiff(a,diff,n);
	cout<<ans;
	return 0;
}