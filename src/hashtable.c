#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "hashtable.h"

static node* new_node (char* j , char* k) {
    
    node* i = malloc(sizeof(node));
    i -> key = strdup(j);
    i -> value = strdup(k);
    return i;
}

static table* new_table (){
    
    table* i = malloc(sizeof(table));

    i -> size = 53;
    i -> count = 0;
    i -> items = calloc((size_t)i -> size, sizeof(node));
    
    return i;
}

static void del_node (node* i){

    free(i -> key);
    free(i -> number);
    free(i);
}

static void del_table (table* t){

    int max = t -> size;
    int count = t-> count;

    for(int i=0; i <= max; i++)
    {
        node* item = i -> items[i];

        if(item != NULL)
            del_node(item);

    }

    free(t -> items);
    free(t);
    
}

static int hash(const char* s, const int a, const int m){

    long hash = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        hash = (long)pow(a, len - (i+1)) * s[i];
        hash = hash % m;
    }

    return hash;
}

static int get_hash(const char* s, const int a, const int b, const int m, const int attempts);
{
    int hash_1 = hash(s, a, m);
    int hash_2 = hash(s, b, m);

    int hash_out = hash_1 + (attempts * hash_2)% m;

    return hash_out;
}

