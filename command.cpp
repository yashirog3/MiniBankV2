#include "command.h"

void Command::DoCreate(CreateAccountEvent * AcEvent)
{
    Handler.Attach(Ac);
    Handler.Notify(Ac, AcEvent);
}

void Command::DoDeposite(DepositeAccountEvent * AcEvent)
{
    Handler.Attach(Ac);
    Handler.Notify(Ac, AcEvent);
}

void Command::DoWithdraw(WithdrawAccountEvent * AcEvent)
{
    Handler.Attach(Ac);
    Handler.Notify(Ac, AcEvent);
}

void Command::DoPersist(IDaoAccount * DaoAc)
{
    Handler.Attach(Ac);
    Handler.Persist(Ac, DaoAc);
}
