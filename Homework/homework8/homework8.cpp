#include <iostream>
using namespace std;

// attack with no parameters
void attack() {
    cout << "You punch the rock!" << endl;
}

// attack with damage
void attack(int damage) {
    cout << "You hit the rock and deal " << damage << " damage!" << endl;
}

// attack with spell and damage
void attack(string spell, int damage) {
    cout << "You cast " << spell << " and deal " << damage << " damage!" << endl;
}

int main() {
    attack();                 // basic attack
    attack(10);               // attack with damage
    attack("Fireball", 25);   // magical attack

    return 0;
}
