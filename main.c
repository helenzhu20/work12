#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <errno.h>
#include <string.h>

int main() {
    struct stat st;
    DIR *d;
    struct dirent *entry;
    char s[100];
    int size = 0;
	
    d = opendir(".");
		
    printf("Directories:\n");
    while (entry = readdir(d)) {
        if (entry->d_type == 4) {
            printf("\t%s\n", entry->d_name);
        }
    }
    
    d = opendir(".");
    stat(entry->d_name, &st);
    printf("Regular files:\n");
    while (entry = readdir(d)) {
        if (entry->d_type == 8) {
            size += st.st_size;
            printf("\t%s\n", entry->d_name);
        }
    }

    closedir(d);

    printf("Total Directory Size: %d\n", size);
    
    return(0);
	
}