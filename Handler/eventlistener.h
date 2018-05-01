#ifndef EVENTLISTENER_H_
#define EVENTLISTENER_H_
#include "../Event/event.h"
#include "../Dao/idaoaccount.h"

class EventListener{

    public:
        virtual ~EventListener() {};
        virtual void Update(Event * ev) = 0;
        virtual void Persist(IDaoAccount * DaoAc) = 0;
};

#endif //EVENTLISTENER_H_
