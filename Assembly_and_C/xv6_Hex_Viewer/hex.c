#include "types.h"
#include "stat.h"
#include "user.h"

char buf[16];

void
cat(int fd)
{  
  int n;
  int lineNum = 0;
  
  while((n = read(fd, buf, sizeof(buf))) > 0) { //read() attempts to read up to sizeof(buf) bytes, from fd, into the buffer - starting at buf.
      //On success, the number of bytes read is returned (zero indicates end of file),  and the file position is advanced by this number.  It is not an error if this number is smaller than the  number  of  bytes  requested;

    // if (write(1, buf, n) != n) { 
    //   printf(1, "cat: write error\n");
    //   exit();
    // }
      printf(1, "%x\t:", lineNum); //keep track of filenum in hex

      for (int i = 0; i < n; i++)
      {
        if (buf[i] <= 10) //if the hex value is less than 10, put 0 before
        {
          printf(1, "0");
        }
        printf(1, "%x ", buf[i]); //print each hex byte
      }
      printf(1, "\n"); //Newline
      lineNum += 16;
  }



  if(n < 0){
    printf(1, "hex: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[]) //argc=filename-length, argv=filename-charArray
{
  int fd, i;

  if(argc <= 1){ //if filename is not provided, exit. 
    cat(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){ //Checks if filename exists and returns fd - fd stands for 'file descriptor' - which points to the file and this variable is used by other system calls such as read() and write(). If fd is negative, it failed. 
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    cat(fd); //if it exists then send fd to cat
    close(fd); //remember to close
  }
  exit();
}
