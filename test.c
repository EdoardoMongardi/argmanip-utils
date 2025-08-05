#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("one");
    fflush(stdout); 

    pid_t pid = fork(); 

    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        execl("/bin/echo", "echo", "two", NULL);
        perror("execl failed");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("three");
        fflush(stdout);
    }

    return 0;
}