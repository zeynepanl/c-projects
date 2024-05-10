
// Zeynep ANLAYIÞLI
// 10.05.2024

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

void append(string& text, const string& s) {
    text += s;
}

void delete_last_k(string& text, int k) {
    if (k >= text.size()) {
        text = "";
    }
    else {
        text.erase(text.size() - k);
    }
}

void print(const string& text, int k) {
    if (k >= text.size()) {
        cout << text << endl;
    }
    else {
        cout << text.substr(0, k) << endl;
    }
}

void undo(stack<string>& history, string& text) {
    if (!history.empty()) {
        text = history.top();
        history.pop();
    }
}

void save_file(const string& text, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << text;
        file.close();
    }
    else {
        cout << "Dosya acilamiyor." << endl;
    }
}

int main() {
    string text = "";
    stack<string> history;

    while (true) {
        cout << "Enter command (append, delete, print, undo, save): "<< endl;
        cout << "Komutla birlikte karakter sayisi da giriniz."<<endl;
        string command;
        cin >> command;

        if (command == "append") {
            string s;
            cin >> s;
            history.push(text);
            append(text, s);
        }
        else if (command == "delete") {
            int k;
            cin >> k;
            history.push(text);
            delete_last_k(text, k);
        }
        else if (command == "print") {
            int k;
            cin >> k;
            print(text, k);
        }
        else if (command == "undo") {
            undo(history, text);
        }
        else if (command == "save") {
            string filename;
            cin >> filename;
            save_file(text, filename);
            break; 
        }
        else {
            cout << " Gecersiz komut." << endl;
        }
    }

    return 0;
}
