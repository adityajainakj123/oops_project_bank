#pragma once
#include <string.h>

string encrypt(string text, int s = 5)
{

    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    return result;
}

string decrypt(string text, int s = 5)
{

    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] - s - 65) % 26 + 65);

        else
            result += char(int(text[i] - s - 97) % 26 + 97);
    }

    return result;
}