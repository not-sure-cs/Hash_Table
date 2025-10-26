typedef struct {
    char* key;
    char* value;
} node;

typedef struct {
    int size;
    int count;
    node** items;
} table;