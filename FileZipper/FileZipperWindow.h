#pragma once

#include <QMainWindow>

// Forward declarations
namespace CWidgets {
class CListView;
}
class QVBoxLayout;
class QLabel;
class QPushButton;

namespace ui {

class FileZipperWindow : public QMainWindow {
  Q_OBJECT

 public:
  FileZipperWindow(QWidget* parent = nullptr);
  ~FileZipperWindow();

 private slots:
  void on_button_add_files_clicked();
  void on_button_zip_files_clicked();

 private:
  QWidget* m_central_widget;
  QVBoxLayout* m_layout;
  QLabel* m_label_title;
  CWidgets::CListView* m_list_loaded_files;
  QPushButton* m_button_add_files;
  QPushButton* m_button_zip_files;

  void setup_ui();
  // void setup_connects();
};

}  // namespace ui