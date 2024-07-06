#pragma once

#include <QListView>

#include "CListViewDelegate.h"
#include "CListViewModel.h"

namespace CWidgets {

class CListView : public QListView {
  Q_OBJECT
 public:
  explicit CListView(QWidget* parent = nullptr);
  ~CListView() override;

  void addItem(const QString& text);
  void removeItem(const QModelIndex& index);

 private:
  CListViewModel* model;
  CListViewDelegate* delegate;
};

}  // namespace CWidgets
