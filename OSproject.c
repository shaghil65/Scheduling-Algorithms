#include<stdio.h>
#include <string.h>
#define max 30
void FCFS()
{
char p[10][10], t[10];
int at[20], bt[20], wt[20], tat[20], i, j, n, temp;
float wtavg, tatavg;

printf("Enter the number of processes:");
scanf("%d", &n);

   for(i=0;i<n;i++)
   {
   printf("Enter The Burst Time Of Process %d \n",i+1);
   scanf("%d",&bt[i]);
    printf("Enter The Arrival Time Of Process %d \n",i+1);
   scanf("%d",&at[i]);
   }
for (i = 0; i < n; i++)               
{
    for (j = 0; j < n; j++)            
    {                             
        if (at[i] < at[j])                                      
        {                        
            temp = at[i];              
            at[i] = at[j];      
            at[j] = temp;       
            temp = bt[i];        
            bt[i] = bt[j];       
            bt[j] = temp;        
            strcpy(t, p[i]);     
            strcpy(p[i], p[j]);  
            strcpy(p[j], t);    
        } 
    }
}
wt[0] = wtavg = 0;                    
tat[0] = tatavg = bt[0];               

for (i = 1; i < n; i++)               
{
    wt[i] = wt[i - 1] + bt[i - 1];  
    tat[i] = tat[i - 1] + bt[i];   
    wtavg = wtavg + wt[i];         
    tatavg = tatavg + tat[i];     
}

printf("\n");
printf("=============================================================================================================================\n");
printf("\n");
printf("=================================== *** FIRST COME FIRST SERVE SCHEDULAR ALGORITHM TABLE *** ===============================\n");
printf("\n");
printf("=============================================================================================================================\n");
printf("\t PROCESS \t ARRIVAL TIME \tBURST TIME \t WAITING TIME \t TURNARROUND TIME \n");
for (i = 0; i < n; i++)
{
    printf("\n\t %d \t\t %d \t\t %d \t\t %d \t\t %d", i+1, at[i], bt[i], wt[i], tat[i]);
}

printf("\n");
printf("=============================================================================================================================\n");
printf("=============================================================================================================================\n");
printf("\n\nAverage Waiting Time is -- %f", wtavg/n);
printf("\nAverage Turnaround Time is -- %f\n", tatavg/n);
}

void SJF()
{
int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
float wtavg, tatavg;

printf("\nEnter the number of processes  ");
scanf("%d", &n);

for(i=0;i<n;i++) 
{
p[i]=i;
printf("Enter Burst Time for Process %d ", i);
scanf("%d", &bt[i]); 
}

for(i=0;i<n;i++)               
{
    for(k=i+1;k<n;k++)         
    {
        if(bt[i]>bt[k])    
        {
            temp=bt[i];    
            bt[i]=bt[k];     
            bt[k]=temp;       

            temp=p[i];      
            p[i]=p[k];     
            p[k]=temp;       
        }
    }
}

wt[0] = wtavg = 0;              
tat[0] = tatavg = bt[0];        

for(i=1;i<n;i++)              
{
    wt[i] = wt[i-1] +bt[i-1];   
    tat[i] = tat[i-1] +bt[i];   
    wtavg = wtavg + wt[i];      
    tatavg = tatavg + tat[i];   
}


printf("\n");
printf("==================================================================================================================\n");
printf("\n");
printf("=================================== *** SHORTEST JOB SCHEDULAR ALGORITHM TABLE *** ===============================\n");
printf("\n");
printf("==================================================================================================================\n");
printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i],bt[i],wt[i],tat[i]);

printf("\n");
printf("==================================================================================================================\n");
printf("==================================================================================================================\n");
printf("\nAverage Waiting Time -- %f", wtavg/n);
printf("\nAverage Turnaround Time -- %f", tatavg/n);
}

