
#include "tlm_utils/simple_target_socket.h"

class target_systemc
    : public sc_core::sc_module
{
public:
    tlm_utils::simple_target_socket<target_systemc> tsocket{"tsocket"};
    target_systemc(sc_core::sc_module_name name);

private:
    void b_transport( tlm::tlm_generic_payload& gp, sc_core::sc_time& delay);
};
