#include "Event/createaccountevent.h"
#include "Event/depositeaccountevent.h"
#include "Event/withdrawaccountevent.h"
#include "Handler/eventhandler.h"
#include "Dao/eventrepository.h"
#include "Model/account.h"
#include "command.h"

using namespace std;

int main(int argc, char ** argv)
{

    EventRepository Repository;
    Account Ac, Ad;
    Command AcCommands(&Ac);
    Command AdCommands(&Ad);

    AcCommands.DoCreate(new CreateAccountEvent());
    AdCommands.DoCreate(new CreateAccountEvent());


    AdCommands.DoDeposite(new DepositeAccountEvent(100.0));
    AdCommands.DoDeposite(new DepositeAccountEvent(3.40));
    AdCommands.DoDeposite(new DepositeAccountEvent(1.50));
    AdCommands.DoDeposite(new DepositeAccountEvent(40.0));

    AdCommands.DoPersist(&Repository);

    AcCommands.DoDeposite(new DepositeAccountEvent(100.0));
    AcCommands.DoPersist(&Repository);

    AcCommands.DoWithdraw(new WithdrawAccountEvent(50.20));
    AcCommands.DoPersist(&Repository);

    AcCommands.DoWithdraw(new WithdrawAccountEvent(40.10));
    AcCommands.DoDeposite(new DepositeAccountEvent(30.50));
    AcCommands.DoDeposite(new DepositeAccountEvent(3.70));
    AcCommands.DoPersist(&Repository);

    return 0;
}
