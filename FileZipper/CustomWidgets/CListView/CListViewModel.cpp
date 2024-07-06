#include "CListViewModel.h"

namespace CWidgets {

CListViewModel::CListViewModel(QObject* parent) : QStandardItemModel(parent) {}

void CListViewModel::addItem(const QString& text) {
  int row = rowCount();
  beginInsertRows(QModelIndex(), row, row);
  QStandardItem* item = new QStandardItem(text);
  appendRow(item);
  endInsertRows();
}

void CListViewModel::removeItem(int row) {
  if (row < 0 || row >= rowCount()) {
    qWarning() << "Invalid row index" << row;
    return;
  }
  beginRemoveRows(QModelIndex(), row, row);
  removeRow(row);
  endRemoveRows();
}

}  // namespace CWidgets
