#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;


void bubbleSort(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {

       
        #pragma omp parallel for
        for(int j = 0; j < n-1; j += 2) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }

       
        #pragma omp parallel for
        for(int j = 1; j < n-1; j += 2) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void merge(vector<int>& a, int l, int m, int r) {

    vector<int> temp;
    int i = l, j = m+1;

    while(i <= m && j <= r) {
        if(a[i] < a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);

    for(int k = 0; k < temp.size(); k++)
        a[l+k] = temp[k];
}

void mergeSort(vector<int>& a, int l, int r) {

    if(l < r) {
        int m = (l+r)/2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(a, l, m);

            #pragma omp section
            mergeSort(a, m+1, r);
        }

        merge(a, l, m, r);
    }
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> b = arr;

    bubbleSort(b, n);

    cout << "\nBubble Sort Output: ";
    for(int x : b)
        cout << x << " ";

 
    vector<int> m = arr;

    mergeSort(m, 0, n-1);

    cout << "\nMerge Sort Output: ";
    for(int x : m)
        cout << x << " ";

    return 0;
}