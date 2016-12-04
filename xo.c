  //                  					  //
 //		   TIC TAC TOE                           //    
//						        //
#include<stdio.h>
char a[3][3];
int win1=0,cw=0,cl=0,pw=0,pl=0,n,k1=0,po[20],po1[20],cp,cp1;
int fl=0;
// INTIALIZATION
void intialize()
{
int i,j;
 for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
	a[i][j]='*';
	}
 }
}
//PRINTTING OUTPUT
void output()
{
int i,j;
 for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
	printf("%c\t",a[i][j]);
	}
	printf("\n");
 }
} 

//COMPUTER MOVEMENT FUNCTION
void cmove() 
{
srand(time(NULL));

cp=rand()%3,cp1=rand()%3;
if(a[cp][cp1]=='*')
{
printf("AAAA\n");
a[cp][cp1]='O';

}
else
cmove();
}

void defence(int k2)
{
k2=k2-1;

int i1;
//VERTICAL AND HORIZONTAL ATTACK
for(i1=1;i1<=k2;i1++)
{
if(po[k2]==po[k2-i1])
{
printf("VER\n");
cp=po[k2]-1;
if(((po1[k2]==1)&&(po1[k2-i1]==2))||((po1[k2]==2)&&(po1[k2-i1]==1)))
{cp1=2;
printf("VER 2\n");
fl=1;
break;}
if(((po1[k2]==3)&&(po1[k2-i1]==2))||((po1[k2]==2)&&(po1[k2-i1]==3)))
{
printf("VER 0\n");
cp1=0;
fl=1;
break;
}
if(((po1[k2]==1)&&(po1[k2-i1]==3))||((po1[k2]==3)&&(po1[k2-i1]==1)))
{cp1=1;
printf("VER 1\n");
fl=1;
break;}

}

if(po1[k2]==po1[k2-i1])
{
{printf("HOR\n");
cp1=po1[k2]-1;}
if(((po[k2]==1)&&(po[k2-i1]==2))||((po[k2]==2)&&(po[k2-i1]==1)))
{printf("HOR 2\n");
cp=2;
fl=1;
break;}
if(((po[k2]==3)&&(po[k2-i1]==2))||((po[k2]==2)&&(po[k2-i1]==3)))
{printf("HOR 0\n");
cp=0;
fl=1;
break;}
if(((po[k2]==1)&&(po[k2-i1]==3))||((po[k2]==3)&&(po[k2-i1]==1)))
{printf("HOR 1\n");
cp=1;

fl=1;
break;}

}
}
//LEFT DIAGONAL ATTACK
if((a[0][0]==a[1][1])||(a[0][0]==a[2][2])||(a[2][2]==a[1][1]))
{

int a1,b,b1,c;

for(i1=1;i1<=k2;i1++)
{
b1=po[k2]+po[k2-i1];
c=po1[k2]+po1[k2-i1];
if((b1==3)&&(c==3))
{
printf("L Dia \n");
cp=2;
cp1=2;
fl=1;
break;
}
if((b1==5)&&(c==5))
{
printf("L Dia \n");
cp=0;
cp1=0;
fl=1;
break;
}
if((b1==4)&&(c==4))
{
printf("L Dia \n");
cp=1;
cp1=1;
fl=1;
break;
}

}
}
//RIGHT DIAGONAL ATTACK
if((a[0][2]==a[1][1])||(a[0][2]==a[2][0])||(a[2][0]==a[1][1]))
{
int a1,b,b1,c;


for(i1=1;i1<=k2;i1++)
{
b1=po[k2]+po[k2-i1];
c=po1[k2]+po1[k2-i1];
if((b1==3)&&(c==5))
{
printf("R Dia \n");
cp=2;
cp1=0;
fl=1;
break;
}
if((b1==5)&&(c==3))
{
printf("R Dia \n");
cp=0;
cp1=2;
fl=1;
break;
}
if((b1==4)&&(c==4))
{
printf("R Dia \n");
cp=1;
cp1=1;
fl=1;
break;
}
}
}

if(fl=1)
{

if(a[cp][cp1]=='*')
a[cp][cp1]='O';

else
{
cmove();
return;
}
}
if(fl==0)
cmove();
return;
}

/*void attack()
{
if((a[0][0]==a[0][1])||(a[0][1]==a[0][2])||(a[0][0]==a[0][2]))
{
}*/

//CALUCULATE THE WINNER
void win()
{
int i;
for(i=0;i<3;i++)
{
if(a[i][1]==a[i][2])
	{
	 if(a[i][2]==a[i][0])
		{
		 	
                 if(a[i][2]=='X')
		 {
		 win1=1;	
		 printf("Player is winner\n");
		 cl++;
		 pw++;
		 return;
		 }
		 if(a[i][2]=='O')
	         {
		 win1=1;		
		 printf("Computer is winner\n");
		 cw++;
     		pl++;
		 return;		 
		 }
		
		
		}
	}

if(a[0][i]==a[1][i])
	{
	 if(a[1][i]==a[2][i])
		{
		 	
                 if(a[1][i]=='X')
		 {
		 win1=1;
		 printf("Player is winner\n");
		 cl++;
		 pw++;
		 return;
                 }		 
		 if(a[1][i]=='O')
		 {
		 win1=1;
		 printf("Computer is winner\n");
		 cw++;
     		pl++;
		 return;
		 }
	
		}
	}
}

if(a[1][1]==a[2][2])
{

if(a[0][0]==a[2][2])
{
		 if(a[0][0]=='X')
		 {
		 win1=1;
		 printf("Player is winner\n");
		  cl++;
		 pw++;
	         return;        
		 }		 
		 if(a[0][0]=='O')
		 {
		 win1=1;
		 printf("Computer is winner\n");
		 return;
		 }
		 
}
}
if(a[2][0]==a[1][1])
{
if(a[0][2]==a[2][0])
{
		 if(a[1][1]=='X')
		 {
		 win1=1;
		 printf("Player is winner\n");
		  cl++;
		 pw++;
                 }		 
		 if(a[1][1]=='O')
		 {
		 win1=1;
		 printf("Computer is winner\n");
		 cw++;
     		pl++;
		 }
return;
}		
}

}
//MAIN FUNCTION

main()
{
int i,j,k=9;
FILE *fp;
fp=fopen("win.txt","w");
printf("\n1.Play\n");
printf("\n2.Exit\n");
scanf("%d",&n);
if(n==1)
{
system("clear");
intialize();
output(); 
for(win1=0,i=0,j=0;j<k;j++)
{
    
if(i<=9)
{
if(i%2==0)
{
//PLAYER MOVEMENT
	printf("\nEnter Position");
	scanf("%d %d",&po[k1],&po1[k1]);
		if(a[po[k1]-1][po1[k1]-1]=='*')
			{    
	                   
			a[po[k1]-1][po1[k1]-1]='X';	
			i=i++;
	
			k1=k1+1;
				
			if(i==9)
			{
			system("clear");
						
			output();
			//win();
			
			if(win1==0)
			{
			system("clear");
			output();
		        printf("\nGame is Draw\n");}
			break;	
			}	
			}
		else
			{
			printf("\nSay Another Location\n");
			k++;	                        
			continue;
			}			
}
if(i%2!=0)
{
if(i<3)
cmove();
if(i>2)
defence(k1);
i++;
}
}
system("clear");
//printf("%d\n",i);	
win();
output();
if(win1==1)
{
fprintf(fp,"Computer Wins %d\nComputer lose %d\nPlayer wins %d\nPlayer lose %d\n",cw,cl,pw,pl);
fclose(fp);
break;
}
if(n==2)
break;
}
}
}

