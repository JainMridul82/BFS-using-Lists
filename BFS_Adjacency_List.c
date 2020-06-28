#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*root=NULL;
struct Queue{
    int data;
    struct Queue *next;
}*front=NULL,*rear=NULL;
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
int isEmptyQ(struct Queue **head,struct Queue **tail){
    return (*head==NULL && *tail==NULL)?1:0;
}
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
void Insert_AL(struct Node **AL,int index,int data){
    Insert(&AL[index],data);
}
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}
void Display_AL(struct Node **AL){
    int i;
    for(i=1;i<6;i+=1){
        Display(AL[i]);
        printf("\n");
    }
}
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
    struct Node **AL=(struct Node **)calloc(8,sizeof(struct Node));
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
    int visited[]={0,0,0,0,0,0,0,0};
    BFS(AL,visited,&front,&rear,7);
    return 0;
}
