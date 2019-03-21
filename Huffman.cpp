//2017030191_LeeHyunji
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER 30005

int sum = 0;

typedef struct heap_node{
    char *ch;
    int freq;
    struct heap_node *left, *right;
}heap_node;

typedef struct{
    int heap_size;
    heap_node *heap[NUMBER];
}MinHeap;

void insert_heap(heap_node *element, MinHeap *h){
    h->heap_size++;
    h->heap[h->heap_size] = element;
    
    int cur = h->heap_size;
    
    while(h->heap[cur/2]->freq > element->freq){
        h->heap[cur] = h->heap[cur/2];
        cur = cur/2;
    }
    
    h->heap[cur] = element;
}

heap_node *delete_min_heap(MinHeap *h){
    int child,cur;
    heap_node * min_element, *last_element;
    
    min_element = h->heap[1];
    last_element = h->heap[h->heap_size--];
    
    for(cur = 1 ; 2*cur <= h->heap_size ; cur = child){
        child = cur*2;
        if(child != h->heap_size && h->heap[child+1]->freq < h->heap[child]->freq) child++;

        if(last_element->freq > h->heap[child]->freq){
            h->heap[cur] = h->heap[child];
        }
        else break;
    }
    h->heap[cur] = last_element;
    
    return min_element;
}

void count(heap_node *tmp, int num){
    num++;
    
    if(tmp->left==NULL && tmp->right==NULL){
        sum += (tmp->freq)*num;
        return;
    }
    
    count(tmp->left,num);
    count(tmp->right,num);
}

int main(){
    int s, bit=1, cnt =-1;
    MinHeap h;
    
    h.heap[0] = (heap_node*)malloc(sizeof(heap_node));
    h.heap[0]->freq = 0;
    h.heap_size = 0;
    
    int n; scanf("%d",&n);
    char *ch = (char*)malloc(sizeof(char)*n);
    int freq;
    
    for(int i = 0 ; i < n ; i++){
        scanf("%s %d", &ch[i], &freq);
        heap_node * tmp = (heap_node*)malloc(sizeof(heap_node));
        
        tmp->ch = &ch[i];
        tmp->freq = freq;
        tmp->left = tmp->right = NULL;
        
        insert_heap(tmp,&h);
    }
    scanf("%d", &s);
    for(int i = 0 ; i < n-1 ; i++){
        heap_node *left = delete_min_heap(&h);
        heap_node *right = delete_min_heap(&h);
        heap_node *tmp = (heap_node*)malloc(sizeof(heap_node));
        
        tmp->ch = 0;
        tmp->left = left;
        tmp->right = right;
        tmp->freq = left->freq + right->freq;
        
        insert_heap(tmp,&h);
    }
    
    heap_node *tree = delete_min_heap(&h);
    
    count(tree,cnt);
    
    int i=1;
    while(true){
        if(n < 2*i && n >= i){
            break;
        }
        i *= 2;
        bit++;
    }
    printf("%d\n", bit*s);
    printf("%d\n", sum);
    
    return 0;
}


