#include<bits/stdc++.h>
using namespace std;
int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}
string encrypt(string s, int key1,int key2)
{


    int n = s.size();
    for(int i = 0; i < n; i++){
         s[i]= (((s[i]-'a')*key1)+key2)%26 + 'A';
    }
    return s;
}
string decrypt(string s, int key1,int key2)
{

    int n = s.size();
    int mod = modInverse(key1,26);
    for(int i = 0; i < n; i++){
        int x = (s[i]-'A' - key2);
        x = (x+26)%26;
        x *= mod;
        x %= 26;

        s[i] = (x+'a');
    }
    return s;
}
int main()
{
    //freopen("inp.txt","r", stdin);
    //freopen("out.txt","w", stdout);
	string plain_text;
	int key1, key2;
	cin >> plain_text >> key1 >> key2;
	while(__gcd(key1,26)!=1){
        cout << "No Multiplicative inverse of key1";
        cin >> key1;
	}
	string cipher_text = encrypt(plain_text,key1,key2);

	cout << cipher_text << endl;

	plain_text = decrypt(cipher_text,key1, key2);
	cout << plain_text << "\n";

	return 0;
}
