#include "../Header Files/SaveManagement.h"



int saveDirectoryAvailable(const char* directoryPath) {
    DIR* directory = opendir(directoryPath);

    if (directory == NULL) {
        printf("Error: Unable to open directory '%s'.\n", directoryPath);
        return 0;
    }

    struct dirent* entry;

    int saveFileFound = 0;

    // Klasördeki dosyaları tarayın

    while ((entry = readdir(directory)) != NULL) {
        // Sadece .txt uzantılı dosyaları kontrol edin
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
            saveFileFound = 1; // En az bir dosya bulunduğunu işaretleyin

    }
    enterToGo();
    closedir(directory); // Klasörü kapat
    return saveFileFound;
}
