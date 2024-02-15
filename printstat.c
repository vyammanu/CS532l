#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void printstat(struct stat statbuf);

int main(int argc, char **argv) {
    int i;
    struct stat buf;
    char *ptr;
    
    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            printf("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if (S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "** unknown mode **";
        printf("%s\n", ptr);
    }
    printstat(buf);
    exit(0);
}

void printstat(struct stat statbuf) {
    printf("File type: ");
    if (S_ISREG(statbuf.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(statbuf.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(statbuf.st_mode))
        printf("Character special file\n");
    else if (S_ISBLK(statbuf.st_mode))
        printf("Block special file\n");
    else if (S_ISFIFO(statbuf.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISLNK(statbuf.st_mode))
        printf("Symbolic link\n");
    else if (S_ISSOCK(statbuf.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");
}
