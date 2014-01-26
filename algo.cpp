#include "algo.h"
#include "ui_algo.h"

Algo::Algo(const QString& url, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Algo)
{
    ui->setupUi(this);
    ui->paramUrl->setText( url );
}
