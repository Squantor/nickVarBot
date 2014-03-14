#include <stdlib.h>

#include "software_bus.h"
#include "results.h"



results softwareBusSubscribe(softwareBusState *swBus, softwareBusHandler handler)
{
    int i;
    for(i = 0; i < MAXSWBUSHANDLERS; i++)
    {
        if(swBus->handlers[i] == NULL)
        {
            swBus->handlers[i] = handler;
            return noError;
        }
    }
    return full;

}


results softwareBusUnsubscribe(softwareBusState *swBus, softwareBusHandler handler)
{
    int i;
    for(i = 0; i < MAXSWBUSHANDLERS; i++)
    {
        if(swBus->handlers[i] == handler)
        {
            swBus->handlers[i] = NULL;
            return noError;
        }
    }
    return notFound;
}


results softwareBusPost(softwareBusState *swBus, int busEvent, void *busData)
{
    int i;
    for(i = 0; i < MAXSWBUSHANDLERS; i++)
    {
        if(swBus->handlers[i] != NULL)
        {
            swBus->handlers[i](busEvent, busData);
        }
    }
    return noError;
}