void RR()
{
 
  int  n; 
  int i;
  int j; 
  int temp; 
  int qt;
  int bt[max];
  int wt[max]; 
  int pr[max];
  int tat[max]; 
  int remaining_bt[max]; 
  float awt=0; 
  float atat=0; 
  int sq=0;
  int count;

   printf("Enter The Number Of Processes \n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
   printf("Enter The Burst Time Of Process %d \n",i+1);
   scanf("%d",&bt[i]);
   remaining_bt[i]=bt[i]; 
   }

   printf("Enter Time Quantam \n");
    scanf("%d",&qt);

    while (1)
    {
        
   for(i=0,count=0;i<n;i++) 
     {
        temp = qt;          
        if(remaining_bt[i]==0)   
        {
            count++;  
            continue; 
        }
        if(remaining_bt[i]>qt) 
        {
            remaining_bt[i]=remaining_bt[i]-qt; 
                                               
        }
        else
           if(remaining_bt>=0) 
           {
               temp=remaining_bt[i]; 

               remaining_bt[i]=0; 
           }
         sq = sq+temp; 
         tat[i] =sq; 
     }
     
     if(n==count) 
     {
        break;
     }
    }
printf("\n");
printf("=================================================================================================================\n");
printf("\n");
printf("=================================== *** ROUND ROBIN SCHEDULAR ALGORITHM TABLE *** ===============================\n");
printf("\n");
printf("=================================================================================================================\n");
    printf("\nProcess\t\tBurst Time\tTurn Around Time\t Waiting Time");
    for(i=0,count=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];  
        awt=awt+wt[i]; 
        atat=atat+tat[i]; 
        printf("\n%d\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],tat[i],wt[i]);
    }

    awt=awt/n; 
    atat=atat/n; 
    printf("\n");
   printf("=================================================================================================================\n");
   printf("=================================================================================================================\n");
    printf("Average Waiting Time %f \n ",awt);
    printf("Average Turn Around Time %f \n",tat);
    
    
}
void PSNP()
{
  int  n; 
  int i; 
  int j; 
  int temp; 
  int bt[max]; 
  int wt[max]; 
  int pr[max]; 
  int tat[max]; 
  int postion; 
  float awt=0; 
  float atat=0; 


   printf("Enter The Number Of Processes \n");
   scanf("%d",&n);


   for(i=0;i<n;i++)
   {
   printf("Enter The Burst Time Of Process %d \n",i+1);
   scanf("%d",&bt[i]);

   printf("Enter The Priority Of Process %d \n",i+1);
   scanf("%d",&pr[i]);
   }

    
   
   for(i=0;i<n;i++)
   {
       postion=i; 
       for(j=i+1;j<n;j++) 
           {
                if(pr[j]>pr[postion])
                {
                    postion=j;
                }

           }
        temp=pr[i]; 
        pr[i]=pr[postion];
        pr[postion]=temp;
        

        temp=bt[i];
        bt[i]=bt[postion];
        bt[postion]=temp;

   }
   wt[0]=0; 


printf("\n");
printf("==============================================================================================================\n");
printf("\n");
printf("=================================== *** PRIORITY SCHEDULAR ALGORITHM TABLE *** ===============================\n");
printf("\n");
printf("==============================================================================================================\n");
    printf("\nProcess\t\tBurst Time\t\tPriority\tTurn Around Time\t Waiting Time"); // Table Kay Headers hongy yeh
    for(i=0,i<n;i<n;i++)
    {
        wt[i]=0;  
        tat[i]=0; 

        for(j=i+1;j<n;j++)
        {
             wt[i]= wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i]; 
        awt=awt+wt[i];      
        atat=atat+tat[i];  
       
        printf("\n%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d",i+1,bt[i],pr[i],tat[i],wt[i]);
    }

    awt=awt/n; 
    atat=atat/n; 
    printf("\n");
    printf("==============================================================================================================\n");
    printf("==============================================================================================================\n");
    printf("Average Waiting Time %f \n ",awt);
    printf("Average Turn Around Time %f \n",tat);


}


int main()
{
int choice;
int Flag;
Flag = 1;
while (Flag == 1) {
printf("\n");
printf("========================================================================================================\n");
printf("\n");
printf("=================================== *** WELCOME TO SCHEDULER PROGRAM *** ===============================\n");
printf("\n");
printf("=========================================================================================================\n");
printf("\n");
printf("\n");
printf("\n");
printf(" 1 : To Perfrom First Come First Serve Algorithm \n");
printf(" 2 : To Perfrom Shortest Job First Scheduling Algorithm \n");
printf(" 3 : To Perfrom Round Robin Scheduling Algorithm \n");
printf(" 4 : To Perfrom Priority Scheduling Algorithm Non-Preemptive \n");
printf(" 5 : To Perfrom Priority Scheduling Algorithm Preemptive \n");
printf(" 6 : To Exit \n");

printf("\n");
printf("========================================================================================================\n");
printf("\n");
printf("=================================== ***-------------------------------*** ===============================\n");
printf("\n");
printf("=========================================================================================================\n");
printf("\n");
printf("\n");
printf("Enter your Choice: \n ");

scanf("%d", &choice);
if (choice == 6) {
Flag == 0;
printf("Thank You For Using Our Program!!!");
break;
}
if (choice == 1) {

FCFS();

}

if (choice == 2) 
{

SJF();

}

if (choice == 3) 
{

RR();

}
if (choice == 4) 
{

PSNP();

}

}
}