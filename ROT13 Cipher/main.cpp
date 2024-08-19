#include <bits/stdc++.h>

using namespace std;

// Map to lookup the index of alphabets
    // Declare a map where keys are characters and values are integers

//  This code has characters as keys and numbers
// as values
map <char,int> dict1;

// Map to lookup alphabets corresponding to
// the index after shift

// This map has numbers as keys and the 
// letters as values
map <int,char> dict2;



// Function to create map to lookup

void create_dict(){

    for(int i = 1; i < 27; i++)
        dict1[char(64+i)] = i;
    
    dict2[0] = 'Z';

    for(int i = 1; i < 26; i++)
        dict2[i] = char(64 + i);

    return;

}


// Function to actually encrypt the string 
// and uses the shift provided


string encrypt(string message, int shift){

    string cipher = "";
    for(int i = 0; i < message.size(); i++){

        // Checks each character of the string message
        if(message[i] != ' '){
            // looks up the map and adds the shift to the index

            int num = (dict1[message[i]] + shift) %26;

            // look at the second map for the shifted alphabets and add them
            cipher += dict2[num];
        } else {
            // adds space (why do we add space ?)
            cipher += " ";
        }
    }
    return cipher;
}

// Function to decrypt the string with the provided shift

string decrypt(string message, int shift){

    string decipher = "";
    for(int i=0; i < message.size(); i++){

        // checks for space
        if(message[i] != ' '){

            // lookups up the map and subtracts the shift to the index
            int num = (dict1[message[i]] - shift + 26) % 26;
            // looks up the second map for the shifter alphabets and adds them
            decipher += dict2[num];
        }
        else{
                // adds space
                decipher += " ";
        }
    }
    return decipher;
}


// Driver code
int main(){
    create_dict();

    string message;
    string operation;

    cout << "Encrypt or Decrypt (E/D) : ";
    cin >> operation;
    cout << "Enter String Here : ";
    cin >> message;

    int shift = 13;

    if (operation == "E"){
        cout << encrypt(message,shift) << "\n";
        
    } else if (operation == "D"){

        cout << decrypt(message,shift) << "\n";
    }

    return 0;

}


// Code Made witht the help of Sachin Bisht , and https://www.geeksforgeeks.org/rot13-cipher/