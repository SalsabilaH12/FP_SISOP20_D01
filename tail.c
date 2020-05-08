#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf [1024];

void tail (int fd, char *name, int line) {
  int i, n;  
  int l=0; 
  int count = 0;

  int temp = open ("temporary", O_CREATE | O_RDWR);    
  while((n = read(fd, buf, sizeof(buf))) > 0 )
  {
    write (temp, buf, n);                             

    for(i=0;i<=n ;i++)
    {
      if(buf[i] != '\n')                              
      {
        continue;
      }
      else                                             
      {
        l++;
      }
    }
  }

  close (temp);

  if (n < 0)
  {
    printf(1, "tail: read error\n");
    exit();
  }

  temp = open ("temporary", 0);                     
  
  while((n = read(temp, buf, sizeof(buf))) > 0 )
  {
    for (i = 0; i<n; i++) 
    {
      if (count >= (l - line))          
      {
        printf(1,"%c",buf[i]);
      }
      else if (l < line)              
      {
        printf(1,"%c",buf[i]);
      }
      else if (buf[i] == '\n')        
      {
        count++;
      }
    }
  }
  close (temp);
  
  unlink("temporary");                  
}


int 
main(int argc, char *argv[]) {
  int i;
  int fd = 0;	
  int x = 10;	
  char *file;	
  char a;

  file = "";
     
  if (argc <= 1) 
  {	
    tail(0, "", 10);	
    exit();
  }

  else {
    for (i = 1; i < argc; i++) 
    {
		  a = *argv[i];	
				
      if (a == '-') 
      {            
        argv[i]++;
        x = atoi(argv[i]++);
      }
				
      else 
      {	
        if ((fd = open(argv[i], 0)) < 0) 
        {
          printf(1, "tail: cannot open %s\n", argv[i]);
          exit();
        }
      }
    }
		 
  tail(fd,file, x);
  close(fd);
  exit();    

  }
}
