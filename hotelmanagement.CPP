#include<stdio.h>
#include<conio.h>
int i;
int count1;
struct hotel
{
	int r[100],p[100],day[100],n;
	char t[100],available[100];
}h;
struct hotel1
{
    char name[100];
}h1[3];
int n;
int count;
int add();
void menu();
void all_rooms(int);
int book(int,int);
void checkout(int,int);
int all_available_rooms(int);
void bill(int,int);

int main()
{
    count=add();
	//struct hotel h;
	menu();
}
void menu()
{

	printf("\t\t MENU \n1.\t ALL ROOMS.\n2.\t AVAILABLE ROOMS.\n3.\t BOOK ROOM.\n4.\t CHECK OUT OF ROOM.\n5.\t ADD ROOM.\n");
	scanf("%d",&n);


	switch(n)
	{
	case 1:
		all_rooms(count);
		break;
       	case 2:
		count1=all_available_rooms(count);
		menu();
		break;
	case 3:
		count1=book(count,count1);
		break;
	case 4:
		checkout(count,count1);
		break;
	case 5:
        count=add();
		break;
	default :
		printf("\t\t MENU \n1.\t ALL ROOMS.\n2.\t AVAILABLE ROOMS.\n3.\t BOOK ROOM.\n4.\t CHECK OUT OF ROOM.\n5.\t ADD ROOM.");
	}
}


void all_rooms(int count)
{
	printf("\n No of rooms::%d",count);
	for(i=0;i<count;i++)
	{
	printf("\n %d ROOM NO:: %d\n TYPE:: %c \t PRICE %d per day::\n availability %c\n\n",i+1,h.r[i],h.t[i],h.p[i],h.available[i]);
	}
}
int add()
{
    int count=0;
	int r[100],p[100] ,n;
	char t[100],available[100];

	printf("enter number of rooms to be added::\n");
	scanf("%d",&h.n);
	for(int i=0;i<h.n;i++)
	{
	printf("enter the rooom no::\t");
	scanf("%d",&h.r[i]);
	printf("enter the type::\t A--AC\t,N--NON AC \t");
	scanf(" %c",&h.t[i]);
	printf("enter the price::\t");
	scanf("%d",&h.p[i]);
	printf("availability::\t");
	scanf(" %c",&h.available[i]);
	++count;
	}
	return count;
}

int all_available_rooms(int count)
{
    int count1=0;
    for(i=0;i<count;i++)
    {
  if(h.available[i]=='Y'||h.available[i]=='y')
  {
      ++count1;
	printf("rooom no::\t%d\n",h.r[i]);
	printf("type::\t%c\n",h.t[i]);
	printf("price::\t%d\n",h.p[i]);
	printf("availability::\t%c\n",h.available[i]);
  }
    }
    return count1;
}

int book(int count,int count1)
{
    char t1,t2;
    printf("enter the type of room required ::\t");
    scanf(" %c",&t1);
    for(i=0;i<count;i++)
    {
        h.day[i]=0;
        if((h.available[i]=='Y'||h.available[i]=='y')&&h.t[i]==t1)
        {
            printf("do you want to book\t Y--yes,N--NO");
            scanf(" %c",&t2);
            if(t2=='Y')
            {
                h.available[i]='N';
                printf("enter the name of the customer::\t");
                scanf(" %s",&h1[0].name);
                count1--;
                printf("%s",h1[0].name);
                h.day[i]++;
                menu();
            }
            else
                menu();
        }
    }
    return count1;
}
void checkout(int count,int count1)
{
    char t1;int r1;
    printf("do you want to checkout::\t");
    scanf(" %c",&t1);
    if(t1=='y'||t1=='Y')
    {
        printf("enter the room no");
        scanf("%d",&r1);
        for(i=0;i<count;i++)
        {
        if(r1==h.r[i])
        {
            bill(count,i);
            count1++;
            h.day[i]=0;
            printf("THANK YOU\t");
            menu();
        }
        }
    }
    else
    {
        menu();
    }
}

void bill(int count,int i)
{
    int amount=0;
    amount=h.day[i]*h.p[i];
    printf("the bill totaled is ::\t%d\n\n",amount);
    h.day[i]=0;

}
