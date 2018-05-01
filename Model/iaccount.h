#ifndef IACCOUNT_H_
#define IACCOUNT_H_

#include "../Handler/eventhandler.h"
#include "../Dao/idaoaccount.h"


class IAccount : public EventListener
{
    private:

       virtual void Update(Event * AcEvent) = 0;
       virtual void Persist(IDaoAccount * DaoAc) = 0;

    public:

       virtual ~IAccount() { };

};


#endif
