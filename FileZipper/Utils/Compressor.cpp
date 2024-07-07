#include "Compressor.h"

#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <iostream>

namespace utils {

QByteArray SimpleCompressor::compressFiles(const QStringList& filePaths) {
  QByteArray result;
  QDataStream out(&result, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_6_7);

  for (const QString& filePath : filePaths) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
      continue;  // Skip files that cannot be opened
    }

    QByteArray fileData = file.readAll();
    QByteArray compressedData = compress(fileData);

    out << filePath << compressedData;
  }

  return result;
}

QByteArray SimpleCompressor::compress(const QByteArray& data) {
  QByteArray compressed;
  int size = data.size();

  for (int i = 0; i < size; ++i) {
    int runLength = 1;
    while (i + 1 < size && data[i] == data[i + 1] && runLength < 255) {
      ++runLength;
      ++i;
    }

    compressed.append(data[i]);
    compressed.append(static_cast<char>(runLength));
  }

  return compressed;
}

void SimpleCompressor::decompressFiles(const QByteArray& compressedData,
                                       const QString& outputDir) {
  QDataStream in(compressedData);
  in.setVersion(QDataStream::Qt_6_7);

  while (!in.atEnd()) {
    QString filePath;
    QByteArray compressedFileData;
    in >> filePath >> compressedFileData;

    QByteArray decompressedData = decompress(compressedFileData);

    QDir dir(outputDir);
    QString absoluteFilePath = dir.filePath(QFileInfo(filePath).fileName());
    QFileInfo fileInfo(absoluteFilePath);
    QDir().mkpath(fileInfo.path());

    QFile file(absoluteFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
      continue;  // Skip files that cannot be opened
    }

    file.write(decompressedData);
    file.close();
  }
}

QByteArray SimpleCompressor::decompress(const QByteArray& data) {
  QByteArray decompressed;
  int size = data.size();

  for (int i = 0; i < size; i += 2) {
    if (i + 1 >= size) {
      std::cout << "Data format error, unexpected end of data." << std::endl;
      break;
    }

    char byte = data[i];
    int runLength = static_cast<unsigned char>(data[i + 1]);

    for (int j = 0; j < runLength; ++j) {
      decompressed.append(byte);
    }
  }

  return decompressed;
}

}  // namespace utils
