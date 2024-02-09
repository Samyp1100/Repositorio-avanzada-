#include <iostream>
#include <algorithm>

using namespace std;

const int n = 5; 
void ordenarCadenas(string conjuntoCadenas[]) {
    sort(conjuntoCadenas, conjuntoCadenas + n);
}

int main() {
    string conjunto[] = {"perro", "gato", "elefante", "abeja", "ballena"};

    cout << "Conjunto antes de ordenar:" << endl;
    for (int i = 0; i < n; i++) {
        cout << conjunto[i] << " ";
    }
    cout << endl;
    ordenarCadenas(conjunto);
    cout << "Conjunto después de ordenar:" << endl;
    for (int i = 0; i < n;i++) {
        cout << conjunto[i] << " ";
    }
    cout << endl;

    return 0;
}
