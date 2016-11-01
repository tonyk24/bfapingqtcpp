#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "betfairapi/accountsapi.h"
#include "betfairapi/eventsapi.h"
#include "misc/bfconfig.h"

#include "eventsmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_pushButtonLogin_clicked();
  void recievedAccountDetails(BfLib::BfAccountDetailsRsp);

  void receivedEvents(QVector<BfLib::BfEvent>);

  void on_pushButtonGetEvents_clicked();

private:
  Ui::MainWindow *ui;

  BfLib::BfConfig *m_bfConfig;
  BfLib::AccountsApi *m_accountsApi;
  BfLib::EventsApi *m_eventsApi;

  EventsModel *m_eventsModel;

};

#endif // MAINWINDOW_H
