
#include "target_systemc.h"

target_systemc::target_systemc(sc_core::sc_module_name name)
{
    tsocket.register_b_transport(this, &target_systemc::b_transport);
}

void target_systemc::b_transport( tlm::tlm_generic_payload& gp, sc_core::sc_time& delay) {
    printf("received transaction from QEMU \\o/\n");
}
