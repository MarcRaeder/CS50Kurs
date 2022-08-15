#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text, int letters, int i);
int count_words(string text, int words, int i);
int count_sentences(string text, int sentences, int i);

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {   
        letters = count_letters(text, letters, i);
        words = count_words(text, words, i);
        sentences = count_sentences(text, sentences, i);
    }
    
    printf("%i letters\n", letters);
    printf("%i words\n", words);
    printf("%i sentences\n", sentences);

    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text, int letters, int i)
{   
    if (isalpha(text[i]))
    {
        letters++;
    
    }

    return letters;
}

int count_words(string text, int words, int i)
{   
    if (text[i] == ' ')
    {
        words++;
    }

    return words;
}

int count_sentences(string text, int sentences, int i)
{
    if (text[i] == '.' || text[i] == '?' || text[i] == '!')
    {
        sentences++;
    }

    return sentences;
}
