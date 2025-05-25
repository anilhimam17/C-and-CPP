#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<shared_ptr<int>> vec_ptrs;

    shared_ptr<int> s1 = make_shared<int>(10);
    cout << "Use count for 10: " << s1.use_count() << endl;

    auto s2 = make_shared<int>(20);
    cout << "Use count for 20: " << s2.use_count() << endl;

    shared_ptr<int> s3 = s1;
    cout << "Use count for 10: " << s3.use_count() << endl;

    auto s4 = s2;
    cout << "Use count for 20: " << s4.use_count() << endl;

    // Populating the vector
    vec_ptrs.push_back(s1);
    vec_ptrs.push_back(s2);
    vec_ptrs.push_back(s3);
    vec_ptrs.push_back(s4);

    for (auto const &ptr : vec_ptrs) {
        cout << "Integer value: " << *ptr << endl;
    }

    s1.reset();
    for (auto const &ptr : vec_ptrs) {
        cout << "Integer value: " << *ptr << " Use Count: " << ptr.use_count() << endl;
    }

    return 0;
}
