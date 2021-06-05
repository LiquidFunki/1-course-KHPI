#inlcude "lib.h"

void show_tree(char * directory_path, int tab){
    DIR * folder;
    struct dirent * entry;

    folder = opendir(directory_path);
    if (folder != NULL)
    {
        while ((entry = readdir(folder)))
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                printf(" |");
                printf("%*c", tab, "\t");
                printf(">---");
                printf("%s\n", entry->d_name);
                char *subdirectory_name = malloc((strlen(directory_path) + 1 + strlen(entry->d_name)) * sizeof(char));
                strcpy(subdirectory_name, directory_path);
                strcat(subdirectory_name, "/");
                strcat(subdirectory_name, entry->d_name);
                show_tree(subdirectory_name, tab + 1);
                free(subdirectory_name);
            }
        }
    }
    closedir(folder);
}

void put_directory_size_on_console(){
    char * directory_path =  malloc(256 * sizeof(char));
    printf("%s\n", "Enter directory name:");
    scanf("%s", directory_path);

    float directory_size = calculate_directory_size(directory_path); //double
    directory_size /= 1024.0;

    printf("%s %s: %3.2f%s\n", "Size of directory", directory_path, directory_size, " KB ");

    free(directory_path);
}

float calculate_directory_size(char * directory_path){

    float directory_size = 0.0;

    DIR * folder;
    struct dirent * entry;

    folder = opendir(directory_path);
    if (folder == NULL){
        FILE * file;
        file = fopen(directory_path, "r");

        if (file != NULL){
            directory_size += (float)calculate_file_size(file);
            fclose(file);
        }
    }
    else{
        while ((entry = readdir(folder))){

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                char * subdirectory_name = malloc((strlen(directory_path) + 1 + strlen(entry->d_name)) * sizeof(char));

                strcpy(subdirectory_name, directory_path);
                strcat(subdirectory_name, "/");
                strcat(subdirectory_name, entry->d_name);

                directory_size += calculate_directory_size(subdirectory_name);
                free(subdirectory_name);
            }
        }
    }
    closedir(folder);

    return directory_size;
}

int calculate_file_size(FILE * file){    //long int ?

    int check_point = ftell(file);
    fseek(file, 0L, SEEK_END);

    int file_size = ftell(file);
    fseek(file, check_point, SEEK_SET);

    return file_size;
}

void get_data_from_file(char *name, char *data, int size){
    FILE * f1 = fopen(name, "rt");
    if (f1 == NULL){
        puts("Error");
    }
    fgets(data, size, f1);
    fclose(f1);
}

void put_data_to_file(char *name, char * result){
    FILE * f2 = fopen(name, "wt");
    if (f2 == NULL){
        puts("Error");
    }
    for(int i = 0; i < strlen(result); i++) {
        fprintf(f2, "%c", *(result + i));
    }
    fclose(f2);
}

int individual_task(){

    char * entering_text = malloc(256 * sizeof(char));
    puts("Enter the name of your file with input data:");
    scanf("%s", entering_text);

    char * data_file = malloc(256 * sizeof(char));
    get_data_from_file(entering_text, data_file, 256);

    //char text[] = "quick youth is a free ticket to hell";

    char original_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char cesar_alphabet[] = "cdefghijklmnopqrstuvwxyzab";
    for ( size_t i = 0; i < strlen(data_file) - 1; i++ ){
        for ( size_t j = 0; j < strlen(original_alphabet) - 1; j++ ){
            if ( *(data_file + i) == cesar_alphabet[j] ){
                *(data_file + i) = original_alphabet[j];
            }
        }
    }

    char *result_data = malloc(256 * sizeof(char));
    puts("Enter the name of your file with input data:");
    scanf("%s", result_data);
    put_data_to_file(result_data, data_file);
    free(entering_text);
    free(data_file);
    free(result_data);
    return 0;
}