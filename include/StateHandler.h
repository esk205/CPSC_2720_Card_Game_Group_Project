#ifndef STATEHANDLER_H
#define STATEHANDLER_H

class StateHandler
{
    /**
    * @brief Virtual Interface for states
    */
public:
    /**
    * @brief constuctor
    */
    StateHandler() {}

    /**
    * @brief deconstructor
    */
    virtual ~StateHandler() {}

    /**
    * @brief Pure Virtual method
    **/
    virtual void handle() = 0;
protected:
private:
};

#endif // STATEHANDLER_H
