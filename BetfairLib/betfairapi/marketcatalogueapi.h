#ifndef MARKETCATALOGUEAPI
#define MARKETCATALOGUEAPI

#include <list>

#include <QObject>
#include <QString>
#include <QNetworkReply>

#include "betfairlib_global.h"

#include "betfairapi/httpjsonclient.h"

#include "misc/bfconfig.h"

#include "betfairfilter/betfairmarketfilter.h"

#include "bftypes/bfmarket.h"
#include "bftypes/bfapingexception.h"
#include "bfenums/bfmarketprojection.h"

namespace BfLib
{
class BETFAIRLIBSHARED_EXPORT MarketCatalogueApi : public QObject
{
  Q_OBJECT
public:
  MarketCatalogueApi(QObject *parent, BfConfig *bfConfig);

  void get(const BetfairMarketFilter &marketFilter,
           const std::list<BfMarketProjection::Enum> &marketProjections);

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClient;

public slots:
  void replyFinish(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void valueChanged(QString eventId, std::list<BfLib::BetfairMarket> markets);
  void error(BfLib::BfApiNgException *ex);
};
}
#endif // MARKETCATALOGUEAPI

