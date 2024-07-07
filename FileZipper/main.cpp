
#include <QApplication>

#include "FileZipperWindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);

  QIcon application_icon(":/icons/FileZipper_logo.ico");
  application.setWindowIcon(application_icon);

  ui::FileZipperWindow file_zipper;
  file_zipper.show();
  return application.exec();
}
