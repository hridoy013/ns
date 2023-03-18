#include<bits/stdc++.h>
using namespace std;
char key[26];
int main()
{

    for(int i = 0; i < 26; i++){
        cin >> key[i];
    }
    string plain_text;

    cin >> plain_text;

    string cipher_text = encryption(plain_text,key[]);


    return 0;
}
