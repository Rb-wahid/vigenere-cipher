// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>

#include <cctype>

#include <string>

using namespace std;

string toUpperCase(string str) {
  transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

string
convetedToOriginalCase(string originalCase, string upperCase) {
  string orig_text;

  for (int i = 0; i < originalCase.size(); i++) {
    char x = upperCase[i];
    if (originalCase[i] >= 'a' && originalCase[i] <= 'z') {

      x = tolower(x);
    }

    orig_text.push_back(x);

  }
  return orig_text;
}

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text

string
generateKey(string str, string key) {
  key = toUpperCase(key);
  int x = str.size();

  for (int i = 0;; i++) {
    if (x == i)
      i = 0;
    if (key.size() == str.size())
      break;
    key.push_back(key[i]);
  }
  return key;
}

// This function returns the encrypted text
// generated with the help of the key
string
cipherText(string str, string key) {
  string upperStr = toUpperCase(str);
  string cipher_text;

  for (int i = 0; i < upperStr.size(); i++) {
    if (!isalpha(upperStr[i])) {
      cipher_text.push_back(upperStr[i]);
    } else {

      // converting in range 0-25
      char x = (upperStr[i] + key[i]) % 26;

      // convert into alphabets(ASCII)

      x += 'A';

      cipher_text.push_back(x);
    }
  }
  return convetedToOriginalCase(str, cipher_text);
}

// This function decrypts the encrypted text
// and returns the original text
string
originalText(string cipher_text, string key) {
  string orig_text;
  string upperStr = toUpperCase(cipher_text);
  for (int i = 0; i < upperStr.size(); i++) {
    if (!isalpha(upperStr[i])) {

      orig_text.push_back(upperStr[i]);
    } else {
      // converting in range 0-25
      char x = (upperStr[i] - key[i] + 26) % 26;

      // convert into alphabets(ASCII)

      x += 'A';

      orig_text.push_back(x);
    }
  }
  return convetedToOriginalCase(cipher_text, orig_text);
}

bool isValidKey(string str, string key) {
  return str.size() >= key.size();
}

void
intro() {
  cout <<
    "===================================================================" <<
    "\n";
  cout <<
    "    Welcom to Vigenere Cipher encrypting alphabetic text System    " <<
    "\n";
  cout <<
    "===================================================================" <<
    "\n";
  cout <<
    "                                                                   " <<
    "\n";

}

void design() {
  cout <<
    "\n===================================================================" <<
    "\n";
}

// Driver program to test the above function
int
main() {
  intro();
  string str;
  string keyword;
  string key;
  int option;
  bool isContinue = true;

  while (isContinue) {
    cout << "\nEnter 1 for Encryption OR 2 for Decryption or 0 for exit : ";
    cin >> option;
    if (option == 0) {
      cout << option;
      isContinue = false;
      break;
    }
    cin.ignore(256, '\n');
    cout << "\nEnter message or type exit : ";
    getline(cin, str);

    if (str == "exit") {
      isContinue = false;
      break;
    }

    cout << "\nEnter key (less than message's length) : ";
    while (true) {
      cin >> keyword;
      if (isValidKey(str, keyword)) {
        key = generateKey(str, keyword);
        break;
      }
      cout << "\nWARNING : Invalid key";
    }

    cin.ignore(256, '\n');

    switch (option) {
    case 0: {
      isContinue = false;
      break;
    }
    case 1: {
      design();
      string encryptedStr = cipherText(str, key);
      cout << "\nYour Encrypted message -:" << encryptedStr << "\n";
      design();
      break;
    }
    case 2: {
      string decryptedStr = originalText(str, key);
      design();
      cout << "\nYour Decrypted message -:" << decryptedStr << "\n";
      design();
      break;
    }
    default: {
      cout << "\nWARNING : Invalid input";
    }
    }
  }

  return 0;
}
