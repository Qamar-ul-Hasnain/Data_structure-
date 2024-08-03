#include <iostream>
#include <string>
using namespace std;


bool compare(char a, char b) {
    return tolower(a) > tolower(b);
}


void selectionSort(string &str) {
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(str[j], str[maxIndex])) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(str[i], str[maxIndex]);
        }
    }
}

int main() {
    string input;
    cout << "Enter a string to sort in descending order: ";
    cin >> input;

    selectionSort(input);

    cout << "Sorted string in descending order: " << input << endl;

    return 0;
}

