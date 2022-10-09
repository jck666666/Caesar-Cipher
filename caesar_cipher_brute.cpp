#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char C[300]; //cipher text
char P[300]; //plain text

int key;

void decryption(int key)
{
    for (int i = 0; i < strlen(C); i++)
    {
        if (isalpha(C[i]))
        {
            /* p = D(c) = (c-k) mod 26 */
            int c;
            if (isupper(C[i]))
            {
                c = C[i] - 64; //turn ascii into 1-26

                int tmp = c - key;
                if (tmp < 0)
                {
                    tmp += 26;
                }
                else if (tmp == 0)
                {
                    tmp += 27;
                }
                P[i] = ((char)tmp % 26) + 64;
            }
            else //islower(C[i])
            {
                c = C[i] - 96; //turn ascii into 1-26

                int tmp = c - key;
                if (tmp < 0)
                {
                    tmp += 26;
                }
                else if (tmp == 0)
                {
                    tmp += 27;
                }
                P[i] = ((char)tmp % 26) + 96;
            }
        }
        else //is not alphabet
        {
            P[i] = C[i];
        }
    }
    cout << "k=" << key << ":" << P << endl;
}   

int main()
{
    cout << "Cipher Text: ";
    cin.getline(C, 300);

    cout << "Plain_Text: " << endl;

    for (int k = 1; k <= 25; k++)
    {
        decryption(k);
    }
    return 0;
}