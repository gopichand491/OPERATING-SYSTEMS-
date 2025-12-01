// Experiment 2: Copy file using system calls in C++
#include <iostream>
#include <fcntl.h>   // open
#include <unistd.h>  // read, write, close
#include <stdlib.h>  // exit

using namespace std;

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t nread;
    char buffer[1024];

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <source_file> <destination_file>" << endl;
        return 1;
    }

    // Open source file in read-only mode
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Open or create destination file in write-only mode
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        return 1;
    }

    // Read from source and write to destination
    while ((nread = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (nread < 0) {
        perror("Error reading from source file");
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    close(src_fd);
    close(dest_fd);

    cout << "File copied successfully." << endl;
    return 0;
}

