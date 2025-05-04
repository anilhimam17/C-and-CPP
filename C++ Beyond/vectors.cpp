#include <iostream>
#include <vector>
using namespace std;

void display_vector(string name, vector <int> vec) {
    cout << name << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "element " << i << ": " << vec.at(i) << endl;
    }
    cout << "\n\n";
}

void display_vector(string name, vector <vector <int>> vec) {
    cout << name << endl;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.at(i).size(); j++) {
            cout << "element " << i << j << ": " << vec.at(i).at(j) << endl;
        }
    }
    cout << "\n\n";
}

int main(int argc, char const *argv[])
{
    vector <int> vec_1;
    vector <int> vec_2(5);
    vector <int> vec_3(5, 100);
    vector <vector <int>> vec_4;
    vector <vector <int>> vec_5(2, vec_2);
    vector <vector <int>> vec_6(2, vec_3);
    
    display_vector("vector 1", vec_1);
    display_vector("vector 2", vec_2);
    display_vector("vector 3", vec_3);
    display_vector("vector 4", vec_4);
    display_vector("vector 5", vec_5);
    display_vector("vector 6", vec_6);

    for (int i = 0; i < 5; i++) {
        vec_1.push_back(i);
    }
    display_vector("Updated Vector 1", vec_1);

    for (int i = 0; i < 5; i++) {
        vec_2.push_back(i);
    }
    display_vector("Updated Vector 2", vec_2);

    for (int i = 0; i < 2; i++) {
        vector <int> new_vec(5, (i + 1) * 10);
        vec_4.push_back(new_vec);
    }
    display_vector("Updated Vector 4", vec_4);

    for (int i = 0; i < 2; i++) {
        vec_5.at(i).push_back((i + 1) * 10);
    }
    display_vector("Updated Vector 5", vec_5);

    return 0;
}
