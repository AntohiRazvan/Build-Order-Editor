#include "action.h"

char* Action::_action_string[] = {"None", "Build", "Train", "Attack"};

Action::Action()
{
}

char* Action::ToString(Actions action)
{
    return _action_string[action];
}
