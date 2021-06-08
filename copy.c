#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv){
	int fd_in,fd_out;
	int read_size;
	char buf[2048];

	fd_in=open(argv[1],O_RDONLY);
	fd_out=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,00600);

	if(fd_in==-1){
		return 0;
	}
	if(fd_out==-1){
		return 0;
	}
	while(1){
		read_size=read(fd_in,buf,1024);
		if(read_size<=0) break;
		write(fd_out,buf,read_size);
	}
	close(fd_in);
	close(fd_out);
}
