
#include "qemu_cosim.h"

qemu_cosim::qemu_cosim(sc_module_name name, const char *sk_descr, Iremoteport_tlm_sync *sync)
    : remoteport_tlm(name, -1, sk_descr, sync)
    , rp_m("rp_m")
    , isocket(&rp_m.sk)
{
    register_dev(9, &rp_m);
}
