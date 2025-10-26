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