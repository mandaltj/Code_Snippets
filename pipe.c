#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    //This array has two file descriptors
    //fd*[0] is the read end of the pipe
    //fd*[1] is the write end of the pipe
    int fd1[2];
    int fd2[2];

    //"arr_list" is a pointer to an array containing 5 integers
    //The size of the array is of 20 bytes
    int *arr_list = (int *) malloc(5*sizeof(int));
    arr_list[0] = 0;
    arr_list[1] = 1;
    arr_list[2] = 2;
    arr_list[3] = 3;
    arr_list[4] = 4;
    //Type cast to a pointer to char type
    char *buf = (char *) arr_list;

    if (pipe(fd1) == -1){
        fprintf(stderr, "Pipe Error\n");
        exit(EXIT_FAILURE);
    }
    if (pipe(fd2) == -1){
        fprintf(stderr, "Pipe Error\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();

    if (pid == -1){
        fprintf(stderr, "Child create Error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0){
        // //Child Process
        fprintf(stdout, "Child Process\n");
        char *temp_buffer = (char *) malloc(5*sizeof(int));
        read(fd1[0], temp_buffer, 20);
        int *int_buf = (int *) temp_buffer;
        for (int i=0; i<5; i++){
            int_buf[i] += 1;
        }

        temp_buffer = (char *) int_buf;
        write(fd2[1], temp_buffer, 20);
        close(fd2[0]);
        close(fd2[1]);

        free(temp_buffer);

    }
    else{
        // //Parent Process
        fprintf(stdout, "Parent Process\n");
        write(fd1[1], buf, 20);
        close(fd1[0]);
        close(fd1[1]);
        //fprintf(stdout, "Passed x to child process\n");
        wait(NULL);


        fprintf(stdout, "Reading in Parent\n");
        read(fd2[0], buf, 20);
        arr_list = (int *) buf;
        for(int i = 0; i<5; i++){
            arr_list[i];
            fprintf(stdout, "int_buf[%d]: %d\n", i, arr_list[i]);
        }
        free(arr_list);
    }
    exit(EXIT_SUCCESS);
}

int main()
{
    int pid, pid1, pid2;

    // variable pid will store the
    // value returned from fork() system call
    pid = fork();

    // If fork() returns zero then it
    // means it is child process.
    if (pid == 0) {

        // First child needs to be printed
        // later hence this process is made
        // to sleep for 3 seconds.
        sleep(3);

        // This is first child process
        // getpid() gives the process
        // id and getppid() gives the
        // parent id of that process.
        printf("child[1] --> pid = %d and ppid = %d\n",
               getpid(), getppid());
    }

    else {
        //wait(NULL);
        pid1 = fork();
        if (pid1 == 0) {
            sleep(2);
            printf("child[2] --> pid = %d and ppid = %d\n",
                   getpid(), getppid());
        }
        else {
            //wait(NULL);
            pid2 = fork();
            if (pid2 == 0) {
                sleep(1);
                // This is third child which is
                // needed to be printed first.
                printf("child[3] --> pid = %d and ppid = %d\n",
                       getpid(), getppid());
            }

            // If value returned from fork()
            // in not zero and >0 that means
            // this is parent process.
            else {
                // This is asked to be printed at last
                // hence made to sleep for 3 seconds.
                //wait(NULL);
                sleep(4);
                printf("parent --> pid = %d\n", getpid());
            }
        }
    }

    return 0;
}
