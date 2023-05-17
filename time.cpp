#include <iostream>
using namespace std;

struct time {
    int first;
    int second;
};

int main() {
    struct time hours;
    // acceptable values
    // 0-1
    hours.first = 1;
    // 0-9
    hours.second = 2;

    struct time minutes;
    // 0-5
    minutes.first = 0;
    // 0-9
    minutes.second = 0;

    int input;
    cin >> input;

    // variable to count artithmetic sequences
    int output = 0;

    for(int i = 0; i < input; i++) {
        // check for an arithmetic sequence
        if((minutes.second - minutes.first) == (minutes.first - hours.second)) {
            if(hours.first == 0) {
                output++;
            } else if((minutes.first - hours.second) == (hours.second - hours.first)) {
                output++;
            }
        }

        // increment the time
        if(minutes.second < 9) {
            minutes.second++;
        } else {
            minutes.second = 0;
            if(minutes.first < 5) {
                minutes.first++;
            } else {
                minutes.first = 0;
                if(hours.first == 0 && hours.second < 9) {
                    hours.second++;
                } else if(hours.first == 0) {
                    hours.first = 1;
                    hours.second = 0;
                } else if(hours.second < 2) {
                    hours.second++;
                } else {
                    hours.first = 0;
                    hours.second = 1;
                }
            }
        }
        // cout << hours.first << hours.second << ":" << minutes.first << minutes.second << endl;
    }

    // check the final time
    if((minutes.second - minutes.first) == (minutes.first - hours.second)) {
        if(hours.first == 0) {
            output++;
        } else if((minutes.first - hours.second) == (hours.second - hours.first)) {
            output++;
        }
    }

    cout << output << endl;
}