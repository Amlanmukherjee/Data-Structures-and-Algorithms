#include <iostream>
using namespace std;

void subset(string input_string, string ouput_string) {
    if(input_string.empty()) {
        if(ouput_string.empty()) {
            cout << "NULL ";
        }
        else {
            cout << ouput_string << " ";
        }
        return;
    }
    char append = input_string.at(0);
    input_string = input_string.erase(0, 1);

    subset(input_string, ouput_string);
    subset(input_string, ouput_string+append);
}

int main() {
    string input_string;
    string ouput_string = "";
    cout << "ENTER A STRING: ";
    cin >> input_string;
    subset(input_string, ouput_string);
    return 0;
}