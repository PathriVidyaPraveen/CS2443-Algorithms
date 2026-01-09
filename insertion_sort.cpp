#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=2;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j+1] < a[j]){
                swap(a[j+1],a[j]);
            }
        }
    }
    cout << "Sorted: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;



    return 0;
}