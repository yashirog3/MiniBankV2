#include "daoaccount.h"

ClientAccounts * DaoAccount::getClient(int ClientId)
{
    for(Repository::const_iterator it = AllClients.begin(); it != AllClients.end(); ++it)
    {
        if(std::get<0>(**it) == ClientId)
        {
            return(*it);
        }
    }

    return nullptr;
}

ClientAccount * DaoAccount::getClientAccount(int ClientId, int AccountId)
{
    //Get Client
    ClientAccounts * ClientRepository = getClient(ClientId);
    if(ClientRepository != nullptr)
    {
        //Get Account
        for(std::vector<ClientAccount*>::const_iterator it = std::get<1>(*ClientRepository)->begin(); it !=  std::get<1>(*ClientRepository)->end(); ++it)
        {
            if(std::get<0>(**it) == AccountId)
            {
                return (*it);
            }
        }
    }

    return nullptr;
}

bool DaoAccount::CheckCollision(int ClientId, int AccountId, int Version)
{
    ClientAccount * MyAccount = getClientAccount(ClientId, AccountId);
    if(MyAccount != nullptr)
    {
        for(Events::const_iterator it = std::get<1>(*MyAccount)->begin(); it != std::get<1>(*MyAccount)->end(); ++it)
        {
            if((*it)->getVersion() >= Version)
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool DaoAccount::Persist(int ClientId, int AccountId, Events * AllEvents, int Version)
{
    try
    {
        //Try to get the correspondent account
        ClientAccount * Aux = getClientAccount(ClientId, AccountId);
        if(Aux != nullptr){
            //Check Version
            if(!CheckCollision(ClientId, AccountId, Version+1))
            {
                throw collision;
            }
            for(Events::const_iterator it = AllEvents->begin(); it != AllEvents->end(); ++it)
            {                        

                std::get<1>(*Aux)->push_back(*it);
            }

            return true;
        }
        else
        {
            ClientAccounts * MyAccounts = getClient(ClientId);
            //Create Account
            if(MyAccounts != nullptr)
            {
                Events * MyEvents = new Events();
                for(Events::const_iterator it = AllEvents->begin(); it != AllEvents->end(); ++it)
                {
                    MyEvents->push_back(*it);
                }
                std::get<1>(*MyAccounts)->push_back(new ClientAccount(AccountId, MyEvents));
            }
            else
            {
                //Create a new client repository
                std::vector<ClientAccount *> * Accounts = new std::vector<ClientAccount *>();
                Events * MyEvents = new Events();
                for(Events::const_iterator it = AllEvents->begin(); it != AllEvents->end(); ++it)
                {
                    MyEvents->push_back(*it);
                }

                Accounts->push_back(new ClientAccount(AccountId, MyEvents));
                AllClients.push_back(new ClientAccounts(ClientId, Accounts));
            }

            return true;
        }

    }
    catch(CollisionDetection &e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    return false;
}
