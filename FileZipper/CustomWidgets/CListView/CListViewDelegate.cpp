#include "CListViewDelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>

namespace CWidgets {

CListViewDelegate::CListViewDelegate(QObject* parent)
    : QStyledItemDelegate(parent) {}

void CListViewDelegate::paint(QPainter* painter,
                              const QStyleOptionViewItem& option,
                              const QModelIndex& index) const {
  QStyledItemDelegate::paint(painter, option, index);

  // Draw the delete button
  QPushButton button;
  button.setText("Delete");
  button.resize(option.rect.height(), option.rect.height());

  // Calculate the position for the button
  int buttonX = option.rect.right() - button.width();
  int buttonY = option.rect.top();

  painter->save();
  painter->translate(buttonX, buttonY);
  button.render(painter);
  painter->restore();
}

bool CListViewDelegate::editorEvent(QEvent* event, QAbstractItemModel* model,
                                    const QStyleOptionViewItem& option,
                                    const QModelIndex& index) {
  if (event->type() == QEvent::MouseButtonPress) {
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
    int buttonX = option.rect.right() - option.rect.height();
    QRect buttonRect(buttonX, option.rect.top(), option.rect.height(),
                     option.rect.height());
    if (buttonRect.contains(mouseEvent->pos())) {
      emit signal_button_delete_clicked(index);
      return true;
    }
  }
  return QStyledItemDelegate::editorEvent(event, model, option, index);
}

}  // namespace CWidgets
