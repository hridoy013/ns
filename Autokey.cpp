#include<bits/stdc++.h>
using namespace std;
string encryption(string s, int key)
{
    for(int i = 0; i < s.length(); i++)
    {
        int temp = s[i]-'a';
        s[i] = (s[i]-'a' + key)%26+'A';
        key = temp;
    }
    return s;
}
string decryption(string s, int key)
{
    for(int i = 0; i < s.length(); i++)
    {

        s[i] = (s[i] - key - 'A'+26)%26 + 'a';
        int tem =s[i]-'a';
        key = tem;
    }
    return s;
}
int main()
{
    freopen("ainp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string plain_text;
    int key;
    cin >> plain_text >> key;
    string cipher_text = encryption(plain_text,key);
    int  n = plain_text.length();
    for(int i = 0; i < n; i++)
    {
        cipher_text[i] = toupper(cipher_text[i]);
    }
    cout << "ciphertext: ";
    cout << cipher_text << "\n";
    plain_text = decryption(cipher_text,key);
    cout << "plaintext: ";
    cout << plain_text << "\n";

    return 0;
}
