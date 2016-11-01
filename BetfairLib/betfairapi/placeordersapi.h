#ifndef PLACEORDERSAPI_H
#define PLACEORDERSAPI_H

#include <list>

#include <QObject>
#include <QString>
#include <QNetworkReply>

#include "betfairlib_global.h"

#include "bftypes/bfmarket.h"

#include "bftypes/bfplaceinstruction.h"
#include "bftypes/bfplaceexecutionreport.h"
#include "betfairapi/httpjsonclient.h"

#include "bftypes/bfapingexception.h"

namespace BfLib
{
class BETFAIRLIBSHARED_EXPORT PlaceOrdersApi : public QObject
{
  Q_OBJECT
public:
  PlaceOrdersApi(QObject *parent, BfConfig *bfConfig);

  void placeOrders(QString marketId, std::list<BfPlaceInstruction> placeInstructions);

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClient;

public slots:
  void replyFinish(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void placeOrdersResponse(BfLib::BfPlaceExecutionReport placeExecutionReport);
  void error(BfLib::BfApiNgException *ex);
};
}

#endif // PLACEORDERSAPI_H

