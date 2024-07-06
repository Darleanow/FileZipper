#pragma once

#include <QStandardItemModel>

namespace CWidgets {

class CListViewModel : public QStandardItemModel {
  Q_OBJECT

 public:
  explicit CListViewModel(QObject* parent = nullptr);
  void addItem(const QString& text);
  void removeItem(int row);
};

}  // namespace CWidgets
