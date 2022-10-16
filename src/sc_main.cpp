
#include "top.h"

int sc_main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("ERROR: machine path required\n");
        exit(1);
    }
    std::string machine_path = std::string("unix:")
                             + std::string(argv[1])
                             + std::string("/qemu-rport-_machine_cosim");

    top myTop("top", machine_path);
    sc_start();
    return 0;
}
