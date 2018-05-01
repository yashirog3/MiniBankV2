#ifndef IDAOACCOUNT_H_
#define IDAOACCOUNT_H_
#include "../Event/createaccountevent.h"
#include "../Event/depositeaccountevent.h"
#include "../Event/withdrawaccountevent.h"
#include <vector>
#include <map>
#include <iostream>

class CollideDetection : public std::exception{


    public:
        virtual const char * what() const throw(){

            return "We Detect an Inconsistence on your account. You Must Login again to change your account";

        }
}collide;

class IDaoAccount{

    public:      

        typedef std::vector<Event *> Events;
        typedef std::pair<int /*AccountId*/, Events *> ClientAccount;
        typedef std::pair<int /*ClientId*/, std::vector<ClientAccount *> *> ClientAccounts;
        typedef std::vector<ClientAccounts *> Repository;  

        virtual ~IDaoAccount() { };
        virtual ClientAccounts * getClient(int ClientId) = 0;
        virtual ClientAccount * getClientAccount(int ClientId, int AccountId) = 0;
        virtual bool CheckCollision(int ClientId, int AccountId, int Version) = 0;     
        virtual bool Persist(int ClientId, int AccountId, Events * AllEvents, int Version) = 0;

 
};

#endif //DAOACCOUNT_H_
