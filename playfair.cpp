#include <iostream>
#include <cstring>

#define SIZE 30

void change_to_lowercase(char plain[], int ps)
{
    for (int i = 0; i < ps; i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int remove_all_spaces(char *plain, int ps)
{
    int count = 0;
    for (int i = 0; i < ps; i++)
    {
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    }
    plain[count] = '\0';
    return count;
}

void generate_key(char key[], int ks, char keyT[5][5])
{
    int i, j, k, flag = 0;
    int *dicty = new int[26];

    memset(dicty, 0, sizeof(int) * 26);

    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'j')
            dicty[key[i] - 97] = 2;
    }
    dicty['j' - 97] = 1;

    i = 0;
    j = 0;
    for (k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 97] == 2)
        {
            dicty[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    for (k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
    delete[] dicty;
}

void searching(char keyT[5][5], char a, char b, int arr[])
{
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a)
{
    if (a < 0)
        a += 5;
    return (a % 5);
}

void decrypt(char str[], char keyT[5][5], int ps)
{
    for (int i = 0; i < ps; i += 2)
    {
        int a[4];
        searching(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][mod5(a[1] - 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] - 1)];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[mod5(a[0] - 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] - 1)][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void decrypt_by_playfair_cipher(char str[], char key[])
{
    char ps, ks, keyT[5][5];

    // Key text
    ks = strlen(key);
    ks = remove_all_spaces(key, ks);
    change_to_lowercase(key, ks);

    // Ciphertext
    ps = strlen(str);
    change_to_lowercase(str, ps);
    ps = remove_all_spaces(str, ps);

    generate_key(key, ks, keyT);

    decrypt(str, keyT, ps);
}

int main()
{
    char str[SIZE], key[SIZE];

    strcpy(key, " amar");
    std::cout << "Key text: " << key << std::endl;

    strcpy(str, " jorethang");
    std::cout << "Encrypted text: " << str << std::endl;

    decrypt_by_playfair_cipher(str, key);

    std::cout << "Deciphered text: " << str << std::endl;

    return 0;
}
