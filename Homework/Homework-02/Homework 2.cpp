#include <iostream>
#include <string>
using namespace std;

int main() {
    string country;

    // 1) Ask the question
    cout << "Where do you live? ";

    // 2) Read what the user types (getline lets them type spaces too!)
    getline(cin, country);

    // 3) Print the message using their input
    cout << "I've heard great things about " << country
        << ". I'd like to go sometime." << endl;

    return 0;
}