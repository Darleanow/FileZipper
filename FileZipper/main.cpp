#include <QApplication>

#include "FileZipperWindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  ui::FileZipperWindow file_zipper;
  file_zipper.show();
  return application.exec();
}
