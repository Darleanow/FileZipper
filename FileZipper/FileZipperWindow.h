#pragma once

#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

namespace CWidgets {
class CListView;
}

namespace ui {

class FileZipperWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit FileZipperWindow(QWidget* parent = nullptr);
  ~FileZipperWindow();

 private:
  void setup_ui();
  void on_button_add_files_clicked();
  void on_button_zip_files_clicked();
  void on_button_unzip_files_clicked();

  QWidget* m_central_widget;
  QVBoxLayout* m_layout;
  QLabel* m_label_title;
  CWidgets::CListView* m_list_loaded_files;
  QPushButton* m_button_add_files;
  QPushButton* m_button_zip_files;
  QPushButton* m_button_unzip_files;
};

}  // namespace ui
