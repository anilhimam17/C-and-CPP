#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Opening / Creating a file in runtime.
    string filename;
    cout << "Enter name of the file: ";
    getline(cin, filename);

    ofstream out_file = ofstream(filename, std::ios::out);
    if (!out_file.is_open()) {
        cerr << "Error opening the file writing" << endl;
        return 1;
    }

    string line;
    while (true) {
        cout << "Enter content for the file: ";
        getline(cin, line);
        
        if (line == "exit")
            break;
        
        out_file << line << endl;
    }

    // Closing the file
    out_file.close();

    // Reading the contents of the file
    ifstream in_file = ifstream(filename, std::ios::in);
    if (!in_file.is_open()) {
        cerr << "Error opening the file for reading" << endl;
        return 1;
    }

    cout << "Reading the contents of the file" << endl;
    while (getline(in_file, line)) {
        cout << line << endl;
    }

    return 0;
}
