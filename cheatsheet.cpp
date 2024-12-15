Cheat Sheet STL C++ Chi Tiết

1. Containers (Cấu trúc dữ liệu)

Sequence Containers (Cấu trúc tuần tự)

std::vector: Mảng động (dynamic array).

```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4); // Thêm phần tử 4 vào cuối vector
v.pop_back();   // Xóa phần tử cuối
v.size();       // Trả về kích thước vector
v.resize(5);    // Thay đổi kích thước vector thành 5
v.front();      // Trả về phần tử đầu tiên
v.back();       // Trả về phần tử cuối cùng
v.at(2);        // Truy cập phần tử tại vị trí 2 (an toàn hơn so với v[2])
v.insert(v.begin() + 1, 10); // Chèn 10 vào vị trí thứ 1
v.erase(v.begin()); // Xóa phần tử tại vị trí đầu tiên
v.clear();          // Xóa tất cả phần tử
```

std::deque: Hàng đợi hai đầu.

```cpp
#include <deque>
std::deque<int> dq = {1, 2, 3};
dq.push_back(4);  // Thêm phần tử vào cuối
dq.push_front(0); // Thêm phần tử vào đầu
dq.pop_back();    // Xóa phần tử cuối
dq.pop_front();   // Xóa phần tử đầu
dq.front();       // Trả về phần tử đầu tiên
dq.back();        // Trả về phần tử cuối cùng
dq.insert(dq.begin() + 1, 10); // Chèn 10 vào vị trí 1
dq.erase(dq.begin());          // Xóa phần tử tại vị trí đầu
dq.clear();                    // Xóa tất cả phần tử
```

std::list: Danh sách liên kết đôi.

```cpp
#include <list>
std::list<int> lst = {1, 2, 3};
lst.push_back(4);  // Thêm phần tử vào cuối
lst.push_front(0); // Thêm phần tử vào đầu
lst.pop_back();    // Xóa phần tử cuối
lst.pop_front();   // Xóa phần tử đầu
lst.remove(2);     // Xóa tất cả phần tử có giá trị 2
lst.sort();        // Sắp xếp danh sách
lst.reverse();     // Đảo ngược danh sách
```

Associative Containers (Cấu trúc ánh xạ)

std::set: Tập hợp các phần tử duy nhất, được sắp xếp.

```cpp
#include <set>
std::set<int> s = {3, 1, 2};
s.insert(4);    // Thêm phần tử 4
s.erase(2);     // Xóa phần tử có giá trị 2
auto it = s.find(3); // Tìm phần tử 3, trả về iterator
s.count(1);      // Kiểm tra xem phần tử 1 có tồn tại hay không
s.lower_bound(2); // Trả về iterator phần tử >= 2
s.upper_bound(2); // Trả về iterator phần tử > 2
```

std::map: Cặp khóa-giá trị, sắp xếp theo khóa.

```cpp
#include <map>
std::map<int, std::string> m;
m[1] = "One";       // Thêm cặp (1, "One")
m.insert({2, "Two"}); // Thêm cặp (2, "Two")
m.erase(1);          // Xóa cặp có khóa là 1
auto it = m.find(2); // Tìm khóa 2
m[3] = "Three";      // Thêm hoặc sửa giá trị của khóa 3
```

Unordered Containers (Cấu trúc không sắp xếp)

std::unordered_set: Tập hợp phần tử duy nhất, không sắp xếp.

```cpp
#include <unordered_set>
std::unordered_set<int> us = {1, 2, 3};
us.insert(4);
us.erase(2);
us.find(3); // Tìm phần tử 3
```

std::unordered_map: Cặp khóa-giá trị, không sắp xếp.

```cpp
#include <unordered_map>
std::unordered_map<int, std::string> um;
um[1] = "One";
um.erase(1);
um.find(2);
```

2. Iterators (Bộ lặp)

Dùng để duyệt qua các container:

```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

Các iterator phổ biến:

- begin(), end(): Duyệt từ đầu đến cuối.
- rbegin(), rend(): Duyệt từ cuối đến đầu.
- cbegin(), cend(): Duyệt từ đầu đến cuối nhưng chỉ đọc.

3. Algorithms (Thuật toán)

Sắp xếp và tìm kiếm:

```cpp
#include <algorithm>
std::vector<int> v = {3, 1, 2};
std::sort(v.begin(), v.end());           // Sắp xếp tăng dần
std::binary_search(v.begin(), v.end(), 2); // Tìm kiếm nhị phân
```

Hoán vị:

```cpp
#include <algorithm>
std::vector<int> v = {1, 2, 3};
std::next_permutation(v.begin(), v.end()); // Hoán vị kế tiếp
std::prev_permutation(v.begin(), v.end()); // Hoán vị trước đó
```

Toán tử trên tập hợp:

```cpp
std::vector<int> v1 = {1, 2, 3}, v2 = {3, 4};
std::vector<int> res;
std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(res));
```

4. Utilities (Tiện ích)

std::pair:

```cpp
#include <utility>
std::pair<int, std::string> p = std::make_pair(1, "One");
std::cout << p.first << " " << p.second;
```

std::tuple:

```cpp
#include <tuple>
std::tuple<int, double, std::string> t = std::make_tuple(1, 2.5, "Hello");
int a; double b; std::string c;
std::tie(a, b, c) = t;