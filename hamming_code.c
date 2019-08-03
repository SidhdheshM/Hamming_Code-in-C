//For Hamming Code Generation we take input as Data bits and based on Number of Data Bits we add Parity Bits.
//In this code initially I have inserted parity Bits as 0 since location where parity bit is to be inserted is important at first.
//After getting the location now we set the value of parity bits as 0 or 1 based on our even/odd parity rule. I have taken EVEN Parity

#include<stdio.h>
#include<math.h>

void errordetect();
void hammingcode();
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
			break();

	}

}

void errordetect()
{
	int n,num=0,d[100],p[10],i,j,k,r,cnt;
	printf("Enter number of Bits of the Hamming Code:  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Bit number %d: ",i);	//Here the Input consists of both Data bits and Parity Bits
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

}//End of Error Detect Fuction.Thus we find the position of erronous bit


void hammingcode()
{
	int d[100],n,p[10],main[110],i,j,r,k=1,l=1,loc[10],cnt;
	printf("Enter length of data Bits: ");
	scanf("%d",&n);
	i=1;
	while(i<=n)
	{
		printf("Data Bit number %d: ",i);	//Taking Input as Only Data Bits
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



	// Finding Location of additional(parity) bits and putting value of those bits as 0 in new 'main' array
	
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
				main[i]=d[k];	//Remaining Data Bits is Copied from d[] to main[]
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
	
	//Setting The Actual Values Of Parity Bits
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
//End of Code

