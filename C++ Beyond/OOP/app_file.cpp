#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Opening the file for writing in append mode
    ofstream out_file = ofstream("copied_file.txt", std::ios::app);
    // ofstream out_file = ofstream("copied_file.txt", std::ios::ate);
    if (!out_file.is_open()) {
        cerr << "Error reading the copied file" << endl;
        return 1;
    }

    // Taking input for writing
    string line;
    out_file << "Appended Content" << endl;
    while (true) {
        cout << "Enter line to be input: ";
        getline(cin, line);

        if (line == "exit") break;

        out_file << line << endl;
    }

    out_file.close();

    // Opening the file for reading
    ifstream in_file = ifstream("copied_file.txt");
    if (!in_file.is_open()) {
        cerr << "Error reading the file." << endl;
        return 1;
    }

    cout << "Reading the contents of the appended file:" << endl;
    while (in_file) {
        getline(in_file, line);
        cout << line << endl;
    }
    return 0;
}
