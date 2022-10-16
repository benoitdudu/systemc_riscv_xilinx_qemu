#include "systemc.h"

#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

#include "remote-port-tlm.h"
#include "remote-port-tlm-memory-master.h"

class qemu_cosim
: public remoteport_tlm
{
private:
    remoteport_tlm_memory_master rp_m;

public:

    tlm_utils::simple_initiator_socket<remoteport_tlm_memory_master> *isocket;

    qemu_cosim(sc_core::sc_module_name name, const char *sk_descr,
        Iremoteport_tlm_sync *sync = NULL);
};