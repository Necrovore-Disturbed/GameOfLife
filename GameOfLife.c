#include<stdio.h>
int n=50;
int grid[50][50];
int aux[50][50];
void display()
{
     int i,j;
     printf("\n");
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
           if(grid[i][j]==1)
           {
               printf("%d",grid[i][j]);
           }
           else
           {
               printf(" ");
           }
           
        }
        printf("\n");
     }
}

void copyback()
{
     int i,j;
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
           grid[i][j]=aux[i][j];
        }
        
     }
}
void init()
{
     int i,j;
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
           grid[i][j]=0;
           aux[i][j]=0;
        }
     }
}
void initial_pattern()
{
     
     grid[25][25]=grid[25][26]=grid[25][27]=grid[25][28]=grid[26][26]=grid[26][27]=grid[26][28]=grid[27][26]=grid[27][27]=grid[27][28]=grid[28][26]=grid[28][27]=grid[28][28]=1;
}

void killing(int kx,int ky)
{
     int neighbours=0;
     if(grid[kx][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx][ky+1]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky+1]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky+1]==1)
     {
       ++neighbours;
     }
     if(neighbours<2 || neighbours>3)
     {
        aux[kx][ky]=0;
     }
     else
     {
         aux[kx][ky]=1;
     }
     
     
}


void bringalive(int kx,int ky)
{
     int neighbours=0;
     if(grid[kx][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx][ky+1]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx-1][ky+1]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky-1]==1)
     {
       ++neighbours;
     }
     if(grid[kx+1][ky+1]==1)
     {
       ++neighbours;
     }
     if(neighbours==3)
     {
        aux[kx][ky]=1;
     }
     else
     {
         aux[kx][ky]=0;
     }
     
     
}

void main()
{
     int i,j;
     init();
     initial_pattern();
     printf("\n\n");
     display();
     //getch();
     sleep(1000);
     system("CLS");
     do
     {
            
            for(i=0;i<n;i++)
            {
               for(j=0;j<n;j++)
               {
                  if(grid[i][j]==0)
                  {
                      bringalive(i,j);
                  }
                  else
                  {
                      killing(i,j);
                  }
               }
               
               
            }
            printf("\n\n");
            copyback();
            display();
            sleep(1000);
            system("CLS");
     }while(1==1);
     
     //getch();
}
