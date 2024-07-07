#include "CListView.h"

#include <QDebug>

namespace CWidgets {

CListView::CListView(QWidget* parent)
    : QListView(parent),
      model(new CListViewModel(this)),
      delegate(new CListViewDelegate(this)) {
  setModel(model);
  setItemDelegate(delegate);

  connect(delegate, &CListViewDelegate::signal_button_delete_clicked, this,
          &CListView::removeItem);

  // Set size policy to expand to fit content
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

CListView::~CListView() = default;

void CListView::addItem(const QString& text) { model->addItem(text); }

void CListView::removeItem(const QModelIndex& index) {
  model->removeItem(index.row());
}

CListViewModel* CListView::getModel() { return model; }

}  // namespace CWidgets
