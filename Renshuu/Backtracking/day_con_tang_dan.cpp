#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int n;
vector<int> a;
vector<int> current;
vector<string> results;

// Ham kiem tra neu day con tang dan
bool check(int value) {
    return current.empty() || value > current.back();
}

// Ham them day con hop le vao ket qua
void solution() {
    if (current.size() >= 2) {
        stringstream ss;
        for (int i = 0; i < current.size(); i++) {
            ss << current[i];
            if (i < current.size() - 1) ss << " ";
        }
        results.push_back(ss.str());
    }
}

// Ham thu cac phan tu tiep theo trong day
void trySequence(int k) {
    for (int i = k; i < n; i++) {
        if (check(a[i])) {
            current.push_back(a[i]); // Them phan tu vao day con hien tai
            solution(); // Kiem tra va them ket qua neu hop le
            trySequence(i + 1); // Thu tiep voi cac phan tu con lai
            current.pop_back(); // Loai bo phan tu vua them de thu gia tri khac
        }
    }
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    trySequence(0); // Bat dau thu tu phan tu dau tien

    sort(results.begin(), results.end()); // Sap xep ket qua theo thu tu tu dien

    for (const string &s : results) {
        cout << s << endl;
    }

    return 0;
}
