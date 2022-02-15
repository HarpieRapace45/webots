// Copyright 1996-2022 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WB_NETWORK_HPP
#define WB_NETWORK_HPP

#include <QtCore/QFileInfo>
#include <QtCore/QObject>

class QNetworkAccessManager;

class WbNetwork : public QObject {
  Q_OBJECT

public:
  static WbNetwork *instance();
  QNetworkAccessManager *networkAccessManager();
  void setProxy();

  bool isCached(QString url);
  void clearCache();
  void save(QString url, const QByteArray &content);
  QString get(const QString url);

  qint64 cacheSize() const { return mCacheSizeInBytes; };
  void reduceCacheUsage();

private:
  static void cleanup();
  WbNetwork();
  ~WbNetwork();

  const QString urlToHash(QString url);

  void recomputeCacheSize();
  static bool lastReadLessThan(QFileInfo &f1, QFileInfo &f2);

  QString mCacheDirectory;
  qint64 mCacheSizeInBytes;

  QNetworkAccessManager *mNetworkAccessManager;
};

#endif  // WB_NETWORK_HPP
