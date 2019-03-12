#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATABASEMANAGER_H
