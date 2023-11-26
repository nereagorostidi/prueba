#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main (int argc, char* argv[]){

    int fd[2];
    pipe(fd);
    int pid=fork();


    if(pid==0){
        close(1);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        printf("Soy el hijo");
        execl("/bin/ls", "ls", "-al", NULL);
        printf("Hola");
    }

    else{
        close(0);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        printf("Soy el padre");
        execlp("grep", "grep", "hijo", NULL);

    }







}
