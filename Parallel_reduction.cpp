#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int minVal = arr[0];
    int maxVal = arr[0];
    int sum = 0;

    
    #pragma omp parallel for reduction(min:minVal) reduction(max:maxVal) reduction(+:sum)
    for(int i = 0; i < n; i++) {

        if(arr[i] < minVal)
            minVal = arr[i];

        if(arr[i] > maxVal)
            maxVal = arr[i];

        sum += arr[i];
    }

    float avg = (float)sum / n;

    cout << "\nMinimum = " << minVal;
    cout << "\nMaximum = " << maxVal;
    cout << "\nSum = " << sum;
    cout << "\nAverage = " << avg << endl;

    return 0;
}