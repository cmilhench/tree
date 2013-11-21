//
//  main.c
//  kata
//
//  Created by Colin Milhench on 01/10/2013.
//  Copyright (c) 2013 Colin Milhench. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode* addWord(struct tnode*, char*);
void printTree(struct tnode*);

int main(int argc, const char * argv[])
{
  
  struct tnode* root = NULL;
  
  char* text = "now is the time for all good men to come to the aid of their party";
  char word[sizeof text];
  for (int offset;sscanf(text, "%s%n", word, &offset) > 0; text += offset) {
    root = addWord(root, word);
  }
  printTree(root);
  
  return 0;
}

struct tnode* addWord(struct tnode *node, char* word){
  int cmp;
  
  if (node == NULL) {
    node = malloc(sizeof(struct tnode));
    node->word = strdup(word);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
  } else if ((cmp = strcmp(node->word, word)) == 0) {
    node->count++;
  }
  else if (cmp < 0) {
    node->right = addWord(node->right, word);
  }
  else if (cmp > 0) {
    node->left = addWord(node->left, word);
  }
  return node;
}

void printTree(struct tnode *node) {
  if (node != NULL) {
    printTree(node->left);
    printf("%s (%d)\n", node->word, node->count);
    printTree(node->right);
  }
}
