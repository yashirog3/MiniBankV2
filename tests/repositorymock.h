#ifndef REPOSITORYMOCK_H_
#define REPOSITORYMOCK_H_
#include <gmock/gmock.h>
#include <vector>
#include <map>
#include "../Dao/idaoaccount.h"

class RepositoryMock : public IDaoAccount 
{
 public:

      MOCK_METHOD1(getClient, ClientAccounts*(int ClientId));
      MOCK_METHOD2(getClientAccount,  ClientAccount*(int ClientId, int AccountId));
      MOCK_METHOD3(CheckCollision, bool(int ClientId, int AccountId, int OldVersion));
      MOCK_METHOD4(Persist, bool(int ClientId, int AccountId, Events * AllEvents, int OldVersion));
};



#endif


