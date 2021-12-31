#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct stat st;
	
	DIR *d;
	struct dirent *entry;
	char s[100];
	int size = 0;
	
	if (argv[1] == NULL) {
		printf("Please enter a directory to scan\n");
		fgets(s, sizeof(s), stdin);
		
		if (s[strlen(s) - 1] == '\n') {
			s[strlen(s) - 1] = '\0';
		}
		
		d = opendir(s);
		
		if (d == NULL) {
			printf("Error: %s\n", strerror(errno));
			return(1);
		}
		
		printf("Directories:\n");
		while (entry = readdir(d)) {
			if (entry->d_type == 4) {
				printf("\t%s\n", entry->d_name);
			}
		}
		
		d = opendir(s);
		stat(entry->d_name, &st);
		printf("Regular files:\n");
		while (entry = readdir(d)) {
			if (entry->d_type == 8) {
				size += st.st_size;
				printf("\t%s\n", entry->d_name);
			}
		}

		closedir(d);
	} else {
		d = opendir(argv[1]);
		
		if (d == NULL) {
			printf("Error: %s\n", strerror(errno));
			return(1);
		}
		
		printf("Directories:\n");
		while (entry = readdir(d)) {
			if (entry->d_type == 4) {
				printf("\t%s\n", entry->d_name);
			}
		}
		
		d = opendir(argv[1]);
		printf("Regular files:\n");
		while (entry = readdir(d)) {
			if (entry->d_type == 8) {
				size += st.st_size;
				printf("\t%s\n", entry->d_name);
			}
		}

		closedir(d);
	}
	
	printf("Total Directory Size: %d\n", size);
	
	return(0);
	
}
