#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{    
    int key = 0;
    // Check if 2 commandline arguments are given, otherwise abort program
    if (argc == 2)
    {
        // Loop through argv[1] to check if only alpabethic inputs are given
        int n = strlen(argv[1]);
        for (int i = 0; i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                key = shift(argv[1][i]);
                printf("%i\n", key);
                printf("Success\n");
            }
            else 
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    };

    // Ask user for secret message
    string message = get_string("plaintext: ");

    // Determine length of secret message and key word
    int length = strlen(message);
    int n = strlen(argv[1]);
    
    // Print "ciphertext: " for layout reasons
    printf("ciphertext: ");
    
    // Loop through message to print every char misplaced by key on same line
    int i, j;
    for (i = 0, j = 0; i < length; i++, j++) 
    {
        j = j % n;
        // Retain uppercase
        if (message[i] >= 65 && message[i] <= 90)
        {
            int newlet = message[i] + shift(argv[1][j]);
            if (newlet > 90)
            {
                printf("%c", newlet - 26);
            }
            else
            {
                printf("%c", newlet);
            }
        }
        // Retain lowercase
        else if (message[i] >= 97 && message[i] <= 122)
        {
            int newlet = message[i] + shift(argv[1][j]);
            if (newlet > 122)
            {
                printf("%c", newlet - 26);
            }
            else
            {
                printf("%c", newlet);
            }
        }
        // Retain punctuation
        else
        {
            printf("%c", message[i]);  
            j --;
        }
    }
    // Go to next line for esthetics
    printf("\n");
    
}
// Shift function that determines the shift value based on the keyword
int shift(char c)
{
    // |_O\/e u sch4tj3
    int value;
    // For uppercase
    if (isupper(c))
    {
        value = c - 65;
    }
    // For lowercase
    if (islower(c))
    {
        value = c - 97;
    }
    return value;
};
