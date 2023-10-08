#pragma once

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

static const char *nato_alphabet[26] = {
    "alpha", "bravo", "charlie", "delta",
    "echo", "foxtrot", "golf", "hotel",
    "india", "juliet", "kilo", "lima",
    "mike", "november", "oscar", "papa",
    "quebec", "romeo", "sierra", "tango",
    "uniform", "victor", "whiskey", "xray",
    "yankee", "zulu"
};

void to_nato(char *text[], int length)
{
    if (length <= 0)
    {
        return;
    }

    for (int i=0; i < length; ++i)
    {
        char *itr = text[i];
        while (*itr != '\0')
        {
            if (isalpha(*itr))
            {
                int index = tolower(*itr) - 'a';
                fputs(nato_alphabet[index], stdout);

                char next_char = *(itr + 1);
                if (!isspace(next_char) && next_char != '\0')
                {
                    putchar(' ');
                }
            }
            else 
            {
                putchar(*itr);    
            }

            itr++;
        }

        if (i < length-1)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}

void from_nato(char *text[], int length)
{
    // whitespace characters according to the C23 standard (ISO/IEC 9899:2023)
    const char *delimiters = " \f\n\r\t\v";
    char *word;
    
    if (length <= 0)
    {
        return;
    }

    for(int i=0; i < length; ++i)
    {
        while ((word = strsep(&text[i], delimiters)) != NULL) 
        {
            char first_char = *word;

            if (isalpha(first_char) && strcasecmp(word, nato_alphabet[tolower(first_char) - 'a']) == 0)
            {
                putchar(first_char);
            }
            else 
            {
                fputs(word, stdout);
            }
        }
    }

    putchar('\n');
}
