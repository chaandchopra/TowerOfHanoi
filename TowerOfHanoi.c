#include<stdio.h>
#include<math.h>

int presrc = 0, predes = 0, empty = 0;

void printarray(int *src, int *des, int *aux, int *ls, int *la, int *ld, int *step);

int checkeven(int var);

void movement(int *src, int *des, int *ls,int *ld);

int conditions(int val1, int val2, int *ls, int *ld, int *src, int *des, int *temp);

int main()
{
	int step = 0, i, j = 0, num, k = 1, temp, check;
	
	printf("Enter no of element in tower of hanoi:\n");
	scanf("%d", &num);
	
	int ls = num, la, ld,val=pow(2,num)-1, src[num + 1], aux[num + 1], des[num + 1], prestep = 1;
	
	src[0] = 0;
	des[0] = 0;
	aux[0] = 0;
	
	for( i = num; i > 0; --i)
	{
		src[k] = i;
		++k;
	}//Inputting values in source.
		
	if(num % 2 == 0)
	{
		movement(src, aux, &ls, &la);
		presrc = 1;
		predes = 2;
		++step;
		printarray(src, des, aux, &ls, &la, &ld, &step);
	}// First step for even no. of disks.
	else
	{
		movement(src, des, &ls, &ld);
		presrc = 1;
		predes = 3;
		++step;
		printarray(src, des, aux, &ls, &la, &ld, &step);
	}// First step for odd no. of disks.	

	while(step < val)
	{
		for(i = 1; i <= 3; ++i)
		{
			for(j = 1; j <= 3; ++j)
			{
								
				if(i == j)// Same Disks 
					continue;
				
				
				if( presrc == j && predes == i)// Rule 1: Previous Step shouldn't be Repeats.
					continue;
								
				if( i == 1 && j == 2)
				{
					check = conditions(1, 2, &ls, &la, src, aux, &temp);	
										
					if(check == 0)
					{
						++step;
						prestep = step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}
					if (check == 3)
					{
						empty = 1;
					}					
				}// Movement from Tower 1 to Tower 2 
				
				if( i == 1 && j == 3)
				{
					check = conditions(1, 3, &ls, &ld, src, des, &temp);
					
					if(check == 0)
					{
						++step;
						prestep = step;	
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}
					
					if (check == 3)
					{
						empty = 1;
					}
					
				}// Movement from Tower 1 to Tower 3
				
				if( i == 2 && j == 3)
				{
					check = conditions(2, 3, &la, &ld, aux, des, &temp);
					
					if(check == 0)
					{
						++step;
						prestep = step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}
					else if (check ==3)
						empty = 1;				
				}// Movement from Tower 2 to Tower 3
				
				if( i == 2 && j == 1)
				{
					check = conditions(2, 1, &la, &ls, aux, src, &temp);
					
					if(check == 0)
					{
						++step;
						prestep = step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}
					else if (check ==3)
						empty = 1;				
					
				}// Movement from Tower 2 to Tower 1
				
				if( i == 3 && j == 1)
				{
					check = conditions(3, 1, &ld, &ls, des, src, &temp);
					
					if(check == 0)
					{
						++step;
						prestep = step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}
					else if (check ==3)
						empty = 1;				
				}// Movement from Tower 3 to Tower 1		
				
				if( i == 3 && j == 2)
				{
					check = conditions(3, 2, &ld, &la, des, aux, &temp);
					
					if(check == 0)
					{
						++step;
						prestep = step;
						printarray(src, des, aux, &ls, &la, &ld, &step);					
					}
					else if (check ==3)
						empty = 1;									
				}// Movement from Tower 3 to Tower 2
			}//End of Destination Loop

			
			if(check == 2)// If Source is Empty.
				continue;
	
			if(empty == 1 && prestep == step && step < val)//If destination tower is Empty.
			{
				if(i == 1)
				{
					if(temp == 2)
					{
						if( presrc == 2 && predes == i)//r1
							continue;
									
						movement(src, aux, &ls, &la);
						++step;
						presrc = i;
						predes = temp;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}// Movement from Tower 1 to Tower 2
					if(temp == 3)
					{
						if( presrc == j && predes == i)//r1
							continue;
			
						movement(src, des, &ls, &ld);
						++step;
						presrc = i;
						predes = temp;
						printarray(src, des, aux, &ls, &la, &ld, &step);
					}// Movement from Tower 1 to Tower 3
				}

				if(i == 2)
				{
					if(temp == 1)
					{
						if( presrc == j && predes == i)//r1
							continue;
												
						movement(aux, src, &la, &ls);
						++step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
						presrc = i;
						predes = temp;
					}// Movement from Tower 2 to Tower 1
					if(temp == 3)
					{
						if( presrc == j && predes == i)//r1
							continue;
																		
						movement(aux, des, &la, &ld);
						++step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
						presrc = i;
						predes = temp;
					}// Movement from Tower 2 to Tower 3
				}
				
				if(i == 3)
				{
					if(temp == 2)
					{
						if( presrc == j && predes == i)//r1
							continue;
									
						movement(des, aux, &ld, &la);
						++step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
						presrc = i;
						predes = temp;
					}// Movement from Tower 3 to Tower 2
					
					if(temp == 1)
					{
						if( presrc == j && predes == i)//r1
							continue;
																			
						movement(des, src, &ld, &ls);
						++step;
						printarray(src, des, aux, &ls, &la, &ld, &step);
						presrc = i;
						predes = temp;
					}// Movement from Tower 3 to Tower 1
				}
				prestep = step;
			}
			else
			{
				prestep = step;
			}
			empty = 0;
		}// End of Source Loop	
	}//End while loop for Number of Steps.
	
	return 0;
}

void movement(int *src, int *des, int *ls, int *ld)
{
	int temp1, v1, v2;
	v1 = *ls;
	v2 = *ld + 1;
	printf("\nMoving disk %d over %d.\n",src[v1], des[v2-1]);
	temp1 = src[v1];
	des[v2] = temp1 ;
	*ls = *ls - 1;
	*ld = *ld +1;
}


int conditions(int val1, int val2, int *ls, int *ld, int *src, int *des, int *temp)
{
	int temp1, temp2;
	int v2 = *ld;
	int v1 = *ls;
	

	if(*ls == 0)// Empty Source Tower
		return 2;

	if(*ld == 0)// Empty Destination Tower
	{
		*temp = val2;
		return 3;
	}
	
	temp1 = checkeven(src[v1]);
	temp2 = checkeven(des[v2]);
	
	if(temp1 == temp2)// Disks of same even or odd.
		return 1;

	else if(temp1 != temp2)
	{
		if(des[v2] > src[v1])// Destination disk greater than source disk.
		{
			movement(src, des, ls, ld);
			presrc = val1;
			predes = val2;
			return 0;
		}
		else
			return 1;
	}
}

int checkeven(int val)
{
	if(val % 2 == 0)
		return 0;
	else
		return 1;
}

void printarray(int *src, int *des, int *aux, int *ls, int *la, int *ld, int *step)
{
	int i = 0;
	int v1 = *ls;
	int v2 = *la;
	int v3 = *ld;
	printf("Step %d: \n\n",*step);
	printf("Source: \t ");
	for(i = 1; i <= v1; i++)
		printf("  %d  ", src[i]);
	printf("\n ");
	printf("\nAuxiliary:\t");	
	for(i = 1; i <= v2; i++)
		printf("  %d  ", aux[i]);
	printf("\n");	
	printf("\nDestination:\t");	
	for(i = 1; i <= v3; i++)
		printf("  %d  ", des[i]);
	printf("\n--------------------------------------------\n");
}
