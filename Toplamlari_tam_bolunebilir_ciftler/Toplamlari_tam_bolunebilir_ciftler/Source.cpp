
// Zeynep ANLAYIÞLI
// 10.05.2024

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void cift_bul(vector<int>& arr, int a, int b) {
    bool bul = false;
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if ((arr[i] + arr[j]) % b == 0) {
                cout << "(" << i << ", " << j << ") ";
                bul = true;
            }
        }
    }
    if (!bul) {
        cout << "Kurala uygun cift bulunamadi." << endl;
    }
}

int main() {
    int c, d;
    cout << "Dizinin uzunlugunu girin(2 ile 1000 arasinda): ";
    cin >> c;
    while (c < 2 || c > 1000) {
        cout << "Lutfen 2 ile 1000 arasinda bir sayi girin: ";
        cin >> c;
    }

    cout << "Ciftlerin toplamini tam bolecek olan sayiyi girin(1 ile 100 arasinda): ";
    cin >> d;
    while (d < 1 || d > 100) {
        cout << "Lutfen 1 ile 100 arasinda bir sayi girin: ";
        cin >> d;
    }

    vector<int> arr(c);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-1000, 1000);

    for (int i = 0; i < c; i++) {
        arr[i] = dis(gen);
    }

    cout << "Olusturulan dizi: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Kurala uygun ciftler: ";
    cift_bul(arr, c, d);

    return 0;
}
