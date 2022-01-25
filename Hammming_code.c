#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int d[30],tra[30],res[30],i,j,k,r=0,c,m,pos,cnt=0;
printf("\n******** Transmitter Side *******");
printf("\n Enter the length of data : ");
scanf("%d",&m);
printf("\n Enter the %d data bits : \n",m);
for(i=0;i<m;i++)
 scanf("%d",&d[i]);
// Finding no of check bits(r)
 while(m+r+1>pow(2,r))
 r++;
printf("\n\n Number of check bits are : %d",r);
//making the values at all positions of transmitted data zero
for(i=1;i<=m+r;i++)
 tra[i]=0;
for(i=1,j=0;i<=m+r;i++)
{
if(i==pow(2,j))
j++;
else
{
 tra[i]=d[cnt];
 cnt++;
}
 }
//finding values of check bits
for(i=0;i<r;i++)
{
c=0;
pos=pow(2,i);
for(j=pos;j<=m+r;j=j+(2*pos))
 for(k=j;k<=m+r&&k<(j+pos);k++)
 c=c^tra[k];
printf("\n c%d = %d ",i,c);
tra[pos]=c;
}
printf("\n\nTransmitted data : ");
for(i=1;i<=m+r;i++)
 printf(" %d",tra[i]);
printf("\n******* Receiver Side ********");
printf("\nTransmitted data : ");
for(i=1;i<=m+r;i++)
 printf(" %d",tra[i]);
printf("\n\n Enter received data : \n");
for(i=1;i<=m+r;i++)
scanf("%d",&res[i]);
for(i=0;i<r;i++)
{
 c=0;
 pos=pow(2,i);
for(j=pos;j<=m+r;j=j+(2*pos))
 for(k=j;k<=m+r&&k<(j+pos);k++)
 c=c^res[k];
}
int err=0;
cnt=0;
for(i=1;i<=m+r;i++)
{
 if(tra[i]!=res[i])
 {
 cnt++;
 err=i;
 break;
 }
 else
 continue;
}
if(cnt==0)
{
printf("\n\nData Received Correctly ! ");
exit(0);
}
else
{
printf("\n\n Data Not Received Correctly ! \n");
 for(i=1;i<=m+r;i++)
 {
 printf(" %d ",tra[i]);
 }
 printf("\n");
 for(i=1;i<=m+r;i++)
 {
 printf(" %d ",res[i]);
 }
 printf("\n\n Error at %d position",err);
}
return 0;
}
