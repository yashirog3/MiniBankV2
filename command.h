#ifndef COMMAND_H_
#define COMMAND_H_
#include "Handler/eventhandler.h"
#include "Dao/idaoaccount.h"
#include "icommand.h"

class Command : public ICommand{

        EventHandler Handler;
        Account * Ac;

    public:

        Command(Account * Ac) : Ac(Ac) {};
        void DoCreate(CreateAccountEvent * AcEvent);
        void DoDeposite(DepositeAccountEvent * AcEvent);
        void DoWithdraw(WithdrawAccountEvent * AcEvent);
        void DoPersist(IDaoAccount * DaoAc);
};

#endif // COMMAND_H_
