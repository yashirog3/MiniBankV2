#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include "../Event/createaccountevent.h"
#include "../Event/depositeaccountevent.h"
#include "../Event/withdrawaccountevent.h"
#include "../Handler/eventlistener.h"
#include "iaccount.h"

class Account : public IAccount
{
    private:

        int AccountId = 0;
        int ClientId = 0;
        double AccountMoney = 0;
        int OldVersion = 0;
        int NewVersion = 0;
        std::vector<Event *> AllEvents;

        void Update(Event * ev);
        void Persist(IDaoAccount * DaoAc);

    public:
        Account() {}; 
};

#endif
