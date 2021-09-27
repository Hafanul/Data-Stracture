#include<iostream>
#include<cstdlib>

using namespace std ;

int counter ;

class ryu
{
private :
    typedef struct node
{
    int data;
    node* prev;

}* stackptr;

    stackptr top ,curr ,temp ;


public :
    ryu ();
    void push();
    void pop();
    void top_stack();
    void destroy() ;
    void display();



};

int main()
{
    ryu obj;
    obj.push();
    obj.push();
    obj.push();
    obj.push();
    obj.display();
    obj.pop();
    obj.top_stack();
    obj.display();
    obj.destroy();
    obj.display();
}

ryu::ryu()
{
    top = NULL ;
    temp = NULL ;
    curr = NULL ;
    counter = 0 ;
}

void ryu::push()
{

    int x ;
    stackptr n = new node ;

    cin >> x ;
    n -> data = x ;

    if (top == NULL)
    {
        n -> prev = NULL ;
        top = n ;
    }

    else
    {
        n->prev = top ;
        top = n ;

    }
    counter ++ ;
}

void ryu::pop()
{
    temp = top ;
    top = top->prev ;
    temp->prev = NULL ;

    cout << endl <<endl << "pop" <<endl <<"----------------------"<<endl ;
    cout << temp ->data << " is deleted  " <<endl ;
    cout << "----------------------"<<endl<< endl  ;
    delete temp ;

    counter-- ;
}

void ryu::top_stack()
{

    cout << endl <<endl << "top" <<endl <<"----------------------"<<endl ;
    cout << "data : " << top->data <<endl ;
    cout << "count : " << counter  <<endl ;
    cout << "----------------------"<<endl<< endl  ;
}

void ryu::destroy()
{
    while(top!=NULL)
    {
        temp = top ;
        top = top->prev ;
        temp->prev = NULL ;
        delete temp ;
    }
}

void ryu::display()
{
    curr = top ;

    if (top==NULL)
    {
        cout << "list is empty" <<endl ;
    }

    else
        cout << endl << "stack list :\t";

    while( curr!= NULL )
    {
        cout << curr->data << "\t" ;
        curr = curr->prev ;
    }
    cout << endl ;
}


