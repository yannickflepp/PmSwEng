include "l.h"

l::l(QObject *parent)
  : QAbstractItemModel(parent)
{
}

QVariant l::headerData(int section, Qt::Orientation orientation, int role) const
{
  // FIXME: Implement me!
}

QModelIndex l::index(int row, int column, const QModelIndex &parent) const
{
  // FIXME: Implement me!
}

QModelIndex l::parent(const QModelIndex &index) const
{
  // FIXME: Implement me!
}

int l::rowCount(const QModelIndex &parent) const
{
  if (!parent.isValid())
    return 0;

  // FIXME: Implement me!
}

int l::columnCount(const QModelIndex &parent) const
{
  if (!parent.isValid())
    return 0;

  // FIXME: Implement me!
}

QVariant l::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  // FIXME: Implement me!
  return QVariant();
}
