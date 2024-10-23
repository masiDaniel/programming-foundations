

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <linux/limits.h>

void search(const char *path){
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char full_path[PATH_MAX];

    if ((dir = opendir(path)) == NULL){
        perror("opendir\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL){
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name,".") == 0)
            continue;
        
        
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (lstat(full_path, &info) == -1){
            perror("istat");
            continue;
        }
        if (S_ISLNK(info.st_mode)) {
            printf("Skipping symbolic link: %s\n", full_path);
            continue;
        }
        if (S_ISDIR(info.st_mode)){
              // If it's a directory, recursively search it
            search(full_path);
        }else if (S_ISREG(info.st_mode)) {
            printf("%s\n", full_path);
        }
        
        else {
            printf("Skipping special file: %s\n", full_path);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start the search from the specified directory
    search(argv[1]);

    return EXIT_SUCCESS;
}