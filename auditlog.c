#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FILE_NAME "audit.log"
#define BUFFER_SIZE 1

int main(int argc, char *argv[]){
	int fd;

	if(argc < 2){
		printf("Usage:\n");
		printf("./auditlog --add \"message\"\n");
		printf("./auditlog --view\n");
		return 1;
	}

	if(strcmp(argv[1],"--add") == 0 ){
		if(argc != 3){
			printf("Please provide text to add");
			return 1;
		}

		fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);

		write(fd, argv[2], strlen(argv[2]));
		write(fd, "\n", 1);

		close(fd);
		printf("Added!");
	}

	else if (strcmp(argv[1], "--view") == 0){
		fd = open(FILE_NAME, O_RDONLY);
		char ch;
		int line = 1;

		printf("%d: ", line);

		while(read(fd, &ch, 1) > 0){
		
			printf("%c", ch);

			if(ch == '\n'){
				line++;

				if(read(fd, &ch, 1) > 0){
					printf("%d: ", line);
					printf("%c", ch);
				}
			
				else{
					break;
				}
			}
		}

		close(fd);
	}

	return 0;
}
