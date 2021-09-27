#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail, *curr;

int ins_1st()
{
    if(head==NULL){
        head=(node*)malloc(sizeof(struct node));

        cout<<"\nInput data: ";
        cin>>head->data;
        head->next=NULL;
        tail=head;
    }

    else{
        curr=head;
        head=(node*)malloc(sizeof(struct node));

        cout<<"\nInput data: ";
        cin>>head->data;
        head->next=curr;
    }
}

int ins_last()
{

        curr=(node*)malloc(sizeof(struct node));

        cout<<"\nInput data: ";
        cin>>curr->data;
        curr->next= NULL;
        if(head==NULL){
            head=curr;
            tail=curr;
        }
        else{
            tail->next=curr;
            tail=curr;
        }

}


void ins_any_pos(int n)
{
    int i;
    struct node *temp, *ne;
    ne = (node*)malloc(sizeof(struct node));

    cout<<"\nInput data: ";
    cin>>ne->data;
    ne->next= NULL;

    curr = head;
    for(i=1;i<n;i++){
        temp = curr;
        curr = curr->next;
    }
    ne->next=curr;
    temp->next=ne;
}

void del_1st()
{
    curr = head;
    head = head->next;
    free(curr);
}


void del_any_pos(int n)
{
    int i;
    struct node *temp;
    curr = head;
    for(i=1;i<n;i++){
        temp = curr;
        curr = curr->next;
    }
    temp->next = curr->next;
    free(curr);
}


void del_last()
{
    struct node *temp;
    curr = head;
    while(curr->next!=NULL){
        temp = curr;
        curr = curr->next;
    }
    free(curr);
    temp->next = NULL;
    tail = temp;
}


void search_ele()
{
    int pos=0,value,i=0;
    curr = head;

    cout<<"\nValue to search: ";
    cin>>value;
    while(curr!=NULL){
        pos++;
        if(curr->data==value){
            cout<<endl<<value<<" is found in position "<<pos<<endl;
            i++;
        }
        curr = curr->next;
    }
    if(i==0)
            cout<<"\nValue does not exists in list."<<endl;

}

struct node* rev(struct node* head)
{
    struct node *pre , *nxt;
    curr = head;
    tail = head;
    pre = NULL;

    while(curr!=NULL){
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }
    head = pre;
    return head;
}
void empty_ch()
{
    if(head==NULL)
        cout<<"\nList is empty.\n";
    else
        cout<<"\nList is not empty\n";
}

void size_list()
{
    int s=0;
    curr=head;
    while(curr!=NULL){
        curr = curr->next;
        s++;
    }
    cout<<"\nSize of the list is "<<s<<".\n";
}

void display()
{
    curr = head;
    cout<<endl;
    while(curr!=NULL){
        cout<<curr->data<<"-->";
        curr=curr->next;
    }
}

main()
{
    int i,n;
    head = NULL;
    while(i!=12){
        cout<<"\n\n1. Insert node at beginning\n2. Insert node at any position\n";
        cout<<"3. Insert node at last\n4. Delete from 1st\n5. Delete from any position\n6. Delete from last\n";
        cout<<"7. Search element\n8. Reverse\n9. Empty check\n";
        cout<<"10. Size of the list\n11. Display\n12. Exit\n"<<endl;
        cin>>i;
        if(i==1)
            ins_1st();
        else if(i==2){
            cout<<"\nPosition to insert: ";
            cin>>n;
            ins_any_pos(n);
        }

        else if(i==3)
            ins_last();
        else if(i==4)
            del_1st();
        else if(i==5){
            cout<<"\nPosition to delete: ";
            cin>>n;
            del_any_pos(n);
        }
        else if(i==6)
            del_last();
         else if(i==7)
            search_ele();
        else if(i==8)
            head=rev(head);
        else if(i==9)
            empty_ch();
        else if(i==10)
            size_list();
        else if(i==11)
            display();
        else
            break;
    }
}
