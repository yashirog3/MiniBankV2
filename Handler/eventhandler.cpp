#include "eventhandler.h"

void EventHandler::Attach(EventListener * listener)
{
    if(EventListeners.end() != std::find(EventListeners.begin(), EventListeners.end(), listener))
        return;
    EventListeners.push_back(listener);
    std::cout << "Handler Attached" << std::endl;
};

void EventHandler::Dettach(EventListener * listener)
{
    EventListeners.erase(std::remove(EventListeners.begin(), EventListeners.end(), listener), EventListeners.end());
};

void EventHandler::Notify(EventListener * listener, Event * Event){
    for(std::vector<EventListener *>::const_iterator it = EventListeners.begin(); it != EventListeners.end(); ++it)
    {
        if(*it == listener)
        {
            (*it)->Update(Event);
        }
    }
};

void EventHandler::Persist(EventListener * listener, IDaoAccount * Dao){
    for(std::vector<EventListener *>::const_iterator it = EventListeners.begin(); it != EventListeners.end(); ++it)
    {
        if(*it == listener)
        {
            (*it)->Persist(Dao);
        }
    }
};
