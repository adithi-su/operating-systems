// understanding process APIs - fork() system call 
// program 2 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int agrc, char *argv[]){
fork();
fork();
fork();
printf("hello, I'm process %d (pid)\n", (int) getpid());
return 0;
}

/* sample output -
hello, I'm process 45624 (pid)
hello, I'm process 45627 (pid)                                                  
hello, I'm process 45626 (pid)
hello, I'm process 45625 (pid)
hello, I'm process 45629 (pid)
hello, I'm process 45628 (pid)
hello, I'm process 45630 (pid)
*/ 

// Total Number of Processes = 2^n, where n is number of fork system calls.
// tree heirarchy - 
/*
The main process: P0
Processes created by the 1st fork: P1
Processes created by the 2nd fork: P2, P3
Processes created by the 3rd fork: P4, P5, P6, P7

             P0
         /   |   \
       P1    P4   P2
      /  \          \
    P3    P6         P5
   /
 P7

 */