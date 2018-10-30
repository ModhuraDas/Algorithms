#include<stdio.h>

int search(int[], int, int);
int rsearch(int[], int, int);

int input, mid;

int search(int data[], int l, int h)
{	while(l <= h){
                mid = (l+h)/2;
                if(data[mid] == input){
                        return mid;
                }
                else if(data[mid] < input){
                        l = mid+1;}
                else if(data[mid] > input){
                        h = mid-1;}
        }
}

int rsearch(int data[], int l, int h){
	int mid = (l+h)/2;
	if(l > h)
		return 0;
	else{
			if(data[mid] == input)
				return mid;
			else{
				if(data[mid] > input)
					rsearch(data,l,(mid-1));
				else if(data[mid] < input)
					rsearch(data,(mid+1),h);
			}
	}
}

void main(){

	int data[10];
	// = {0,1,2,3,4,5,6,7,8,9};
	int l = 0,h = 10, flag =0, c=0;

	printf("\nEnter data(in assending order) :");

        for(int i =0; i<=9; i++)
        {       scanf("%d",&data[i]);}


	printf("Enter data for search : ");
	scanf("%d",&input);

	printf("\n\nEnter Choice : \n\n1.Using recursive method\n2.Without using recursive method\n");
	scanf("%d", &c);
	switch(c)
	{	case 1: flag = rsearch(data,l,h);
			break;

		case 2: flag = search(data,l,h);
			break;

		default: printf("Wrong choice!!");
			 break;
	}
	if(flag != 0)
		printf("\n\nValue found in %d position\n",flag+1);
	else
		printf("\n\nValue not found !\n");
}

