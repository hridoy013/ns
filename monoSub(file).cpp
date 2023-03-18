#include<bits/stdc++.h>
using namespace std;

map<char, char> encMap, decMap;
string encryption_monosub(string plainText)
{
    string cipherText = "";

    for(int i=0; i<plainText.size(); i++)
    {
        cipherText += encMap[plainText[i]];
    }

    return cipherText;
}

string decryption_monosub(string cipherText)
{
    string decipherText = "";

    for(int i=0; i<cipherText.size(); i++)
    {
        decipherText += decMap[cipherText[i]];
    }
    return decipherText;
}


int main()
{
    freopen("monosubInput.txt", "r", stdin);

    for(int i=0; i<26; i++)
    {
        char a, b;
        cin >> a >> b;
        encMap[a] = b;
        decMap[b] = a;

    }
    string plainText;
    cin >> plainText;

    string cipherText = encryption_monosub(plainText);
    cout << "The cipherText is: " << cipherText << "\n";

    string decipherText = decryption_monosub(cipherText);
    cout << "The decipherText is: " << decipherText << "\n";

    return 0;
}


