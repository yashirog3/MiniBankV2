#ifndef EVENTREPOSITORY_H_
#define EVENTREPOSITORY_H_
#include <iostream>
#include "idaoaccount.h"

class EventRepository : public IDaoAccount
{
    private:

        typedef std::vector<Event *> Events;
        typedef std::pair<int /*AccountId*/, Events *> ClientAccount;
        typedef std::pair<int /*ClientId*/, std::vector<ClientAccount *> *> ClientAccounts;
        typedef std::vector<ClientAccounts *> Repository;
        Repository AllClients;

    public:

        ClientAccounts * getClient(int ClientId);
        ClientAccount * getClientAccount(int ClientId, int AccountId);
        bool CheckCollision(int ClientId, int AccountId, int Version);
        bool Persist(int ClientId, int AccountId, Events * AllEvents, int Version);
};

#endif
