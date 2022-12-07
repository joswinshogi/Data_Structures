#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	int allocation[n];

	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}
	for (i = 0; i < n; i++)	 
	{
		for (j = 0; j < m; j++)	 
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break; 
			}
		}
	}
    printf("======FIRST FIT======\n");
	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}
void bestFit(int blockSize[], int m, int processSize[],int n)
{
		int allocation[n];
		for (int i = 0; i < n; i++)
        {
			allocation[i] = -1;
        }
		for (int i=0; i<n; i++)
		{
			int bestIdx = -1;
			for (int j=0; j<m; j++)
			{
				if (blockSize[j] >= processSize[i])
				{
					if (bestIdx == -1)
						bestIdx = j;
					else if (blockSize[bestIdx] > blockSize[j])
						bestIdx = j;
				}
			}
			if (bestIdx != -1)
			{
				allocation[i] = bestIdx;
				blockSize[bestIdx] -= processSize[i];
			}
		}
        printf("======BEST FIT======\n");
		printf("\nProcess No.\tProcess Size\tBlock no.\n");
	    for (int i = 0; i < n; i++)
	    {
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	    }
}
void worstFit(int blockSize[], int m, int processSize[],int n)
{
		int allocation[n];
		for (int i = 0; i < n; i++)
			allocation[i] = -1;
		for (int i=0; i<n; i++)
		{
			int wstIdx = -1;
			for (int j=0; j<m; j++)
			{
				if (blockSize[j] >= processSize[i])
				{
					if (wstIdx == -1)
						wstIdx = j;
					else if (blockSize[wstIdx] < blockSize[j])
						wstIdx = j;
				}
			}
			if (wstIdx != -1)
			{
				allocation[i] = wstIdx;
				blockSize[wstIdx] -= processSize[i];
			}
		}
        printf("======WORST FIT======\n");
		printf("\nProcess No.\tProcess Size\tBlock no.\n");
	    for (int i = 0; i < n; i++)
	    {
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	    }
}
int main()
	{
		int m,n,bsize[10],psize[10],i;
        printf("enter the number of the blocks\n");
        scanf("%d",&m);
        printf("enter the size of each blocks\n");
        for(i=0;i<m;i++)
            scanf("%d",&bsize[i]);
        printf("enter the number of the process\n");
        scanf("%d",&n);
        printf("enter the size of process\n");
        for(i=0;i<n;i++)
            scanf("%d",&psize[i]);
        firstFit(bsize, m, psize, n);
		bestFit(bsize, m, psize, n);
		worstFit(bsize, m, psize, n);
	}