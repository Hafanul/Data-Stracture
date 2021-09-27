#include<iostream>
#include<string>
#include<cstdlib>

using namespace std ;

int x ;

class ryu
{
private :
    typedef struct node
{
    int data;
    char word;
    node* next ;

}* queptr;

    queptr front,rear ,curr ,temp,another,top,f1,r1 ;


public :
    ryu();
    void enqeue(int value);
    void deqeue();
    int check_size();
    int check_list();
    void destroy_list();
    void reverse_list();
    void delelte_negative();
    void enqeue2(int value);
    void copy_list();
    void compress();
    void stack_to_qeue();
    void push(int x );
    int pop();
    void display(queptr print);
    void display_main();


};

int main ()
{
    ryu obj,obj2 ;

    int a ;
    cout << "1=enqeue\t2=deqeue\t3=size\t4=destroy\t5=stack to qeue\t6=delete negative number\t7=copy qeue\t8=compress\t0=exit : ";
    cin >> x ;
    while(x!=0)
    {

        switch(x)
        {
        case 1 :
            cout << "input a value : ";
            cin >> a;
            obj.enqeue(a);
            break ;
        case 2 :
            obj.deqeue();
            break ;
        case 3 :
            obj.check_size();
            break ;
        case 4 :
            obj.destroy_list();
            break ;
        case 5 :
            obj.stack_to_qeue();
            break ;

        case 6 :
            obj.delelte_negative();
            break ;

        case 7 :
            if(obj.check_list()==1)
                obj.copy_list();
            break;

        case 8 :
            obj.compress();
            break ;



            }

        obj.display_main();

        cout << endl << "1=enqeue\t2=deqeue\t3=size\t4=destroy\t5=stack to qeue\t6=delete negative number\t7=copy qeue\t8=compress\t0=exit : ";
        cin >> x ;
    }

}

ryu :: ryu ()
{
    front = NULL ;
    rear = NULL ;
    r1=NULL;
    f1=NULL;
    top = NULL;
    curr = NULL ;
    temp = NULL ;
}

void ryu ::enqeue( int value)
{
    queptr n = new node ;
    n->next = NULL ;


    n->data = value;

    if(rear==NULL )
    {

       front = n ;
       rear = n ;
    }
    else
    {
        rear->next = n ;
        rear = n ;

    }
    top =rear ;
}

void ryu::deqeue()
{
    temp = front ;
    front = front ->next ;
    temp->next = NULL ;
    delete temp ;

    if(check_list()==0)
        ryu();
}

int ryu::check_size()
{
    int counter = 0 ;

    curr = front ;
     while(curr!=NULL)
    {
        curr = curr->next ;
        counter++;
    }
    return counter ;
}

int ryu::check_list()
{

    if(front == NULL )
    {
        return 0 ;
    }


    else
    {
        return 1 ;
    }


}

void ryu::destroy_list()
{
    int size,i=0 ;
    size = check_size() ;

    while(i < size)
    {
        deqeue();
        i++;
    }

    ryu();

}

void ryu::reverse_list()
{
    queptr pre,nxt ;

    pre = front ;
    curr = front->next ;

    pre->next = NULL;

    while(curr!=NULL)
    {
        nxt = curr->next ;

        curr->next = pre ;

        pre = curr ;
        curr = nxt;
    }

    temp = front ;
    front = rear ;
    rear = temp;
}

void ryu::delelte_negative()
{

    int x = check_size();

    curr=front;

    while(x!=0)
    {
        if( curr->data > 0)
        {
            enqeue2(curr->data);
        }
        curr=curr->next;
        x--;
    }
    destroy_list();
    front = f1;
    rear = r1;
}

void ryu::copy_list()
{
    curr=front;

    while(curr!=NULL)
    {
        enqeue2(curr->data);
        curr=curr->next;
    }

    cout << "copied ";
    display(f1);

}

void ryu::enqeue2(int value)
{
    queptr q = new node ;
    q->next = NULL ;


    q->data = value;

    if(r1==NULL )
    {

       f1 = q ;
       r1 = q ;
    }
    else
    {
        r1->next = q ;
        r1 = q ;

    }
}

void ryu::compress()
{

    char name[100];
    cin.getline(name,100);
    cout <<name;
}

void ryu::stack_to_qeue()
{
    destroy_list();
    int i,n,a ;
    i=0;
    destroy_list();
    cout << "how many number : ";
    cin>>n;
    cout << "input stack : ";
    while(i<n)
    {
        cin>>a;
        push(a);
        i++;
    }

    cout << "stack : ";
    curr=top;
    while(curr!=NULL)
    {
        temp = curr;
        cout<<curr->data << " \t" ;
        curr= curr->next ;
    }
    cout << endl <<endl ;
    rear = temp ;
    front = top;


}



void ryu::display(queptr print)
{
    cout << "Qeue : ";
    while(print!=NULL)
    {
        cout<<print->data << " \t" ;
        print= print->next ;
    }
    cout << endl <<endl ;

}

void ryu::display_main()
{
    display(front);
}

void ryu::push(int x)
{

    queptr n = new node ;

    n -> data = x ;

    if (top == NULL)
    {
        n -> next = NULL ;
        top = n ;
    }

    else
    {
        n->next = top ;
        top = n ;

    }
}



