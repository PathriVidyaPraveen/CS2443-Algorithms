#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int start, int mid , int end){
    int len_left = mid - start+1;
    int len_right = end - mid;
    vector<int> left(len_left);
    vector<int> right(len_right);
    for(int i=0;i<len_left;i++){
        left[i] = a[start+i];
    }
    for(int i=0;i<len_right;i++){
        right[i] = a[mid+1+i];
    }

    int i=0,j=0,k=start;
    while(i < len_left && j < len_right){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i< len_left){
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < len_right){
        a[k] = right[j];
        j++;
        k++;
    }

}  


void mergeSort(vector<int>& a, int start , int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,mid,end);
}

int main(){

    int n;
    cout << "Number of elements to be sorted: " ;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    mergeSort(a,0,n-1);
    cout << "Sorted: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;




    return 0;
}