#include<stdio.h>
#include<string.h>

char a[20], b[20];     // a[] array-র মধ্যে ciphertext জমা করা হবে, আর b[] এর মধ্যে deciphertext

int mulInv(int k)
{
    for(int i=1; i<26; i++)     // কোন number এর  multiplicative inverse হবে ১ থেকে ২৫ এর মধ্যে ঐ number, যার সাথে গুন করে 26 দিয়ে mod করলে answer 1 আসবে
    {
        if((k * i) % 26 == 1)      // যদি এমন number পাই, তাহলে ঐটা রে return করে দেবো
            return i;
    }
    return -1;                  // আর যদি কোন multiplicative inverse না পাই, তাহলে -1 return করে দেবো
}

void encrypt(char p[], int k)              // Ciphertext এর Formula টা ছিলো এমন: C = (P * k) % 26
{                                                         // p[i] হচ্ছে lowercase character, char এর সাথে তো আর k, number গুন করা যাবে না
    for(int i=0; i<strlen(p); i++)                              // এইটা থেকে 'a' বাদ দিলে number পাবো, আর number এর সাথেই k গুন করা লাগবে, then mod করবো
    {                                                               // আর lastly 'A' যোগ করে দিলে, এইটা আবার number থেকে uppercase character হয়ে যাবে
        a[i] = (((p[i]-'a') * k) % 26) + 'A';                       // By the way, আমরা কিন্তু ciphertext টা global array a[] তে store করছি, পরে এইটা কে c[] array তে দিয়ে দিবো
    }
}

void decrypt(char c[], int k)
{
    int k_inv = mulInv(k);    // k এর multiplicative inverse টা mulInv() function দিয়ে বের করে k_inv এ store করলাম
                                                        // Deciphertext এর Formula টা ছিলো এমন: P = (C * k_INV) % 26
    for(int i=0; i<strlen(c); i++)                           // c[i] হচ্ছে uppercase character, char এর সাথে তো আর k_inv, number গুন-যোগ করা যাবে না
    {                                                               // এইখানেও encrypt এর মতোন same কাজ করা লাগবে, কিন্তু আগেরবার  শুরুতেছোটা হাতের 'a' বাদ দিছি, আর এইবার বড় হাতের 'A' যোগ করবো
        b[i] = (((c[i] + 'A') * k_inv) % 26) + 'a';               // আর শেষে 'a' যোগ করলে number থেকে lowercase character হয়ে যাবে, আর এইবার কিন্তু b[] তে রাখছি
    }
}

int main(){

    char p[20], c[20], d[20];       // p[] তে রাখবো, plaintext, c[] তে ciphertext আর d[] তে deciphertext
    int k;

    scanf("%s %d", p, &k);     // input নিলাম plaintext, key
    while(mulInv(k) == -1)         // key এর যদি multiplicative inverse না থাকে (-1 মানে নাই), তাহলে key আবারো input নেওয়া লাগবে
    {
        printf("k does not have multiplicative inverse. Enter Key values again:\n");
        scanf("%d",&k); // যতক্ষণ ভুল key দেবে, ততক্ষণ input নিতে থাকবো
    }

    encrypt(p, k); // encrypt() function এ plaintext আর key টা pass করে দিলাম, এই function টা a[] array-র মধ্যে ciphertext জমা করে দেবে
    strcpy(c, a);   // a[] তে যেই ciphertext জমা করছি, ওইটা c[] array-র মধ্যে copy করে ফেলবো
    printf("Ciphertext: %s\n", c);

    decrypt(c, k); // decrypt() function এ ciphertext আর key টা pass করে দিলাম, এই function টা b[] array-র মধ্যে deciphertext জমা করে দেবে
    strcpy(d, b);   // b[] তে যেই deciphertext জমা করছি, ওইটা d[] array-র মধ্যে copy করে ফেলবো
    printf("Deciphertext: %s\n", d);

    return 0;
}

