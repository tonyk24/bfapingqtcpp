#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_eventsModel(new EventsModel(ui->tableView))
{
  ui->setupUi(this);

  ui->tableView->setModel(m_eventsModel);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
  m_bfConfig = new BfLib::BfConfig(ui->lineEditUsername->text(),
                            ui->lineEditPassword->text(),
                            true,
                            "",
                            ui->lineEditAppKeyDelayed->text());

  m_accountsApi = new BfLib::AccountsApi(this, m_bfConfig);
  connect(m_accountsApi, SIGNAL(valueChanged(BfLib::BfAccountDetailsRsp)),
          this, SLOT(recievedAccountDetails(BfLib::BfAccountDetailsRsp)));



  this->m_accountsApi->getAccountDetails();

}

void MainWindow::recievedAccountDetails(BfLib::BfAccountDetailsRsp accountDetails)
{
  ui->textEditAccountDetails->setText(
        "First name: " + accountDetails.m_firstName +
        "\nLast name: " + accountDetails.m_lastName +
        "\nLocale code: " + accountDetails.m_localeCode +
        "\nPoints Balance: " + QString::number(accountDetails.m_pointsBalance) +
        "\nRegion: " + accountDetails.m_region +
        "\nTime zone: " + accountDetails.m_timezone +
        "\nCurrency code: " + accountDetails.m_currencyCode +
        "\nCountry code: " + accountDetails.m_countryCode);
}

void MainWindow::receivedEvents(QVector<BfLib::BfEvent> events)
{
  m_eventsModel->setEventsData(events);
}

void MainWindow::on_pushButtonGetEvents_clicked()
{
  m_eventsApi = new BfLib::EventsApi(this, m_bfConfig);
  connect(m_eventsApi, SIGNAL(valueChanged(QVector<BfLib::BfEvent>)),
          this, SLOT(receivedEvents(QVector<BfLib::BfEvent>)));

  BfLib::BetfairMarketFilter marketFilter;
  marketFilter.m_eventIds.push_back(QString("1")); // Football
  m_eventsApi->get(marketFilter);
}
