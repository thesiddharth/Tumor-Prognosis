#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("wpbc.data","r");
	FILE *fout = fopen("recur.data","w");
	int i,j,k;
	char out[4];
	char* buf = (char *)malloc(240*sizeof(char));
	char mini_buf[20];
	strcpy(buf," ");
	int count=0;
	while(!feof(fp))
	{
		i=0;		
		fgets(buf,240,fp);
		while(buf[i]!=',')
			i++;
		i++;
		if(buf[i]=='N')
		{
			i+=2;
			j=0;
			while(buf[i]!=',')
			{
				out[j++]=buf[i++];
			}
			out[j]='\0';
		}
		else
		{
			while(buf[i]!=',')
				i++;
			strcpy(out,"-20");
		}
		i++;
		j=0;
		while(j<10)
		{
			k=0;
			while(buf[i]!=',')
			{
				mini_buf[k++]=buf[i++];
			}
			mini_buf[k]='\0';
			i++;
			fprintf(fout,"%s ",mini_buf);
			j++;
		}
		while(buf[i+3]!='\n')
			i++;
		while(buf[i-1]!=',')
			i--;
		k=0;
		while(buf[i]!=',')
		{
			mini_buf[k++]=buf[i++];
		}
		mini_buf[k]='\0';
		fprintf(fout,"%s ",mini_buf);
		fprintf(fout,"\n%s\n",out);
	}
fclose(fp);
fclose(fout);
return  0;
}
