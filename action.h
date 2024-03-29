#ifndef ACTION_H
#define ACTION_H

#include <string>

enum Actions
{
    None,
    Build,
    Train,
    Attack
};


class Action
{
    static const char* _action_string[];
public:
    Action();
    static const char* ToString(Actions action);
    static int ToAction(const char* actionString);
};

#endif // ACTION_H
