
#include "top.h"

top::top(sc_core::sc_module_name name, std::string machine_path)
    : sc_core::sc_module(name)
    , qemu("qemu", machine_path.c_str(), nullptr)
{
    qemu.isocket->bind(tSystemC.tsocket);
    qemu.rst.bind(reset);

    SC_THREAD(pull_reset);
}

void top::pull_reset()
{
    reset.write(true);
    wait(1, SC_US);
    reset.write(false);
}