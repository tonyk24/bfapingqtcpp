#ifndef MARKETBOOKAPI
#define MARKETBOOKAPI

#include <QObject>
#include <QString>

#include <map>

#include "betfairlib_global.h"

#include "betfairapi/httpjsonclient.h"
#include "betfairapi/marketcatalogueapi.h"

#include "misc/bfconfig.h"

#include "bftypes/bfmarket.h"

#include "betfairfilter/betfairmarketfilter.h"

#include "bftypes/bfapingexception.h"

namespace BfLib
{
class BETFAIRLIBSHARED_EXPORT MarketBookApi : public QObject
{
  Q_OBJECT
public:
  MarketBookApi(QObject *parent, BfConfig *bfConfig);

  void getMarketBook(std::list<QString> marketsToGet);

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClient;

  void parseRunnersJsonArray(QJsonArray &runnersArray,
                              BetfairMarket *market);

private slots:
  void replyFinish(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void valueChanged(std::list<BfLib::BetfairMarket> markets);
  void error(BfLib::BfApiNgException *ex);
};
}
#endif // MARKETBOOKAPI

