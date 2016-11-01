#ifndef MARKETSMODEL_H
#define MARKETSMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVector>

#include "bftypes/bfevent.h"

class EventsModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  EventsModel(QObject *parent);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  Qt::ItemFlags flags(const QModelIndex & index) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  void setEventsData(QVector<BfLib::BfEvent> events);

signals:
public slots:

private:
  QVector<BfLib::BfEvent> m_events;
};

#endif // MARKETSMODEL_H
