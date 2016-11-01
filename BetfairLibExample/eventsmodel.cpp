#include <cmath>
#include <QDebug>
#include <QColor>
#include "eventsmodel.h"

#include "bftypes/bfmarket.h"

EventsModel::EventsModel(QObject *parent)
  :QAbstractTableModel(parent)
{
}

int EventsModel::rowCount(const QModelIndex & /*parent*/) const
{
  return m_events.size();
}

int EventsModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 4;
}

Qt::ItemFlags EventsModel::flags(const QModelIndex & index) const
{
  return QAbstractTableModel::flags(index);
}

QVariant EventsModel::data(const QModelIndex &index, int role) const
{
  if (role == Qt::DisplayRole)
  {
    if (index.column() == 0)
      return m_events[index.row()].m_eventId;
    else if (index.column() == 1)
      return m_events[index.row()].m_name;
    else if (index.column() == 2)
      return m_events[index.row()].m_countryCode;
    else if (index.column() == 3)
      return m_events[index.row()].m_openDate;

  }
  return QVariant();
}

QVariant EventsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if(role == Qt::DisplayRole)
  {
    if(orientation == Qt::Horizontal)
    {
      if (section == 0)
        return QString("Id");
      else if (section == 1)
        return QString("Name");
      else if (section == 2)
        return QString("Country");
      else if (section == 3)
        return QString("Opendate");
    }

  }

  return QVariant::Invalid;
}

void EventsModel::setEventsData(QVector<BfLib::BfEvent> events)
{
  m_events = events;

  QModelIndex topLeft = index(0, 0);
  QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);

  emit dataChanged(topLeft, bottomRight);
  emit layoutChanged();
}
