#include<stdio.h> #include<conio.h> #define max 25 void firstfit()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp; static int bf[max],ff[max];

printf("\nEnter the number of blocks:"); scanf("%d",&nb);
printf("Enter the number of files:"); scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
 
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n"); for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i]; if(temp>=0)
{
ff[i]=j; break;
}
}
}
frag[i]=temp; bf[ff[i]]=1;
}
printf("\nFile_size:\tBlock_size:"); for(i=1;i<=nf;i++)
 
printf("\n%d\t\t%d",f[i],b[ff[i]]);
}


void bestfit()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000; static int bf[max],ff[max];

printf("\nEnter the number of blocks:"); scanf("%d",&nb);
printf("Enter the number of files:"); scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n"); for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n"); for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
 
temp=b[j]-f[i]; if(temp>=0) if(lowest>temp)
{
ff[i]=j;


lowest=temp;
}
}
}
frag[i]=lowest; bf[ff[i]]=1; lowest=10000;
}
printf("\nFile Size:\tBlock Size:"); for(i=1;i<=nf && ff[i]!=0;i++) printf("\n%d\t\t%d",f[i],b[ff[i]]);
}


void worstfit()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0; static int bf[max],ff[max];

printf("\nEnter the number of blocks:"); scanf("%d",&nb);
printf("Enter the number of files:"); scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n"); for(i=1;i<=nb;i++)
 
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n"); for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{


for(j=1;j<=nb;j++)
{
if(bf[j]!=1) //if bf[j] is not allocated
{
temp=b[j]-f[i]; if(temp>=0) if(highest<temp)
{
ff[i]=j; highest=temp;
}
}
}
frag[i]=highest; bf[ff[i]]=1; highest=0;
}
 
printf("\nFile_size:\tBlock_size:"); for(i=1;i<=nf;i++) printf("\n%d\t\t%d",f[i],b[ff[i]]);
}


void main()
{
int c; while(1)
{
printf("\n1.First Fit 2.Best Fit 3.Worst Fit 4.Exit"); printf("\nEnter choice:");
scanf("%d",&c); switch(c)
{
case 1:firstfit(); break;
case 2:bestfit(); break;
case 3:worstfit(); break;
case 4:exit(0); default:printf("Invalid choice");
}
}
}

