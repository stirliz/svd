#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QString>
#include <QList>

#include "algo.h"

class Downloader;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_webView_linkClicked(const QUrl &arg1);
        void on_goButton_clicked();
        void on_webView_urlChanged(const QUrl &arg1);
        void on_actionBack_triggered();
        void on_actionForward_triggered();
        void on_actionRefresh_triggered();
        void on_actionOpenSrc_triggered();

        void on_urlEdit_returnPressed();

        void on_actionModAlg_triggered();

    private:
        Ui::MainWindow *ui;

        QList<Downloader*> downloads;
        Algo *algo;
};

#endif // MAINWINDOW_H
