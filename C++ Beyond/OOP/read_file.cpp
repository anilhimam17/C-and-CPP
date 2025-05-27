#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    std::ifstream my_file = std::ifstream("file.txt", std::ios::in);

    // Sanity Check
    if (!my_file.is_open()) {
        cerr << "There was an issue in opening / accessing the contents of the file." << endl;
        return 1;
    }

    // cout << "Reading the file line by line" << endl;
    // string line;
    // while (!my_file.eof()) {
    //     std::getline(my_file, line);
    //     cout << line << endl;
    // }

    cout << "Reading the file by character" << endl;
    char c;
    while (my_file.get(c)) {
        cout << c;
    }

    return 0;
}
