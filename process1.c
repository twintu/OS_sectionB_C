#include<stdio.h>


int main()
{
    int pid1,pid2,pid3; 
    
    printf("Parent id is %d and root id is%d\n",getpid(),getppid()); 
    pid1=fork();                                                       /*Child1 Created*/
    
    if(pid1==0)
    {
        printf("Child1 id is %d and its parent id is %d\n",getpid(),getppid());

        pid2=fork();                                                  /*Child2 Created*/
    }
    
    if(pid1==0&&pid2==0)
    { 
        printf("Child2 id is %d and its parent id is %d\n",getpid(),getppid()); 
    }

return;
}
