#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER margo

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./margo-lttng-tp.h"

#if !defined(_HELLO_TP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _HELLO_TP_H

#include <lttng/tracepoint.h>

/*
LTTNG_TRACEPOINT_ENUM(
    margo_monitor_fn,
    TP_ENUM_VALUES(
        ctf_enum_value("START", MARGO_MONITOR_FN_START)
        ctf_enum_value("END",   MARGO_MONITOR_FN_END)
        ctf_enum_value("POINT", MARGO_MONITOR_POINT)
    )
)
*/

LTTNG_UST_TRACEPOINT_EVENT(
    margo, 
    progress,
    LTTNG_UST_TP_ARGS(
        uint8_t, sep
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer_hex(uint8_t, sep, sep)
    )
)

LTTNG_UST_TRACEPOINT_EVENT(
    margo,
    register,
    LTTNG_UST_TP_ARGS(
        uint64_t, rpc_id,
        const char*, rpc_name
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer_hex(uint64_t, rpc_id, rpc_id)
        lttng_ust_field_string(rpc_name, rpc_name)
    )
)

LTTNG_UST_TRACEPOINT_EVENT_CLASS(
    margo,
    rpc_init,
    LTTNG_UST_TP_ARGS(
        uint64_t, uid,
        uint64_t, handle,
        uint64_t, rpc_id,
        const char*, address,
        uint8_t, sep
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer_hex(uint64_t, uuid, uid)
        lttng_ust_field_integer_hex(uint64_t, trace_handle, handle)
        lttng_ust_field_integer_hex(uint64_t, local_rpc, rpc_id)
        lttng_ust_field_string(to_address,address)
        lttng_ust_field_integer(uint8_t, sep, sep)
    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_init,
    margo,
    c_rpc_create,
    LTTNG_UST_TP_ARGS(
        uint64_t, uid,
        uint64_t, handle,
        uint64_t, rpc_id,
        const char*, address,
        uint8_t, sep
    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_init,
    margo,
    s_rpc_handler,
    LTTNG_UST_TP_ARGS(
        uint64_t, uid,
        uint64_t, handle,
        uint64_t, rpc_id,
        const char*, address,
        uint8_t, sep
    )
)

// IN-FLIGHT
LTTNG_UST_TRACEPOINT_EVENT_CLASS(
    margo,
    rpc_event,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer_hex(uint64_t, trace_handle, handle)
        lttng_ust_field_integer(uint8_t, sep, sep)
    )
)
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    c_rpc_forward,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    rpc_wait,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    c_rpc_forward_cb,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    s_rpc_work,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    s_rpc_ult,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    margo,
    rpc_event,
    margo,
    s_rpc_respond,
    LTTNG_UST_TP_ARGS(
        uint64_t, handle,
        uint8_t, sep
    )
)

#endif /* _HELLO_TP_H */

#include <lttng/tracepoint-event.h>


