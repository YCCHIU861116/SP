#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
int main(void)
{
	/*int fd = open("b",O_WRONLY|O_TRUNC);
	if(fd == -1)
		fprintf(stderr,"error\n");
	else
		close(fd);*/
	/*char slide[100] = "a/b/c/d/e";
	slide[strrchr(slide,'/')-slide] = '\0';
	printf("%s\n",slide);
	slide[strlen(slide)] = '/';
	printf("%s\n",slide);*/
	//symlink("test.c","symlinktest");
	unlink("symlinktest");
	symlink("test.c","symlinktest");
	return 0;
}
