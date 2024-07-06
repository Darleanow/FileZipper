#include "CListViewDelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QStyle>

namespace CWidgets {

CListViewDelegate::CListViewDelegate(QObject* parent)
    : QStyledItemDelegate(parent),
      m_icon_delete(QIcon(":/icons/delete_icon.png")) {}

void CListViewDelegate::paint(QPainter* painter,
                              const QStyleOptionViewItem& option,
                              const QModelIndex& index) const {
  painter->save();

  QColor selection_color(73, 80, 87);
  QColor border_color(108, 117, 125);

  QRect item_rect = option.rect.adjusted(4, 4, -4, -4);

  if (option.state & QStyle::State_Selected) {
    painter->fillRect(item_rect, selection_color);
  } else {
    painter->fillRect(item_rect, option.palette.window());
  }

  QFont font = option.font;
  font.setPointSize(font.pointSize() + 2);
  painter->setFont(font);
  QFontMetrics font_metrics(font);

  int left_padding = 10;
  QRect text_rect = item_rect.adjusted(left_padding, 0, -28, 0);
  QString elided_text = font_metrics.elidedText(
      index.data().toString(), Qt::ElideRight, text_rect.width());
  painter->setPen(option.palette.text().color());
  painter->drawText(text_rect, option.displayAlignment, elided_text);

  int icon_size = 24;
  int button_x = item_rect.right() - icon_size - 4;
  int button_y = item_rect.top() + (item_rect.height() - icon_size) / 2;
  QRect button_rect(button_x, button_y, icon_size, icon_size);

  m_icon_delete.paint(painter, button_rect);

  painter->setPen(border_color);
  painter->drawRect(item_rect);

  painter->restore();
}

bool CListViewDelegate::editorEvent(QEvent* event, QAbstractItemModel* model,
                                    const QStyleOptionViewItem& option,
                                    const QModelIndex& index) {
  if (event->type() == QEvent::MouseButtonPress) {
    QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
    int icon_size = 24;
    QRect item_rect = option.rect.adjusted(4, 4, -4, -4);
    int button_x = item_rect.right() - icon_size - 4;
    int button_y = item_rect.top() + (item_rect.height() - icon_size) / 2;
    QRect button_rect(button_x, button_y, icon_size, icon_size);
    if (button_rect.contains(mouse_event->pos())) {
      emit signal_button_delete_clicked(index);
      return true;
    }
  }
  return QStyledItemDelegate::editorEvent(event, model, option, index);
}

QSize CListViewDelegate::sizeHint(const QStyleOptionViewItem& option,
                                  const QModelIndex& index) const {
  QSize original_size = QStyledItemDelegate::sizeHint(option, index);
  return QSize(original_size.width(), original_size.height() + 20);
}

}  // namespace CWidgets
