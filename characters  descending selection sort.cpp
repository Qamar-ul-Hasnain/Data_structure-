#include <iostream>

using namespace std;


bool charComp(char a, char b) {
    return tolower(a) > tolower(b);
}


void selectionSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (charComp(arr[j], arr[maxIndex])) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Swap the characters
            char temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the no of char ";
    cin >> n;

    char arr[n];

    cout << "Enter char " << n <<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "characters in descending order  ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

