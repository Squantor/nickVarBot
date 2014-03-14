#ifndef __IRC_EVENT_H__
#define __IRC_EVENT_H__

enum {
    ircSay,
} ircEventType;

typedef struct
{
    char *user;
    char *command;
    char *where;
    char *target;
    char *message;
} sayEventData;

#endif
