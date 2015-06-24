#ifndef ACTION_H
#define ACTION_H

enum Actions
{
    None,
    Build,
    Train,
    Attack
};


class Action
{
    static char* _action_string[];
public:
    Action();
    static char* ToString(Actions action);
};

#endif // ACTION_H
