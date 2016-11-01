#ifndef EVENTSAPI_H
#define EVENTSAPI_H

#include <QObject>
#include <QTimer>
#include <QVector>

#include "betfairlib_global.h"

#include "misc/bfconfig.h"

#include "betfairapi/httpjsonclient.h"
#include "bftypes/bfevent.h"
#include "bfenums/bfcompetition.h"
#include "betfairfilter/betfairmarketfilter.h"
#include "bftypes/bfapingexception.h"

namespace BfLib
{
class BETFAIRLIBSHARED_EXPORT EventsApi : public QObject
{
  Q_OBJECT
public:
  EventsApi(QObject *parent, BfConfig *bfConfig);
  ~EventsApi();

  void get(const BetfairMarketFilter &marketFilter);

private:
  BfConfig *m_bfConfig;
  HttpJsonClient m_httpJsonClient;


public slots:
  void replyFinish(QString answer);
  void errorOccurred(BfLib::BfApiNgException *ex);
signals:
  void valueChanged(QVector<BfLib::BfEvent> events);
  void error(BfLib::BfApiNgException *ex);
};
}
#endif // EVENTSAPI_H

