#include <stdio.h>

int array[100], n;
int main()

{

    int ch, num,m;

    n = 0;

    while(1)

    {

        printf("\n\n\n\t\t\t1.Insert \n");

        printf("\t\t\t2.Delete\n");

        printf("\t\t\t3.Display\n");

        printf("\t\t\t4.Quit \n\n");
        level:

        printf("\t\t\tEnter your choice : ");

        scanf("%d", &ch);

        switch(ch)

        {

        case 1:

            printf("Enter the element : ");

            scanf("%d", &num);


            insert(num, n);

            n = n + 1;

            goto level;

            break;

        case 2:

            printf("Enter deleted element: ");


            scanf("%d", &num);

            delete(num);
            printf("Successfully Deleted :%d",num);
            goto level;


            break;

        case 3:

            display();
            goto level;

            break;

        case 4:

            exit(0);
            goto level;

        default:

            printf("wrong input\n");
            goto level;

    }

}

}



display()

{

    int i;

    if (n == 0)

    {

        printf("Heap is empty \n");

        return;

    }

    for (i = 0; i < n; i++)

        printf("%d ", array[i]);

    printf("\n");

}



insert(int num, int location)

{

    int parentnode;

    while (location > 0)

    {

        parentnode =(location - 1)/2;

        if (num <= array[parentnode])

        {

            array[location] = num;

            return;

        }

        array[location] = array[parentnode];

        location = parentnode;

    }

    array[0] = num;

}



delete(int num)

{

    int left, right, i, temp, parentnode;



    for (i = 0; i < num; i++) {

        if (num == array[i])

            break;

    }

    if (num != array[i])

    {

        printf("%d not found in heap list\n", num);

        return;

    }

    array[i] = array[n - 1];

    n = n - 1;

    parentnode =(i - 1) / 2;

    if (array[i] > array[parentnode])

    {

        insert(array[i], i);

        return;

    }

    left = 2 * i + 1;

    right = 2 * i + 2;

    while (right < n)

    {

        if (array[i] >= array[left] && array[i] >= array[right])

            return;

        if (array[right] <= array[left])

        {

            temp = array[i];

            array[i] = array[left];

            array[left] = temp;

            i = left;

        }

        else

        {

            temp = array[i];

            array[i] = array[right];

            array[right] = temp;

            i = right;

        }

        left = 2 * i + 1;

        right = 2 * i + 2;

    }

    if (left == n - 1 && array[i])    {

        temp = array[i];

        array[i] = array[left];

        array[left] = temp;

    }

}
