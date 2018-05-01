#ifndef EVENT_H_
#define EVENT_H_

enum TypeEvent {

    CREATE,
    DEPOSITE,
    WITHDRAW

};

class Event{

    protected:

        int Version = 0;
        double Money = 0.0;
        int EventType = -1;

    public:
        virtual int getVersion() { return Version; }
        virtual double getMoney() { return Money; }
        virtual int getEventType()  { return EventType; }
        virtual void setVersion(int Version) = 0;
        virtual ~Event() {};
};

#endif
