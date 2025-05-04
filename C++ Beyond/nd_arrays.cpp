#include <iostream>
using namespace std;

void display_arr(string name, int nd_array[][3]) {
    cout << name << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(nd_array[i]) / sizeof(int); j++) {
            cout << "arr[" << i << "][" << j << "] = " << nd_array[i][j] << endl;
        }
    }
    cout << "\n\n";
}

int main(int argc, char const *argv[])
{
    int multi_array_1[3][3] = {0};
    int multi_array_2[3][3] = {1, 2, 3};
    int multi_array_3[3][3] = {{1, 2, 3}};
    
    display_arr("array_1", multi_array_1);
    display_arr("array_2", multi_array_2);
    display_arr("array_3", multi_array_3);
    return 0;
}
