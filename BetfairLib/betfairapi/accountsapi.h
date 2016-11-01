#ifndef ACCOUNTSAPI_H
#define ACCOUNTSAPI_H

#include "betfairlib_global.h"

#include "betfairapi/httpjsonclient.h"

#include "misc/bfconfig.h"

#include "bftypes/bfapingexception.h"
#include "bftypes/bfaccountfundsrsp.h"
#include "bftypes/bfaccountdetailsrsp.h"

namespace BfLib
{

class BETFAIRLIBSHARED_EXPORT AccountsApi : public QObject
{
  Q_OBJECT
public:
  AccountsApi(QObject *parent, BfConfig *bfConfig);

  void getAccountFunds();
  void getAccountDetails();

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClientFunds;
  HttpJsonClient m_httpJsonClientDetails;


public slots:
  void replyFinishFunds(QString answer);
  void replyFinishDetails(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void valueChanged(BfLib::BfAccountFundsRsp accountFundsRsp);
  void valueChanged(BfLib::BfAccountDetailsRsp accountFundsRsp);
  void error(BfLib::BfApiNgException *ex);
};
}

#endif // ACCOUNTSAPI_H

