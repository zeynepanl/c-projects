
// Zeynep ANLAYIÞLI
// 10.05.2024


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

const int adim_sayisi = 10;
const int min_mesafe = 5;
const int max_mesafe = 20;

int generate_random_point() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, max_mesafe);
    return dis(gen);
}

int main() {
    vector<int> visited_points;
    visited_points.push_back(0); 

    for (int i = 0; i < adim_sayisi - 1; ++i) {
        int next_point;
        do {
            next_point = generate_random_point();
        } while (find(visited_points.begin(), visited_points.end(), next_point) != visited_points.end() ||
            abs(next_point - visited_points.back()) < min_mesafe);

        visited_points.push_back(next_point);
    }

    cout << " Mini Ada'nin gezinti haritasi: [ ";
    for (int i = 0; i < visited_points.size(); ++i) {
        cout << visited_points[i];
        if (i != visited_points.size() - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
    return 0;
}
