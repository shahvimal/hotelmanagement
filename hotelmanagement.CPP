#include<stdio.h>
#include<conio.h>
struct hotel
{
	int room_num,price;
	int days;
	char type,availability;
	char name[20];
}hotel_data[100];
int add_database();
void menu(int counter);
void all_rooms(int counter);
int book(int counter,int count1);
void checkout(int counter,int count1);
int all_available_rooms(int counter);
void bill(int i);

int main()
{
    int counter;
    printf("Create a Database for your Hotel:\n");
    counter=add_database();
	//struct hotel h;
	menu(counter);
}
void menu(int counter)
{
    int n,count1,i=1;
    while(i==1)
    {
	printf("\t\t MENU \n1.\t ALL ROOMS.\n2.\t AVAILABLE ROOMS.\n3.\t BOOK ROOM.\n4.\t CHECK OUT OF ROOM.\n5.\t ADD ROOM.\n6.\t EXIT.");
	scanf("%d",&n);


	switch(n)
	{
	case 1:
		all_rooms(counter);
		break;
    case 2:
		count1=all_available_rooms(counter);
		menu(counter);
		break;
	case 3:
		count1=book(counter,count1);
		menu(counter);
		break;
	case 4:
		checkout(counter,count1);
		break;
	case 5:
        counter=add_database();
		break;
	case 6:
	    i=0;
        break;
	default :
	    break;
	}
    }
}


void all_rooms(int counter)
{
    int i;
	printf("\n No of rooms::%d",counter);
	for(i=0;i<counter;i++)
	{
	printf("\n %d ROOM NO:: %d\n TYPE:: %c \t PRICE %d per day::\n availability %c\n\n",i+1,hotel_data[i].room_num,hotel_data[i].type,hotel_data[i].price,hotel_data[i].availability);
	}
	menu(counter);
}
int add_database()
{
    static int i=0,n=0,counter=0;
    int num;
	printf("enter number of rooms to be added::\n");
	scanf("%d",&num);
	n=n+num;

	while(i<n)
	{
	printf("Enter the rooom no::\t");
	scanf("%d",&hotel_data[i].room_num);
	printf("\nEnter the type::\t A--AC\t,\t N--NON-AC\t");
	scanf(" %c",&hotel_data[i].type);
	printf("\nEnter the price::\t");
	scanf("%d",&hotel_data[i].price);
	printf("\nAvailability:(Y:yes,N:no):\t");
	scanf(" %c",&hotel_data[i].availability);
	++counter;
	i++;
	}
	return counter;
}

int all_available_rooms(int counter)
{
    int i,count1=0;
    for(i=0;i<counter;i++)
    {
      if(hotel_data[i].availability=='Y'||hotel_data[i].availability=='y')
      {
        ++count1;
        printf("\n %d ROOM NO:: %d\n TYPE:: %c \t PRICE %d per day::\n availability %c (A--AC,N--NON AC)\n\n",i+1,hotel_data[i].room_num,hotel_data[i].type,hotel_data[i].price,hotel_data[i].availability);
      }

      else
        printf("There is no avaliable room");
    }
    return count1;
}

int book(int counter,int count1)
{
    char t1,t2,i;
    count1 = all_available_rooms(counter);
    printf("\nEnter the type of room required :A--AC, N--NON-AC:\t");
    scanf(" %c",&t1);
    for(i=0;i<counter;i++)
    {

        if((hotel_data[i].availability=='Y'||hotel_data[i].availability=='y')&&hotel_data[i].type==t1)
        {
            printf("\nDo you want to book\t Y--yes,N--NO");
            scanf(" %c",&t2);
            if(t2=='Y')
            {
                hotel_data[i].days=0;
                hotel_data[i].availability='N';
                printf("Enter the name of the customer::\t");
                scanf(" %s",&hotel_data[i].name);
                --count1;
                printf("\n   for how many days do you wish to stay?");
                scanf("%d",&hotel_data[i].days);
                printf("\n thankyou for choosing our hotel your booking has been confirmed!!\n Have a pleasant stay\n ");
                menu(counter);
            }
            else
                break;

        }
    }
    printf("do you want to book another room? Y--Yes, N--No");
    scanf(" %c",&t2);
    if(t2 == 'Y')
    {
        book(counter,count1);
    }
    else
    {
        return count1;
    }
}
void checkout(int counter,int count1)
{
    char t1;
    int r1,i;
    printf("\ndo you want to checkout::\t");
    scanf(" %c",&t1);
    if(t1=='y'||t1=='Y')
    {
        printf("enter the room no");
        scanf("%d",&r1);
        for(i=0;i<counter;i++)
        {
        if(r1==hotel_data[i].room_num)
        {
            bill(i);
            ++count1;
            hotel_data[i].days=0;
            printf("THANK YOU\t");
            menu(counter);
        }
        }
    }
    else
    {
        menu(counter);
    }
}

void bill(int i)
{
    int amount=0;
    amount=hotel_data[i].days*hotel_data[i].price;
    printf("The bill totaled is ::\t%d\n\n",amount);
}
