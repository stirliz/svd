#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->urlEdit->setText( QString("http://linux.org.ru") );
    ui->webView->setUrl( QUrl( ui->urlEdit->text() ) );

    ui->webView->page()->setLinkDelegationPolicy( QWebPage::DelegateAllLinks );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_webView_linkClicked(const QUrl &arg1)
{
    ui->webView->setUrl( arg1 );
}

void MainWindow::on_goButton_clicked()
{
    QString url = ui->urlEdit->text();
    if ( url.indexOf(QString("://")) == -1 )
        url.prepend( "http://" );
    ui->webView->setUrl( QUrl(url) );
    ui->urlEdit->setText( url );
}

void MainWindow::on_webView_urlChanged(const QUrl &arg1)
{
    ui->urlEdit->setText( arg1.toString() );
}

void MainWindow::on_actionBack_triggered()
{
    ui->webView->back();
}

void MainWindow::on_actionForward_triggered()
{
    ui->webView->forward();
}

void MainWindow::on_actionRefresh_triggered()
{
    ui->webView->setUrl( ui->webView->url() );
}

void MainWindow::on_actionOpenSrc_triggered()
{
}

void MainWindow::on_urlEdit_returnPressed()
{
    on_goButton_clicked();
}
