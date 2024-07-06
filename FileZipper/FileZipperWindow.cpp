#include "FileZipperWindow.h"

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "CustomWidgets/CListView/CListView.h"
#include "Styles/Styles.h"

namespace ui {

FileZipperWindow::FileZipperWindow(QWidget* parent) : QMainWindow(parent) {
  setup_ui();
  // setup_connects();
}

FileZipperWindow::~FileZipperWindow() {}

void FileZipperWindow::setup_ui() {
  m_central_widget = new QWidget(this);
  m_central_widget->setStyleSheet(Styles::default_window());

  m_layout = new QVBoxLayout(m_central_widget);

  // Title
  m_label_title = new QLabel("File Zipper", m_central_widget);
  m_label_title->setStyleSheet(Styles::label_title());
  m_label_title->setAlignment(Qt::AlignCenter);
  m_layout->addWidget(m_label_title);

  // ListView and Model
  m_list_loaded_files = new CWidgets::CListView(m_central_widget);
  m_layout->addWidget(m_list_loaded_files);

  // Button Layout
  auto* layout_buttons = new QHBoxLayout();
  m_button_add_files = new QPushButton("Add Files", m_central_widget);
  m_button_zip_files = new QPushButton("Zip Files", m_central_widget);

  layout_buttons->addWidget(m_button_add_files);
  layout_buttons->addWidget(m_button_zip_files);
  m_layout->addLayout(layout_buttons);

  // Apply styles
  m_button_add_files->setStyleSheet(Styles::default_button());
  m_button_zip_files->setStyleSheet(Styles::default_button());

  connect(m_button_add_files, &QPushButton::clicked, this,
          &FileZipperWindow::on_button_add_files_clicked);
  connect(m_button_zip_files, &QPushButton::clicked, this,
          &FileZipperWindow::on_button_zip_files_clicked);

  setCentralWidget(m_central_widget);
}

void FileZipperWindow::on_button_add_files_clicked() {
  QStringList files =
      QFileDialog::getOpenFileNames(this, "Select Files to Add");
  if (!files.isEmpty()) {
    for (const QString& file : files) {
      m_list_loaded_files->addItem(file);
    }
  }
}

void FileZipperWindow::on_button_zip_files_clicked() {
  // Add functionality to zip files
}

}  // namespace ui
