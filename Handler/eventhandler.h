#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include <vector>
#include <algorithm>
#include <iostream>
#include "eventlistener.h"
#include "../Event/event.h"
#include "../Dao/idaoaccount.h"

class EventHandler{

    private:
        std::vector<EventListener *> EventListeners;
    public:
        void Attach(EventListener * listener);
        void Dettach(EventListener * listener);
        void Notify(EventListener * listener, Event * Event);
        void Persist(EventListener * listener, IDaoAccount * Dao);
};

#endif
