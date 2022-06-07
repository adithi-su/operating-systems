// understanding process APIs - fork() system call 

/* 
Fork system call is used for creating a new process, which is called child process, 
which runs concurrently with the process that makes the fork() call (parent process).
After a new child process is created, both processes will execute the next instruction following the fork() system call. 
A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.

It takes no parameters and returns an integer value.

Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int agrc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if(rc<0){
        //fork failed, exit
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc==0) {
       //child, new process 
       printf("hello, this is the child process (pid:%d)\n", (int)getpid());
    }
    else {
        printf("hello, this is the parent of %d (pid:%d)\n", rc,(int)getpid());
    }
    return 0;
}

/* sample output:
hello world (pid:45576)
hello, this is the parent of 45577 (pid:45576)
hello, this is the child process (pid:45577)
*/ 