#ifndef LISTCURRENTORDERSAPI_H
#define LISTCURRENTORDERSAPI_H

#include <list>

#include <QObject>
#include <QString>
#include <QNetworkReply>

#include "betfairlib_global.h"

#include "bftypes/bfmarket.h"

#include "bftypes/bfplaceinstruction.h"
#include "bftypes/bfcurrentorder.h"
#include "betfairapi/httpjsonclient.h"

#include "bftypes/bfapingexception.h"

namespace BfLib
{
class BETFAIRLIBSHARED_EXPORT ListCurrentOrdersApi : public QObject
{
  Q_OBJECT
public:
  ListCurrentOrdersApi(QObject *parent, BfConfig *bfConfig);

  void listCurrentOrders(std::list<QString> marketIds);

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClient;

public slots:
  void replyFinish(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void listCurrentOrdersResponse(std::list<BfLib::BfCurrentOrder> currentOrders);
  void error(BfLib::BfApiNgException *ex);
};
}
#endif // LISTCURRENTORDERSAPI_H




