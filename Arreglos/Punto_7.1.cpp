#include <iostream>
using namespace std;

int romanCharToValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToArabic(string roman) {
    int result = 0;
    int prevValue = 0;

    for (int i = roman.length() - 1; i >= 0; i--) {
        int current = romanCharToValue(roman[i]);

        if (current < prevValue) {
            result -= current;
        } else {
            result += current;
        }

        prevValue = current;
    }

    return result;
}

int main() {
    string romanNumber;

    cout << "Ingrese un número romano en mayúsculas: ";
    cin >> romanNumber;

    int arabicNumber = romanToArabic(romanNumber);

    cout << "El número en formato arábigo es: " << arabicNumber << endl;

    return 0;
}
