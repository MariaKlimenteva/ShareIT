#pragma once

#include <QtGui>
#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QFileDialog>
#include <QtWidgets>
#include <QObject>

class Notepad : public QMainWindow
{
    Q_OBJECT;

public:
    Notepad();
    virtual ~Notepad() {};

private slots:
    void open();
    void save();
    void quit();

private:
    QTextEdit *textEdit;
    QAction *saveAction;
    QAction *exitAction;
    QAction *openAction;

    QMenu *fileMenu;
};