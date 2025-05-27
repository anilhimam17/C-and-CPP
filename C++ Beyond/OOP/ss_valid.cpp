#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter bio data as follows:" << endl;
    string name, month, base, input;
    int day, year;
    stringstream ss;

    bool done = false;
    do {
        cout << "Enter name: ";
        getline(cin, input);
        
        bool valid = !input.empty();
        if (valid) {
            for (char c: input) {
                if ((!isalpha(c)) && (!isspace(c))) {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid)
            cout << "Please enter a name as a string" << endl;
        else {
            name = input;
            done = true;
        }
    } while (!done);

    done = false;
    do {
        cout << "Enter day: ";
        getline(cin, input);
        ss = stringstream(input);
        if (!(ss >> day))
            cout << "Please enter a valid day" << endl;
        else
            done = true;
    } while (!done);

    done = false;
    do {
        cout << "Enter month: ";
        getline(cin, input);
        
        bool valid = !input.empty();
        if (valid) {
            for (char c: input) {
                if ((!isalpha(c)) && (!isspace(c))) {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid)
            cout << "Please enter a month as a string" << endl;
        else {
            month = input;
            done = true;
        }
    } while (!done);

    done = false;
    do {
        cout << "Enter year: ";
        getline(cin, input);
        ss = stringstream(input);
        if (!(ss >> year))
            cout << "Please enter a valid year" << endl;
        else
            done = true;
    } while (!done);

    done = false;
    do {
        cout << "Enter base: ";
        getline(cin, input);
        
        bool valid = !input.empty();
        if (valid) {
            for (char c: input) {
                if ((!isalpha(c)) && (!isspace(c))) {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid)
            cout << "Please enter a base as a string" << endl;
        else {
            base = input;
            done = true;
        }
    } while (!done);

    cout << name << " " << day << " " << month << " " << year << " " << base << endl;

    return 0;
}
