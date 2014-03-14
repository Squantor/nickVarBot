#ifndef __SOFTWARE_BUS_H_
#define __SOFTWARE_BUS_H_

#include "results.h"

// max amount of handlers per software bus
#define     MAXSWBUSHANDLERS   16

// bus handler
typedef results (*softwareBusHandler) (int busEvent, void *busData);

// bus state
typedef struct {
    softwareBusHandler handlers[MAXSWBUSHANDLERS];
} softwareBusState;

// subscribe
results softwareBusSubscribe(softwareBusState *swBus, softwareBusHandler handler);

// unsubscribe
results softwareBusUnsubscribe(softwareBusState *swBus, softwareBusHandler handler);

// post event
results softwareBusPost(softwareBusState *swBus, int busEvent, void *busData);

#endif

