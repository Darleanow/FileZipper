#include "Styles.h"

#include <QString>

QString Styles::default_window() {
  return "QWidget {"
         "background-color: #212529;"
         "}";
}

QString Styles::default_button() {
  return "QPushButton {"
         "background-color: #343A40;"
         "border: none;"
         "color: #E9ECEF;"
         "padding: 15px 32px;"
         "text-align: center;"
         "text-decoration: none;"
         "font-size: 16px;"
         "margin: 4px 2px;"
         "border-radius: 10px;"
         "border: 1px solid #6C757D;"
         "}"
         "QPushButton:hover {"
         "background-color: #495057;"
         "}"
         "QPushButton:pressed {"
         "background-color: #495057;"
         "}";
}

QString Styles::label_title() {
  return "QLabel {"
         "    font-size: 35px;"
         "    font-weight: bold;"
         "    color: #CED4DA;"
         "}";
}
