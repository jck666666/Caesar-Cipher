#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char P[300]; //plain text
char C[300]; //cipher text
int key;

void encryption()
{

    cout << "Key: ";
    cin >> key;

    cout << "Plain Text: ";
    cin.ignore(1024, '\n');
    cin.getline(P, 300);

    for (int i = 0; i < strlen(P); i++)
    {
        if (isalpha(P[i]))
        {
            /* c = E(p) = (p+k) mod 26 */
            int p;
            if (isupper(P[i]))
            {
                p = P[i] - 64; //turn ascii into 1-26
                C[i] = ((char)(p + key) % 26) + 64;
            }
            else //islower(P[i])
            {
                p = P[i] - 96; //turn ascii into 1-26
                C[i] = ((char)(p + key) % 26) + 96;
            }
        }
        else //is not alphabet
        {
            C[i] = P[i];
        }
    }
    cout << "Cipher Text: " << C << endl;
}

void decryption()
{
    cout << "Key: ";
    cin >> key;

    cout << "Cipher Text: ";
    cin.ignore(1024, '\n');
    cin.getline(C, 300);

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
    cout << "Plain_Text: " << P << endl;
}

int main()
{
    while (1)
    {
        cout << "E(Encryption) or D(Decryption): ";
        char operation;
        cin >> operation;

        if (operation == 'E')
        {
            encryption();
            break;
        }
        else if (operation == 'D')
        {
            decryption();
            break;
        }
        else
        {
            cout << "No such instructions. Please enter again." << endl
                 << endl;
        }
    }

    return 0;
}