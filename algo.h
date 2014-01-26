#ifndef ALGO_H
#define ALGO_H

#include <QWidget>
#include <QList>
#include <QString>

namespace Ui {
class Algo;
class ParamEntry;
}

class Algo : public QWidget
{
        Q_OBJECT
    public:
        explicit Algo(const QString& url, QWidget *parent = 0);

    signals:

    public slots:
    private:
        Ui::Algo *ui;
        QList<Ui::ParamEntry*> params;

};

#endif // ALGO_H
