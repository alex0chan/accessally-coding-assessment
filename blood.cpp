#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// creating an enumeration for all patient types for readability
enum type {
    onegative,
    opositive,
    anegative,
    apositive,
    bnegative,
    bpositive,
    abnegative,
    abpositive,
};

// using structs to group important data

struct patient {
    int available;
    type bloodtype;
};

// creating a struct for all blood types to group important data
struct unit {
    int available;
    unordered_map<type, bool> donate;
};

// global variables aren't always the best practice, but it helps with our functions
int baseoutput;
int output;

// give away blood
void donate(int numbers[], unit units[], patient patients[]) {

    // we will compare this against our current highest output
    int test = baseoutput;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(units[numbers[i]].available > 0 && units[numbers[i]].donate[patients[j].bloodtype]) {
                if(units[numbers[i]].available >= patients[j].available) {
                    test += patients[j].available;
                    units[numbers[i]].available -= patients[j].available;
                    patients[j].available = 0;
                } else {
                    test += units[numbers[i]].available;
                    patients[j].available -= units[numbers[i]].available;
                    units[numbers[i]].available = 0;
                }
            }
        }
    }

    if(test > output) {
        output = test;
    }

}

// using the next_permutation() function
// the goal is to go through all possible permutations of blood donation to find the one that maximizes donations
void permute(int numbers[], unit units[], patient patients[]) {

    sort(numbers, numbers + 8);

    do {
        // creating deep copies of the arrays so we don't lose overwrite their data
        unit u[8];
        copy(units, units + 8, u);
        patient p[8];
        copy(patients, patients + 8, p);

        donate(numbers, u, p);
    } while (next_permutation(numbers, numbers + 8));

}


int main() {

    // initializing arrays to hold our data
    // using arrays because the input is a fixed length
    unit units[8];
    patient patients[8];

    int input;
    output = 0;

    // read in our input
    for(int i = 0; i < 8; i++) {
        cin >> input;
        units[i].available = input;
    }

    for(int i = 0; i < 8; i++) {
        cin >> input;
        patients[i].available = input;
    }

    // we have a lot of background information about each blood type, so all this set up will help us later
    // this will (hopefully) allow us to mix up the order of the arrays without any issues
    
    // onegative
    units[0].donate[onegative] = true;
    units[0].donate[opositive] = true;
    units[0].donate[anegative] = true;
    units[0].donate[apositive] = true;
    units[0].donate[bnegative] = true;
    units[0].donate[bpositive] = true;
    units[0].donate[abnegative] = true;
    units[0].donate[abpositive] = true;

    // opositive
    units[1].donate[onegative] = false;
    units[1].donate[opositive] = true;
    units[1].donate[anegative] = false;
    units[1].donate[apositive] = true;
    units[1].donate[bnegative] = false;
    units[1].donate[bpositive] = true;
    units[1].donate[abnegative] = false;
    units[1].donate[abpositive] = true;

    // anegative
    units[2].donate[onegative] = false;
    units[2].donate[opositive] = false;
    units[2].donate[anegative] = true;
    units[2].donate[apositive] = true;
    units[2].donate[bnegative] = false;
    units[2].donate[bpositive] = false;
    units[2].donate[abnegative] = true;
    units[2].donate[abpositive] = true;

    // apositive
    units[3].donate[onegative] = false;
    units[3].donate[opositive] = false;
    units[3].donate[anegative] = false;
    units[3].donate[apositive] = true;
    units[3].donate[bnegative] = false;
    units[3].donate[bpositive] = false;
    units[3].donate[abnegative] = false;
    units[3].donate[abpositive] = true;

    // bnegative
    units[4].donate[onegative] = false;
    units[4].donate[opositive] = false;
    units[4].donate[anegative] = false;
    units[4].donate[apositive] = false;
    units[4].donate[bnegative] = true;
    units[4].donate[bpositive] = true;
    units[4].donate[abnegative] = true;
    units[4].donate[abpositive] = true;

    // bpositive
    units[5].donate[onegative] = false;
    units[5].donate[opositive] = false;
    units[5].donate[anegative] = false;
    units[5].donate[apositive] = false;
    units[5].donate[bnegative] = false;
    units[5].donate[bpositive] = true;
    units[5].donate[abnegative] = false;
    units[5].donate[abpositive] = true;

    // abnegative
    units[6].donate[onegative] = false;
    units[6].donate[opositive] = false;
    units[6].donate[anegative] = false;
    units[6].donate[apositive] = false;
    units[6].donate[bnegative] = false;
    units[6].donate[bpositive] = false;
    units[6].donate[abnegative] = true;
    units[6].donate[abpositive] = true;

    // abpositive
    units[7].donate[onegative] = false;
    units[7].donate[opositive] = false;
    units[7].donate[anegative] = false;
    units[7].donate[apositive] = false;
    units[7].donate[bnegative] = false;
    units[7].donate[bpositive] = false;
    units[7].donate[abnegative] = false;
    units[7].donate[abpositive] = true;

    patients[0].bloodtype = onegative;
    patients[1].bloodtype = opositive;
    patients[2].bloodtype = anegative;
    patients[3].bloodtype = apositive;
    patients[4].bloodtype = bnegative;
    patients[5].bloodtype = bpositive;
    patients[6].bloodtype = abnegative;
    patients[7].bloodtype = abpositive;

    // let's start giving out blood!
    // we'll match up exact types first because that's always going to be the most efficient
    for(int i = 0; i < 8; i++) {
        if(units[i].available > 0) {
            if(units[i].available >= patients[i].available) {
                baseoutput += patients[i].available;
                units[i].available -= patients[i].available;
                patients[i].available = 0;
            } else {
                baseoutput += units[i].available;
                patients[i].available -= units[i].available;
                units[i].available = 0;
            }
        }
    }

    output = baseoutput;

    // now for the fun part
    // the trickle down
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7};
    permute(numbers, units, patients);

    cout << output << endl;

}
