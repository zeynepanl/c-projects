
// Zeynep ANLAYIÞLI
// 10.05.2024

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string orijinal_metin;
    cout << "Lutfen metni girin: ";
    getline(cin, orijinal_metin);

    string temizlenmis_metin = "";
    for (char c : orijinal_metin) {
        if (c != ' ') {
            temizlenmis_metin += c;
        }
    }
    int l = temizlenmis_metin.length();

    int m = floor(sqrt(l));
    int n = ceil(sqrt(l));

    if (m * n < l) {
        m++;
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m && index < l; j++) {
            cout << temizlenmis_metin[index++];
        }
        cout << endl;
    }

    cout << "m: " << m << ", n: " << n << endl;

    return 0;
}
