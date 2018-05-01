#ifndef DEPOSITEACCOUNTEVENT_H_
#define DEPOSITEACCOUNTEVENT_H_
#include "event.h"

class DepositeAccountEvent : public Event{
    public:

        DepositeAccountEvent(double Money)
        {
            this->Version = 0;
            this->Money = Money;
            this->EventType = DEPOSITE;
        }

        DepositeAccountEvent(int Version, double Money)
        {
            this->Version = Version;
            this->Money = Money;
            this->EventType = DEPOSITE;
        }

        void setVersion(int Version) { this->Version = Version;}

};

#endif
