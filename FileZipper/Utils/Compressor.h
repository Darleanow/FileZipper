#pragma once

#include <QByteArray>
#include <QStringList>

namespace utils {

class SimpleCompressor {
 public:
  static QByteArray compressFiles(const QStringList& filePaths);
  static QByteArray compress(const QByteArray& data);
  static void decompressFiles(const QByteArray& compressedData,
                              const QString& outputDir);
  static QByteArray decompress(const QByteArray& data);
};

}  // namespace utils
