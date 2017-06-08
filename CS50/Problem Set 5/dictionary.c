/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* root;

void init_node(node* node)
{
    node->is_word = false;
    for (int i = 0; i < 27; i++) {
        node->children[i] = NULL;
    }
}

bool free_tree(node* root) {
    for (int i = 0; i < 27; i++) {
        if ( root->children[i] != NULL ) {
            free_tree(root->children[i]);
        }
    }
    free(root);
    return true;
}

int numwords = 0;

int convertchar(char c)
{
    if (c == '\'') {
        return 26;
    }
    if (!isalpha(c)) {
        return -1;
    }
    // Convert letter into number, where a and A are 0, b/B is 1, etc.
    return ((int) tolower(c)) - 97;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int code;
    node* current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        code = convertchar(word[i]);
        if (current->children[code] == NULL) {
            return false;
        }
        current = current->children[code];
    }
    return (current->is_word == true);
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Assign root node
    root = malloc(sizeof(node));
    init_node(root);
    
    // try to open dictionary file
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    
    node* current = root;
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // If you have reached the end of a word, indicate that a word has been added,
        // reset current node, and increment global word counter
        if (c == '\n' || c == EOF) {
            current->is_word = true;
            current = root;
            numwords += 1;
        }
        else {
            int place = convertchar(c);
            
            // If the current node has no child for this char, malloc a new one
            if (current->children[place] == NULL) {
                current->children[place] = malloc(sizeof(node));
                init_node(current->children[place]);
            }
            // traverse down
            current = current->children[place];
        }
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return numwords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return free_tree(root);
}