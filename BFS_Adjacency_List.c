#include<stdio.h>
#include<stdlib.h>

// The Node structure is used in the implementation of Linked Lists as part of the Adjacency List.
struct Node{
    int data;
    struct Node *next;
}*root=NULL;

// The Queue structure is used in the BFS algorithm.
// The Queue is implemented using Linked Lists.
struct Queue{
    int data;
    struct Queue *next;
}*front=NULL,*rear=NULL;

// To insert integer value(data) into the Queue.
void Enqueue(struct Queue **head,struct Queue **tail,int data){
    struct Queue *node=(struct Queue *)malloc(sizeof(struct Queue));
    node->data=data;
    node->next=NULL;
    if(*head==NULL && *tail==NULL)
        *head=*tail=node;
    else{
        (*tail)->next=node;
        *tail=node;
    }
}

// To check if the Queue is empty or not?
int isEmptyQ(struct Queue **head,struct Queue **tail){
    return (*head==NULL && *tail==NULL)?1:0;
}

// To remove an integer data element from the exisiting Queue.
int Dequeue(struct Queue **head,struct Queue **tail){
    int res;
    struct Queue *p=*head;
    *head=p->next;
    if(*head==NULL)
        *tail=*head;
    res=p->data;
    free(p);
    return res;
}

// To insert a node in the Linked List. Here Linked List means one of the many lists in the Adjacency List.
void Insert(struct Node **head,int data){
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    if(*head==NULL)
        *head=node;
    else{
        struct Node *p=*head;
        while(p->next!=NULL)
            p=p->next;
        p->next=node;
    }
}

// To insert a particular node in a particular position in the Adjacency List
void Insert_AL(struct Node **AL,int index,int data){
    Insert(&AL[index],data);
}

// To display the elements(data integer) in a linked list. Here linked list means one of the many lists in the Adjacency List.
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

// To display the entire Adjacency List
void Display_AL(struct Node **AL){
    int i;
    for(i=1;i<8;i+=1){ // We are assuming there are only 1 to 7 nodes. 1 & 7 are included.
        Display(AL[i]);
        printf("\n");
    }
}

// The BFS algorithm for Adjacency List.
void BFS(struct Node **AL,int visited[],struct Queue **head,struct Queue **tail,int u){
    int v;
    printf("%d\t",u);
    visited[u]=1;
    Enqueue(head,tail,u);
    while(!isEmptyQ(head,tail)){
        v=Dequeue(head,tail);
        struct Node *p=AL[v];
        while(p!=NULL){
            if(visited[p->data]==0){
                printf("%d\t",p->data);
                visited[p->data]=1;
                Enqueue(head,tail,p->data);
            }
            p=p->next;
        }
    }
}

int main(){
    struct Node **AL=(struct Node **)calloc(8,sizeof(struct Node)); // An adjacency List is essentially an array of pointer variables.
    //Insert_AL(name of the Adjacency List: AL,from node 1,to node 2);
    Insert_AL(AL,1,2);
    Insert_AL(AL,1,3);
    Insert_AL(AL,1,4);
    Insert_AL(AL,2,1);
    Insert_AL(AL,2,3);
    Insert_AL(AL,3,1);
    Insert_AL(AL,3,2);
    Insert_AL(AL,3,4);
    Insert_AL(AL,3,5);
    Insert_AL(AL,4,1);
    Insert_AL(AL,4,3);
    Insert_AL(AL,4,5);
    Insert_AL(AL,5,3);
    Insert_AL(AL,5,4);
    Insert_AL(AL,5,6);
    Insert_AL(AL,5,7);
    Insert_AL(AL,6,5);
    Insert_AL(AL,7,5);
    int visited[]={0,0,0,0,0,0,0,0}; // Initially none of the nodes have been visited.
    BFS(AL,visited,&front,&rear,7); // Run the algorithm.
    return 0;
}
