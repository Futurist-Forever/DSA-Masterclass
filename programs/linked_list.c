/* Write a program to create a single linked list of n nodes and perform the following menu based operations on it using function:
i. Insert a node at specific position 
ii. Insert after a given data
iii.Deletion of an element from specific position
iv.Delete of a given data  
v. Count nodes
vi. Traverse the linked list */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create(struct node *start){
    struct node *new_node;
    int x;
    printf("\nEnter -1 to exit: ");
    printf("\nEnter the data: ");
    scanf("%d", &x);

    while(x!=-1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = x;

        if(start == NULL){
            start = new_node;
            new_node->next = NULL;
        }
        else{
            new_node->next = start;
            start = new_node;
        }
        printf("\nEnter the data OR -1 to exit: ");
        scanf("%d", &x);
    }
    return start;
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int count_node(struct node *start){
    struct node *ptr;
    int count = 0;
    ptr = start;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

struct node *insert_at_pos(struct node *start, int x, int pos){
    struct node *new_node;
    struct node *ptr;
    int i;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    ptr = start;
    if(pos == 1 || start == NULL){
        new_node->next = start;
        start = new_node;
    }
    else{
        int count = count_node(start);
        if(pos>count+1 || pos<1){
            printf("\nInvalid position!");
        }

        else if(pos==count+1){
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            new_node->next = NULL;
            ptr->next = new_node;
        }
        else{
            for(i=1; i<pos-1; i++){
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
    return start;
}

struct node *delete_at_pos(struct node *start, int pos){
    struct node *ptr;
    struct node *temp;
    if(start==NULL){
        printf("\nUnderflow");
    }
    else{
        int count = count_node(start);
        if(pos>count || pos<1){
            printf("\nInvalid position");
        }
        else if(pos==1){
            temp = start;
            start = start->next;
            free(temp);
        }
        else{
            temp = start;
            for (int i = 1; i < pos - 1;i++){
                temp = temp->next;
            }
            ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
        }
    }
    return start;
}

struct node *insert_after_data(struct node *start, int given_data, int item){
    int pos = search_data(start, given_data);
    if(pos==-1){
        printf("\nElement not in the list");
    }
    else{
        start = insert_at_pos(start, item, pos+1);
    }
    return start;
}

int search_data(struct node *start, int given_data){
    struct node *ptr;
    int pos = 1;
    ptr = start;
    while(ptr->data!=given_data){
        pos++;
        if(ptr->next==NULL){
            return -1;
        }
        else{
            ptr = ptr->next;
        }
    }
    return pos;
}

struct node *delete_data(struct node *start, int given_data){
    int pos = search_data(start, given_data);
    if(pos==-1){
        printf("\nElement not in the list");
    }
    else{
        start = delete_at_pos(start, pos);
    }
    return start;
}

int main(){
    int choice, x, pos;
    while(1){
        printf("\n\n**MENU**");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Insert a node at specific position");
        printf("\n4. Insert after a given data");
        printf("\n5. Deletion of an element from specific position");
        printf("\n6. Delete of a given data");
        printf("\n7. Count nodes");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                start = create(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("\nEnter the data: ");
                scanf("%d", &x);
                printf("\nEnter the position: ");
                scanf("%d", &pos);
                start = insert_at_pos(start, x, pos);
                break;
            case 4:
                printf("\nEnter the  given data: ");
                scanf("%d", &x);
                printf("\nEnter data to insert: ");
                int data;
                scanf("%d", &data);
                start = insert_after_data(start, x, data);
                break;
            case 5:
                printf("\nEnter the position: ");
                scanf("%d", &pos);
                start = delete_at_pos(start, pos);
                break;
            case 6:
                printf("\nEnter the data: ");
                scanf("%d", &x);
                start = delete_data(start, x);
                break;
            case 7:
                int count = count_node(start);
                printf("\nNumber of nodes: %d", count);
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}
