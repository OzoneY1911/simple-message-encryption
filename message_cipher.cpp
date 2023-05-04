#include <iostream>                     // To use i/o
#include <string>                       // To use C++ strings
#include <algorithm>                    // To use reverse()
#include <chrono>                       // To use milliseconds()
#include <thread>                       // To use sleep_for()

// The next few lines are to avoid use of the whole C++ Standard Library

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;                     // Function allows cin to accept whole line with whitespaces as input
using std::chrono::milliseconds;        // Function allows to use milliseconds to interpret time
using std::this_thread::sleep_for;      // Function allows to stop program for time specified in the previous function

int main()
{
    
    string original_symbol;             // Will store symbols from ASCII Chart
    string original_message;            // Original message entered by user

    for (char s {' '}; s <= '~'; s++)   // Fill from 32th to 126th symbol inclusively (ASCII Chart)
        original_symbol += s;

    string encrypted_symbol {original_symbol};      // A cipher string
    reverse(encrypted_symbol.begin(), encrypted_symbol.end());      // Fill with 32..126 ASCII symbols in reversed order

    cout << "\nEnter message to encipher: ";        // Ask user for message he wants to encipher
    getline(cin, original_message);                 // Get whole message entered by user

    if((original_message.size() != 0) && (original_message != " ")) {

        // This is executed only if user entered something and not just whitespace

        string encrypted_message;       // Will store message after encryption
        string decrypted_message;       // Will store message after decryption
        size_t position{};              // Will store index of string used further

        cout << "\nEncrypting message...";          // Show the user that encrypting started

        for (auto val : original_message) {

            // Check every index in the message

            position = original_symbol.find(val);               // Find symbol and set its index
            encrypted_message += encrypted_symbol.at(position); // Add an encrypted symbol from cipher at the same index

        }

        sleep_for(milliseconds(1500));                          // Pretend that process is going for some time
        cout << "\n\nEncrypted message is: " << encrypted_message << endl;  // Display message after encryption
        sleep_for(milliseconds(3000));
        cout << "\nDecrypting message now... ";                 // Will decipher message now
        sleep_for(milliseconds(1500));

        for (auto val : encrypted_message) {
            
            // Decryption of encrypted message

            position = encrypted_symbol.find(val);
            decrypted_message += original_symbol.at(position);

        }

        cout << "\n\nDecrypted message is: " << decrypted_message << endl;

    }
    else {

        system("CLS");
        cout << "\nNothing to encipher. Please restart the program and try again.\n";

    }

    return 0;
}