#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Welcome to the Number Guessing Game!\n";
    const int low = 1;
    const int high = 100;
    cout << "I'm thinking of a number between " << low << " and " << high << ".\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    int secret = dist(gen);

    int attempts = 0;
    while (true) {
        cout << "Enter your guess: ";
        string line;
        if (!getline(cin, line)) {
            cout << "\nInput closed. Exiting.\n";
            break;
        }

        stringstream ss(line);
        int guess;
        if (!(ss >> guess)) {
            cout << "Please enter a valid integer.\n";
            continue;
        }

        attempts++;
        if (guess == secret) {
            cout << "Correct! You guessed the number in " << attempts << " attempts.\n";
            break;
        } else if (guess < secret) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
