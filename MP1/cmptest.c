#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 65536
void Findchr(FILE* fp,char *buf,char c){
	char *pound = NULL;
	//printf("%ld\n",ftell(fp));
	while(ftell(fp) > BUF_SIZE-1 && pound == NULL){
		fseek(fp,(1-BUF_SIZE),SEEK_CUR);
		fread(buf,sizeof(char),BUF_SIZE-1,fp);
		buf[BUF_SIZE-1] = '\0';
		pound = strrchr(buf,c);
		fseek(fp,(1-BUF_SIZE),SEEK_CUR);
	} 
	if(pound == NULL){//#1234567890
		int rest = (int)ftell(fp);//12
		fseek(fp,0,SEEK_SET);
		fread(buf,sizeof(char),rest-1,fp);
		buf[rest-1] = '\0';
		pound = strrchr(buf,c);
		fseek(fp,0,SEEK_SET);
	}
	fseek(fp,pound-buf,SEEK_CUR);
	//printf("%ld\n",ftell(fp));
	return;
} 
int main(int argc, char *argv[])
{
	char buf[BUF_SIZE];
	FILE *fp = fopen(argv[1],"r");
	fseek(fp,0,SEEK_END);
	//Findchr(fp,buf,'#');
	/*fread(buf,sizeof(char),1,fp);
	buf[1] = '\0';*/
	printf("%ld\n",ftell(fp)); 
	return 0;
}
