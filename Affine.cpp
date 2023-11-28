#include <iostream>
#include <string>
using namespace std;

int Inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
        else
    return -1; 
}

string CryptageAffine(string message, int a, int b) {
    string result = "";
    int m = 26; 

    for (char& c : message) {
        if (isalpha(c)) {
            char lettre = ((a * (c - 'a') + b) % m) + 'a';
            result += lettre;
        } else {
            result += c;
        }
    }
    return result;
}

string DecryptageAffine(string message, int a, int b) {
    string result = "";
    int m = 26; 
    int Invers = Inverse(a, m);

    for (char& c : message) {
        if (isalpha(c)) {
            char lettre = (Invers * (c - 'a' - b + m)) % m + 'a';
            result += lettre;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string message;
    int a, b;

    cout << "Entrez le message à crypter/décrypter : ";
    getline(cin, message);

    cout << "Entrez la première clé (a) pour le chiffrement affine : ";
    cin >> a;

    cout << "Entrez la deuxième clé (b) pour le chiffrement affine : ";
    cin >> b;

    string messagecrypter = CryptageAffine(message, a, b);
    string messagedecrypter = DecryptageAffine(message, a, b);

    cout << "Message crypté : " << messagecrypter << endl;
    cout << "Message décrypté : " << messagedecrypter << endl;

    return 0;
}
