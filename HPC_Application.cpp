#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    int n;

    cout << "Enter number of patients: ";
    cin >> n;

    float temp[n];

    cout << "Enter temperature of patients:\n";

    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    cout << "\nPatient Risk Prediction:\n";

    
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {

        if(temp[i] > 100) {

            #pragma omp critical
            cout << "Patient " << i+1 << " : High Risk\n";

        } else {

            #pragma omp critical
            cout << "Patient " << i+1 << " : Low Risk\n";
        }
    }

    return 0;
}