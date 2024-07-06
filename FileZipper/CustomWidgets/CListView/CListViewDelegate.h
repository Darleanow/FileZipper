#pragma once

#include <QPushButton>
#include <QStyledItemDelegate>

namespace CWidgets {

class CListViewDelegate : public QStyledItemDelegate {
  Q_OBJECT

 public:
  explicit CListViewDelegate(QObject* parent = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option,
             const QModelIndex& index) const override;

  bool editorEvent(QEvent* event, QAbstractItemModel* model,
                   const QStyleOptionViewItem& option,
                   const QModelIndex& index) override;

 signals:
  void signal_button_delete_clicked(const QModelIndex& index) const;
};

}  // namespace CWidgets
