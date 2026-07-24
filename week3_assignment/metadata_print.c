#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Retrieve file attributes
    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    // Determine file type
    char *fileType;
    if (S_ISREG(fileStat.st_mode))
        fileType = "Regular File";
    else if (S_ISDIR(fileStat.st_mode))
        fileType = "Directory";
    else if (S_ISCHR(fileStat.st_mode))
        fileType = "Character Device";
    else if (S_ISBLK(fileStat.st_mode))
        fileType = "Block Device";
    else if (S_ISFIFO(fileStat.st_mode))
        fileType = "FIFO (Pipe)";
    else if (S_ISLNK(fileStat.st_mode))
        fileType = "Symbolic Link";
    else if (S_ISSOCK(fileStat.st_mode))
        fileType = "Socket";
    else
        fileType = "Unknown";

    // Print attributes
    printf("=== File Attributes for: %s ===\n", argv[1]);
    printf("File Type:            %s\n", fileType);
    printf("Permissions:          %04o\n", fileStat.st_mode & 0777);
    printf("File Size:            %lld bytes\n", (long long)fileStat.st_size);
    printf("Hard Links Count:     %lu\n", (unsigned long)fileStat.st_nlink);
    printf("Owner (UID):          %u\n", fileStat.st_uid);
    printf("Group (GID):          %u\n", fileStat.st_gid);

    printf("Last Access Time:     %s", ctime(&fileStat.st_atime));
    printf("Last Modification:    %s", ctime(&fileStat.st_mtime));
    printf("Status Change Time:   %s", ctime(&fileStat.st_ctime));

    return EXIT_SUCCESS;
}
