#ifndef WITHDRAWACCOUNTEVENT_H_
#define WITHDRAWACCOUNTEVENT_H_
#include "event.h"

class WithdrawAccountEvent : public Event{
        int Version = 0;
        double Money = 0.0;
        int EventType = WITHDRAW;

    public:

        int getVersion() { return Version; }
        double getMoney() { return Money; }
        int getEventType() { return EventType; }

        WithdrawAccountEvent(double Money)
        {
            this->Version = 0;
            this->Money = Money;
            this->EventType = WITHDRAW;
        }

        WithdrawAccountEvent(int Version, double Money)
        {
            this->Version = Version;
            this->Money = Money;
            this->EventType = WITHDRAW;
        }

        void setVersion(int Version) { this->Version = Version;}
};

#endif
