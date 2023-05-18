#include <iostream>
using namespace std;

int main() {
    // initializing arrays to hold our data
    int units[8];
    int patients[8];

    int input;
    int output = 0;

    // read in our input
    for(int i = 0; i < 8; i++) {
        cin >> input;
        units[i] = input;
    }

    for(int i = 0; i < 8; i++) {
        cin >> input;
        patients[i] = input;
    }

    // let's start giving out blood!
    // first we'll match up the exact types
    for(int i = 0; i < 8; i++) {
        if(units[i] >= patients[i] && units[i] > 0) {
            output += patients[i];
            units[i] -= patients[i];
            patients[i] = 0;
        } else if(units[i] > 0) {
            output += units[i];
            patients[i] -= units[i];
            units[i] = 0;
        }
    }

    // cout << output << endl;

    // for(int i = 0; i < 8; i++) {
    //     cout << units[i] << endl;
    //     cout << patients[i] << endl;
    // }

    // now we can drip down :D
    // ideally we could make this less case-by-case and more efficient with more time
    for(int i = 0; i < 7; i++) {
        if(units[i] > 0) {

            // o negative
            if(i == 0) {
                for(int j = 1; j < 8; j++) {
                    if(units[i] >= patients[j] && units[i] > 0) {
                        output += patients[j];
                        units[i] -= patients[j];
                        patients[j] = 0;
                    } else if(units[i] > 0) {
                        output += units[i];
                        patients[j] -= units[i];
                        units[i] = 0;
                    }
                }
            }
            // o positive
            else if(i == 1) {
                for(int j = 3; j < 8; j += 2) {
                    if(units[i] >= patients[j] && units[i] > 0) {
                        output += patients[j];
                        units[i] -= patients[j];
                        patients[j] = 0;
                    } else if(units[i] > 0) {
                        output += units[i];
                        patients[j] -= units[i];
                        units[i] = 0;
                    }
                }
            }
            // a negative
            else if(i == 2) {
                for(int j = 3; j < 8; j++) {
                    if(units[i] >= patients[j] && units[i] > 0) {
                        output += patients[j];
                        units[i] -= patients[j];
                        patients[j] = 0;
                    } else if(units[i] > 0) {
                        output += units[i];
                        patients[j] -= units[i];
                        units[i] = 0;
                    }
                    if(j == 3) {
                        j += 2;
                    }
                }
            }
            // b negative
            else if(i == 4) {
                for(int j = 5; j < 8; j++) {
                    if(units[i] >= patients[j] && units[i] > 0) {
                        output += patients[j];
                        units[i] -= patients[j];
                        patients[j] = 0;
                    } else if(units[i] > 0) {
                        output += units[i];
                        patients[j] -= units[i];
                        units[i] = 0;
                    }
                }
            }
            // a positive, b positive, ab negative
            else if(i == 3 || i == 5 || i == 6) {
                if(units[i] >= patients[7] && units[i] > 0) {
                    output += patients[7];
                    units[i] -= patients[7];
                    patients[7] = 0;
                } else if(units[i] > 0) {
                    output += units[i];
                    patients[7] -= units[i];
                    units[i] = 0;
                }
            }

        }
    }

    cout << output << endl;
}