#include <iostream>
#include <cstring>


using namespace std;

int main() {
    char str[100];
    cout << "What's your name?\n";
    cin.getline(str, 100);
    cout << "Here's your input!: " << str << endl;
}
