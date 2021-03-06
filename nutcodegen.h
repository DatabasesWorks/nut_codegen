#ifndef NUTCODEGEN_H
#define NUTCODEGEN_H

#include <QDir>
#include <QString>
#include <QSqlDatabase>

#include "libkode/printer.h"
#include "table.h"

class NutCodeGen
{
public:
    NutCodeGen(const QString &database,
               const QString &host,
               const QString &username,
               const QString &password,
               const QString &workingDirectory);
    ~NutCodeGen();
    bool readTables();
    bool readTableFields();
    bool readRelations();

    QString errorString() const;

    bool generateFiles();

private:
    QSqlDatabase m_db;
    QString m_database;
    QString m_host = QStringLiteral("localhost");
    QString m_username;
    QString m_password;
    QString m_workingDir;

    QString m_errorString;

    QList <Table*> m_tables;

    bool generateDatabaseClass();
    bool generateTableClasses();
    bool generatePriFile();

    KODE::Printer m_printer;
};

#endif // NUTCODEGEN_H
