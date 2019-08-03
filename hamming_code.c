

// Error Detection using Hamming code
#include<stdio.h>
#include<math.h>

void errordetect();
void hammingcode();

//int errordetect(int);
//Even Parity
void main()
{
	int a;
	printf("What operation you want?\n");
	printf("1. Hamming Code Generation\t2.Error Detection\n");
	scanf("%d",&a);
    switch(a)
	{
		case 1:
		    hammingcode();
		    break;
		case 2:
		    errordetect();
		    break;
        default:
            printf("Invalid input");


	}

}

void errordetect()
{
	int n,num=0,d[100],p[10],i,j,k,r,cnt;
	//printf("SAP ID: 60004170110\n");
	printf("Enter number of Bits of the Hamming Code:  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Bit number %d: ",i);
		scanf("%d",&d[i]);

	}

	r=0;
	while(pow(2,r)<(n+1))
    {
     r++;
    }

	for(i=0;i<r;i++)
	{
		cnt=0;
		for(j=pow(2,i);j<=n;j=j+pow(2,i+1))
		{
			for(k=0;k<pow(2,i);k++)
			{

				if((j+k)<=n)
				{
					if(d[j+k]==1)
						cnt++;
				}
			}
		}

		p[i]=(cnt%2==1)?1:0;

	}
    printf("Array of Parity bits is:\n");
	for(i=0;i<r;i++)
	{
		printf("%d\n",p[i]);
	}



	//Error Detection
	for(i=0;i<r;i++)
	{
		num=num+(p[i]*pow(2,i));
	}
	if(num!=0)
        printf("Error detected at postion %d. Thus invert bit number %d",num,num);

    else
        printf("No error");

}//End of Error Detect Fuction.Thus we find the erronous bit


void hammingcode()
{
	int d[100],n,p[10],main[110],i,j,r,k=1,l=1,loc[10],cnt;
	printf("Enter length of data Bits: ");
	scanf("%d",&n);
	i=1;
	while(i<=n)
	{
		printf("Data Bit number %d: ",i);
		scanf("%d",&d[i]);
		i++;
	}
	r=0;
	while(pow(2,r)< (n+r+1))
    {
     r++;
    }
	printf("\n");
	printf("Number of Parity Bits: %d\n",r);



	// Main array


	for(i=1;i<=n+r;i++)
	{
		for(j=log(i)/log(2);j<=log(i)/log(2);j++)
		{
			if(i== pow(2,j))
			{
				loc[l]=i;
				main[i]=0;
				l++;
            }
			else
			{
				main[i]=d[k];
				k++;
			}
		}
	}
	printf("Initial Hamming Code is:\n");
	for(i=1;i<=(n+r);i++)
    {
        printf("%d",main[i]);
    }

    printf("\n");

    for(i=0;i<r;i++)
	{
		cnt=0;
		for(j=pow(2,i);j<=(n+r);j=j+pow(2,i+1))
		{
			for(k=0;k<pow(2,i);k++)
			{
                if((j+k)<=(n+r))
                {
                   if(main[j+k]==1)
					cnt++;
                }

			}
		}

		p[i]=(cnt%2==1)?1:0;
	}


	printf("Array of Parity Bits is\n");
	for(i=0;i<r;i++)
    {
        printf("%d",p[i]);
    }
    printf("\n");

	i=0;
	for(l=1;l<=r;l++)
	{
		main[loc[l]]=p[i];
		i++;
	}
	printf("Final Hamming Code is:\n");
	for(i=1;i<=(n+r);i++)
    {
        printf("%d\n",main[i]);
    }

}


