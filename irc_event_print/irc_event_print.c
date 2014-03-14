#include <stdio.h>

#include "../results.h"
#include "../software_bus.h"
#include "../irc_event.h"
#include "irc_event_print.h"

results ircEventDebugPrint(int busEvent, void *busData)
{
    sayEventData * ircEvent = busData;
    printf("ircEventDebugPrint [from: %s] [reply-with: %s] [where: %s] [reply-to: %s] %s", ircEvent->user, ircEvent->command, ircEvent->where, ircEvent->target, ircEvent->message);
    return noError;
}

