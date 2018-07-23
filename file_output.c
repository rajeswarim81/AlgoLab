
	#include<stdio.h>

	int main()
	{
    		FILE *ptr_file;
    		int buf;

    		ptr_file =fopen("output.txt","r+");
    		if (!ptr_file)
        		return 1;
            fscanf(ptr_file,"%d",buf);
    		//while (fgets(buf,1000, ptr_file)!=NULL)
        		printf("%d",buf);

		fclose(ptr_file); getchar();
    		return 0;
	}