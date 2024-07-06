#include "CListView.h"

#include <QDebug>

#include "CListViewModel.h"

namespace CWidgets {

CListView::CListView(QWidget* parent)
    : QListView(parent),
      model(new CListViewModel(this)),
      delegate(new CListViewDelegate(this)) {
  setModel(model);
  setItemDelegate(delegate);

  connect(delegate, &CListViewDelegate::signal_button_delete_clicked, this,
          &CListView::removeItem);
}

CListView::~CListView() = default;

void CListView::addItem(const QString& text) {
  model->addItem(text);
}

void CListView::removeItem(const QModelIndex& index) {
  model->removeItem(index.row());
}

}  // namespace CWidgets
