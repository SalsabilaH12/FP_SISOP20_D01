#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"
#include "file.h"

int
main(int argc, char *argv[])
{
	  if(argc < 2){
	    printf(2, "Usage: tree [path]...\n");
	    exit();
	  }
	  tree(argv[1]);

	  /**
	  int fd = open(argv[1],O_RDONLY);
	  if(fd<0)
		  return -1;
		  **/
	 // struct dirent dir;
	  /**
	  while(read(fd,&dir,sizeof(dir))!=0){
		  printf(1,"|_ %d,%d",dir.name,dir.inum);
		  //struct stat *st;
		  struct inode ip;
		  ip= getinode(dir.inum);
		  if(ip.type==T_DIR){
			  int i;
			  for(i=0;i<NDIRECT;i++ ){
				  uint add=ip.addrs[i];
				  printf(1,"%d",add);
			  }
		  }
	  }
	  **/
  return 0;
}
