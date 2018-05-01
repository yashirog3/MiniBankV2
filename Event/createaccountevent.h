#ifndef CREATEACCOUNTEVENT_H_
#define CREATEACCOUNTEVENT_H_
#include "event.h"

class CreateAccountEvent : public Event{
    public:
        CreateAccountEvent()
        {
            this->Version = 0;
            this->Money = 0.0;
            this->EventType = CREATE;
        };

        CreateAccountEvent(int Version)
        {
            this->EventType = CREATE;
            this->Version = Version;

        }

        void setVersion(int Version) { this->Version = Version;}
};

#endif
