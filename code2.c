#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to count the frequency of words in a paragraph
void countWordFrequencies(char *paragraph) {
    WordCount words[MAX_WORDS];
    int wordCount = 0;

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \t\n\r.,;!?()[]{}\"'");
    while (token != NULL) {
        // Convert word to lowercase
        toLowerCase(token);

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the list
        if (!found) {
            if (wordCount < MAX_WORDS) {
                strcpy(words[wordCount].word, token);
                words[wordCount].count = 1;
                wordCount++;
            } else {
                printf("Word limit exceeded\n");
                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " \t\n\r.,;!?()[]{}\"'");
    }

    // Print the word frequencies
    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char paragraph[10000];

    printf("Enter a paragraph (end with an empty line):\n");

    // Read the entire paragraph
    int i = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n' && i > 0 && paragraph[i - 1] == '\n') {
            break;
        }
        paragraph[i++] = ch;
    }
    paragraph[i] = '\0';

    // Count and print word frequencies
    countWordFrequencies(paragraph);

    return 0;
}
