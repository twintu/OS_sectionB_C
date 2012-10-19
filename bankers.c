#include<stdio.h>

int main()
{
    int clm[7][5],req[7][5],alloc[7][5],rsrc[5],avail[5],comp[7];
    int first,p,r,i,j,prc,count,t;
    count=0;
    for(i=1;i<=7;i++)
        comp[i]=0;

    printf("BANKERS ALGORITHM\n");
    printf("Enter the no of processes:");
    scanf("%d",&p);                                             //read the number of process

    printf("\nEnter the no of resources:");
    scanf("%d",&r);                                             //read the number of resources

    printf("\nEnter the claim for each process");
    
    for(i=1;i<=p;i++)
    {
        printf("\nFor process %d: ",i);
        for(j=1;j<=r;j++)
        {
            scanf("%d",&clm[i][j]);
        }
    }

    printf("\nEnter the allocation for each process");          //read the allocation of each process
    for(i=1;i<=p;i++)
    {
        printf("\nFor process ",i);
        for(j=1;j<=r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("\n\nEnter total no of each resource:");
    for(j=1;j<=r;j++)
        scanf("%d",&rsrc[j]);
    
    for(j=1;j<=r;j++)                                       //calculate the available resources
    {
        int total=0;
        avail[j]=0;
        for(i=1;i<=p;i++)
        {
            total+=alloc[i][j];
        }
        avail[j]=rsrc[j]-total;
    }
    
    do
    {
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=r;j++)
            {
                req[i][j]=clm[i][j]-alloc[i][j];
            }
        }
        
        printf("\n\nAvailable resources are : ");                       //print the allocated resources and available resources
        for(j=1;j<=r;j++)
        { 
            printf(" ",avail[j]); 
        }
        
        printf("\nClaim matrix:\tAllocation matrix:\n");
        
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=r;j++)
            {
                printf("%d\t",clm[i][j]);
            }
            printf("\t\t");
            for(j=1;j<=r;j++)
            {
                printf("%d\t",alloc[i][j]);
            }
            printf("\n");
        }
        prc=0;
        for(i=1;i<=p;i++)
        {
            if(comp[i]==0)
            {
                prc=i;
                for(j=1;j<=r;j++)
                {
                    if(avail[j])
                    {
                        prc=0;
                        break;
                    }
                }
            }
            if(prc!=0)
                break;
        }
        if(prc!=0)
        {
            printf("\nProcess ",prc,"runs to completion!");
            count++;
            for(j=1;j<=r;j++)
            {
                avail[j]+=alloc[prc][j];
                alloc[prc][j]=0;
                clm[prc][j]=0;
                comp[prc]=1;
            }
        }
    }
    while(count!=p&&prc!=0);                                        //check whether the system is in safe state or unsafe state
    if(count==p)
        printf("\nThe system is in a safe state!!");
    else
        printf("\nThe system is in an unsafe state!!");
return ;
}


