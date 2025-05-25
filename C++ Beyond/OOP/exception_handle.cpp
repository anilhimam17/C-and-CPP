#include <iostream>
using namespace std;

int calc_avg(int a, int b) {
    if ((a < 0) && (b < 0))
        throw string {"Division by -ve numbers"};
    else if (b == 0)
        throw 0;
    else if (a < 0)
        throw 1;
    return a / b;
}


int main(int argc, char const *argv[])
{
    int a = -10, b = 150;
    try {
        int avg = calc_avg(a, b);
        cout << "Average: " << avg << endl;
    } 
    // catch(int &ex) {
    //     if (ex == 0)
    //         cerr << "Error zero division" << endl;
    // } 
    catch (string &ex) {
        cerr << ex << endl;
    } catch (...) {
        cerr << "Something new here needs a fix" << endl;
    }
    return 0;
}
