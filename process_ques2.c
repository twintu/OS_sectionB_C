#include<stdio.h>

int main() 
{
    int pid1,pid2,pid3,pid4; 

    printf("Parent id is %d and root id is%d\n",getpid(),getppid()); 

    pid1= fork();                                                     /* child1 created*/

    if(pid1== 0) 
    {

        printf("child1 is %d and its parent id is %d\n",getpid(),getppid());
    } 

    else 
    {

        pid2= fork();                                                  /* child2 created*/

        if (pid2==0) 
        {


            printf("child2 id is %d and its parent id is %d\n",getpid(),getppid());  
        } 

        pid3=fork();                                                   /*child3 created*/

        if(pid2==0&&pid3==0) 
        { 

            printf("child 3 id is %d and its parent id is %d\n",getpid(),getppid());
        }       

        else 
        {

            pid4=fork();                                                /*child4 created*/

            if(pid2==0&&pid4==0) 
            {

                printf("child 4 id is %d and its parent id is %d\n",getpid(),getppid());
            }


        }
    }
}
