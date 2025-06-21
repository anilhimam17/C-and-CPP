#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> s1;
    s1.push(1);
    s1.emplace(2);

    // Making a copy of the stack for traversal
    auto s2 = s1;
    cout << "Traversing the elements of the default stack" << endl;
    for (auto it = s2.top(); it != s2.empty(); ) {
        cout << "Element: " << it << endl;
        s2.pop();
    }
    return 0;
}
