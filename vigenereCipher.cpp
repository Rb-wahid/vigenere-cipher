// C++ code to implement Vigenere Cipher
#include<bits/stdc++.h>

#include <cctype>

#include <string>

using namespace std;

string toUpperCase (string str) {
  transform (str.begin (), str.end (), str.begin (),::toupper);
  return str;
}

string convetedToOriginalCase (string originalCase, string upperCase) {
  string orig_text;

  for (int i = 0; i < originalCase.size (); i++){
      char x = upperCase[i];
      if (originalCase[i] >= 'a' && originalCase[i] <= 'z'){
        x = tolower (x);
	    }

      orig_text.push_back (x);
    }
  return orig_text;
}

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text

string generateKey (string str, string key) {
  key = toUpperCase(key);
  int x = str.size ();

  for (int i = 0;; i++){
      if (x == i)
	      i = 0;
      if (key.size () == str.size ())
      	break;
      key.push_back(key[i]);
    }
  return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText (string str, string key) {
  string upperStr = toUpperCase (str);
  string cipher_text;

  for (int i = 0; i < upperStr.size (); i++){
      char x = upperStr[i];
      // if value is alphabet then converting
      if (isalpha (x)){
	      // converting in range 0-25
	       x = (upperStr[i] + key[i]) % 26;
	      // convert into alphabets(ASCII)
	      x += 'A';
	    }
    
      cipher_text.push_back (x);
    }
  // converted cipher_text to original case. str is the original case
  cipher_text = convetedToOriginalCase (str, cipher_text);

  return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText (string cipher_text, string key){
  string orig_text;
  string upperStr = toUpperCase (cipher_text);
  for (int i = 0; i < upperStr.size (); i++){
      char x = upperStr[i];
      if (isalpha (x)){
	      // converting in range 0-25
	      x = (upperStr[i] - key[i] + 26) % 26;
	      // convert into alphabets(ASCII)
	      x += 'A';
	     }
     orig_text.push_back (x);
    }
  // converted orig_text to original case. cipher_text is the original case
  orig_text = convetedToOriginalCase (cipher_text, orig_text);
  return orig_text;
}

bool isValidKey (string str, string key){
  return str.size () >= key.size ();
}


// Driver program to test the above function
int main() {
  string str;
  string keyword;
  string key;

  cout << "\nEnter message ->";
  getline (cin, str);		// input message

// while loop for sure , input is valid
  while (true){
    cout << "\nEnter key (less than message's length) ->";
    cin >> keyword;
    if (isValidKey (str, keyword)){
	    //keyword is repeated in a circular manner until it matches the length of the message
	   key = generateKey (str, keyword);
	   break;
	  }
      cout << "\nWARNING : Invalid key\n";
    }

  //  cin.ignore(256, '\n');

  string encryptedStr = cipherText (str, key);
  cout << "\nYour Encrypted message ->" << encryptedStr << "\n";

  string decryptedStr = originalText (encryptedStr, key);
  cout << "\nYour Decrypted message ->" << decryptedStr << "\n";

  return 0;
}
