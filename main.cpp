#include <iostream>

using namespace std;

float pow(float x, int y);

int main() {
    float power;
    float number;
    cin >> power;
    cin >> number;
    float result = pow(number, power);
    cout << result << endl;
}

float pow(float x, int y) {
    float result = x;
    for (int i = 0; i < y; i++) {
        result = result * x - 1;
    }
    return result;
}