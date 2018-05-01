#include "account.h"

void Account::Update(Event * ev)
{

    if((ev->getEventType() == WITHDRAW) && (AccountMoney - ev->getMoney() < 0))
    {
            std::cout << "You can not withdraw this value! Max Is " << AccountMoney << std::endl;
            return;
    }

    ev->setVersion(++NewVersion);
    switch(ev->getEventType())
    {
        case DEPOSITE:
            AccountMoney += ev->getMoney();
            break;
        case WITHDRAW:
            AccountMoney -= ev->getMoney();
            break;
        default:
            break;
    }
    std::cout << NewVersion << std::endl << AccountMoney << std::endl;
    AllEvents.push_back(ev);
}

void Account::Persist(IDaoAccount * DaoAc)
{
    if(DaoAc->Persist(ClientId, AccountId, &AllEvents, OldVersion))
    {
        AllEvents.clear();
        OldVersion = NewVersion;
    }
    else
    {
        std::cout << "An Error Occurred. Please, try again." << std::endl;
    }
}
