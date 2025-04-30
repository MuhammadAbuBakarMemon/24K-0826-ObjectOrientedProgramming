#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextEncryptor {
private:
    string text;
    string encryptedText;
    string decryptedText;

public:
    void inputText() {
        cout << "Enter String = ";
        getline(cin, text);
        cout << "Normal Text:= " << text << endl;
    }

    void encrypt() {
        encryptedText = text;
        for (int i = 0; i < encryptedText.length(); ++i) {
            encryptedText[i] = encryptedText[i] + (i + 1);
        }
    }

    void saveToFile(const string& filename) {
        ofstream fout(filename);
        fout << encryptedText;
        fout.close();
        cout << "Encrypted text inserted in file" << endl;
    }

    void readFromFile(const string& filename) {
        ifstream fin(filename);
        getline(fin, encryptedText);
        fin.close();
    }

    void decrypt() {
        decryptedText = encryptedText;
        for (int i = 0; i < decryptedText.length(); ++i) {
            decryptedText[i] = decryptedText[i] - (i + 1);
        }
    }

    void displayDecryptedText() {
        cout << "Decrypted text Read then decoded from file" << endl;
        cout << decryptedText << endl;
    }
};

int main() {
    TextEncryptor te;
    te.inputText();
    te.encrypt();
    te.saveToFile("encrypted.txt");
    te.readFromFile("encrypted.txt");
    te.decrypt();
    te.displayDecryptedText();
    return 0;
}
