#include <unistd.h>

int main()
{
    int nread;
    char buff[20];

    nread = read(0, buff, 10); // read 10 bytes from standard input (keyboard) into buffer
    write(1, buff, nread);    // write read bytes to standard output (screen)

    return 0;
}
