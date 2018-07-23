
	#include<stdio.h>

	int main()
	{
		FILE *ptr_file;
		int x;

		ptr_file =fopen("output.txt", "w+");

		if (!ptr_file)
		{
			printf("error");
			return 1;
		}

		fprintf(ptr_file,"%d",2);
		int buf;

		//for (x=1; x<=10; x++)
		//fprintf(ptr_file,"%d\n", x);
		fseek(ptr_file,0,SEEK_SET);

		fscanf(ptr_file,"%d",&buf);
    		//while (fgets(buf,1000, ptr_file)!=NULL)
        		printf("%d\n",buf);

		fclose(ptr_file);

		return  0;
	}