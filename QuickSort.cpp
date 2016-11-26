#include<stdio.h>

int 	compare(int a,int b)
{
	if(a>b)return 1;
	
	if(a<b)return -1;

	return 0;
}

void 	exch(int* pArray,int a,int b)
{
	int nTmp;
	
	nTmp = pArray[a];
	pArray[a] = pArray[b];
	pArray[b] = nTmp;
}

void	 QuickSort(int *pArray,int nLow,int nHight)
{
	if(nHight<= nLow)
		return;	
	
	int lt = nLow,i = nLow +1,gt = nHight;

	int nKey = pArray[nLow];

	int iRet  =0;

	while(i <= gt) 
	{
		iRet = compare(pArray[i],nKey);
		if(iRet < 0) exch(pArray,lt ++,i++);
		else if(iRet >0) exch(pArray,i,gt--);
		else i++; 
	}

	QuickSort(pArray,nLow,lt -1);
	QuickSort(pArray,gt+1,nHight);
}


void Display(int *pArray)
{
	for(int j =0 ;j<=23;j++)
		printf("%d ",pArray[j]);
		
	printf("\n");
}

void	moveData(int *pArray,int number,int nLow,int nHight)
{
	for(int i =0;i<number;i++)
		exch(pArray,nLow++,nHight--);
}

/*快速排序--三向切分算法*/
void	 QuickSort3(int *pArray,int nLow,int nHigh)
{
	if(nHigh<= nLow)
		return;	
	
	int i = nLow +1,j = nHigh;
	int p = nLow,q = nHigh;
	int nKey = pArray[nLow];
	int iRet = 0;

	while(1) 
	{
		while(i <j)/*不能为等号，否则i有可能越界到j之后的数据，把原本大的数据置换到小的地方！如： 5 |4 4 7;i = 0,j =1,7会被置换到4的位置！*/
			if(pArray[i]<nKey){i++;continue;}
			else	break;

		if(pArray[i] == nKey)
			exch(pArray,++p,i++);
		else if(pArray[i]>nKey)
			exch(pArray,j--,i);
			
		if(i>j)break;

		while( j>i)
			if(pArray[j]>nKey){j--;continue;}
			else break;

		if(pArray[j] == nKey)
			exch(pArray,q--,j--);
		else if(pArray[j]<nKey)
			exch(pArray,i++,j);

		if(i > j)break;
	}

	int number = p-nLow+1;
	int number2= nHigh -q;

	moveData(pArray,number,nLow,j);
	moveData(pArray,number2,i,nHigh);	

	QuickSort3(pArray,nLow,j-number);
	QuickSort3(pArray,i+number2,nHigh);
}

int main()
{
	int a[] ={1,4,9,0,-9,8,0,9,78,34,9,833,45345,345,67,46,454,44,4,5,6,25,55,788,99};
	
	int i = sizeof(a)/sizeof(int) -1;

	QuickSort3(a,0,i);

	Display(a);
}
