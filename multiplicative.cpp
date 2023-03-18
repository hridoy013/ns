#include<bits/stdc++.h>
using namespace std;
int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++){
        if (((A % M) * (X % M)) % M == 1){
            return X;
        }
    }
}
string encryption(string s, int k)
{
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] - 'a') * k)%26 + 'A';
    }
    return s;
}
string decryption(string s, int k)
{
    int n = s.length();
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] - 'A') * k)%26 + 'a';
    }
    return s;
}
int main()
{
    //freopen("min.txt","r",stdin);
    //freopen("mout.txt","w",stdout);
    string plain_text;
    int key;
    cout <<"Enter Plain Text & Key: ";
    cin >> plain_text >> key;


    while(__gcd(26,key)!=1)
    {
        cout <<"Invalid key!"<<"\n";
        cout <<"Enter valid key: ";
        cin >>key;
    }
    int mod = modInverse(key,26);
    string cipher_text = encryption(plain_text,key);
    cout << "Cipher Text : " << cipher_text << "\n";
    plain_text = decryption(cipher_text,mod);
    cout << "Plain Text : " << plain_text << "\n";

    return 0;
}
