##### Added - 04/08 

The file c2lc3.md in this folder lays out step by step how to do stack build
up and tear down across function calls. 

The file `running.asm` in this folder shows the implementation of a small
recursive function in LC3, in great detail. 

```
int running_sum(int n){
    int fn;
    if (n==1)
    fn = 1;
    else
    fn = n + running_sum(n-1);
    return fn;
}

int main(void){
    int n = 4;
    running_sum(n);
}
```

In [Lec 19](../lec19)'s folder there are two LC3 files which print out a
linked list. 

```
typedef struct Node{
    char symbol;
    struct Node *next;
}node;

void print_list(node *cursor){
    if (cursor==NULL)
        /* List empty; do nothing */
        return;
    else{
        /* Print and recurse */
        printf("%c", cursor->symbol);
        print_list(cursor->next);
    }
}
```
You should compare the differences between the two files in terms of callee
build up and tear down. 
