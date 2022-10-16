
#include <string>
#include "systemc"

#include "qemu_cosim.h"
#include "target_systemc.h"

class top
    : sc_core::sc_module
{
public:

    top(sc_core::sc_module_name, std::string machine_path);
    SC_HAS_PROCESS(top);

private:
    qemu_cosim qemu;
    target_systemc tSystemC{"tSystemC"};
    sc_core::sc_signal<bool> reset{"reset"};

    void pull_reset();
};
