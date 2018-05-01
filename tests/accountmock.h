#ifndef ACCOUNTMOCK_H_
#define ACCOUNTMOCK_H_
#include "../Model/iaccount.h"
#include "../Event/createaccountevent.h"
#include "../Event/depositeaccountevent.h"
#include "../Event/withdrawaccountevent.h"
#include "../Handler/eventhandler.h"
#include "../Dao/idaoaccount.h"
#include "../Model/account.h"
#include "../Event/event.h"
#include <gmock/gmock.h>

class AccountMock : public IAccount 
{

    public:

        MOCK_METHOD1(Update, void (Event * AcEvent));
        MOCK_METHOD1(Persist, void(IDaoAccount * DaoAc));

   };


#endif
