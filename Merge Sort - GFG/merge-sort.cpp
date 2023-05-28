//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int n2=r-m;
         int n1=m-l+1;
         int arr1[n1];
         int arr2[n2];
         for(int i=0;i<n1;i++){
             arr1[i]=arr[l+i];
         }
         for(int i=0;i<n2;i++){
             arr2[i]=arr[m+1+i];
         }
         int i=0;
         int j=0;
         int k=l;
         while(i<n1 && j<n2){
             if(arr1[i]<=arr2[j]){
                 arr[k++]=arr1[i++];
             }
             else{
                 arr[k++]=arr2[j++];
             }
         }
         while(i<n1){
             arr[k++]=arr1[i++];
         }
         while(j<n2){
             arr[k++]=arr2[j++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(r>l){
            int m=l+(r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends