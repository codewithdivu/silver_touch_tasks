#include <bits/stdc++.h>
using namespace std;

template <typename T>
class view_vec_add {
private:
    const vector<T>& l;
    const vector<T>& r;
public:
    view_vec_add(const vector<T>& l, const vector<T>& r) : l(l), r(r) {}
    vector<T> operator()() {
        vector<T> result(l.size());
        for (size_t i = 0; i < l.size(); ++i) {
            result[i] = l[i] + r[i];
        }
        return result;
    }
};

template <typename T>
view_vec_add<T> operator+(const vector<T>& l, const vector<T>& r) {
    return view_vec_add<T>(l, r);
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    auto v3 = v1 + v2; 
    
    vector<int> v4 = v3(); 
    for (size_t i = 0; i < v4.size(); ++i) {
        cout << v4[i] << " ";
    }
    cout << endl;
}