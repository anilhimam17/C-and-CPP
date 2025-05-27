#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Taking input for the names of the write and copy files.
    string f_write, f_copy;
    cout << "Enter a filename for Writing: ";
    getline(cin, f_write);
    cout << "Enter a filename for Copying: ";
    getline(cin, f_copy);

    // Placeholder for reading and writing lines
    string line;

    // Writing input into the file
    ofstream out_file_origin = ofstream(f_write);
    if (!out_file_origin.is_open()) {
        cerr << "Error opening the file for reading" << endl;
        return 1;
    }

    cout << "Writing contents into the original file" << endl;
    while (true) {
        cout << "Enter new line for the file: ";
        getline(cin, line);

        if (line == "exit")
            break;

        out_file_origin << line << endl;
    }

    out_file_origin.close();

    // Copying the file
    ifstream in_file_origin = ifstream(f_write);
    ofstream out_file_copy = ofstream(f_copy);
    if (!in_file_origin || !out_file_copy) {
        cerr << "Error in reading the file for copy or creating the copy file." << endl;
        return 1;
    }

    cout << "Copying contents of the original file into the file copy." << endl;
    while (getline(in_file_origin, line))
        out_file_copy << line << endl;

    out_file_copy.close();

    // Reading the Copied File
    ifstream in_file_copy = ifstream(f_copy);
    if (!in_file_copy.is_open()) {
        cerr << "Error reading the copied file." << endl;
        return 1;
    }

    cout << "Reading the contents of the copied file." << endl;
    while (getline(in_file_copy, line))
        cout << line << endl;

    in_file_copy.close();
}