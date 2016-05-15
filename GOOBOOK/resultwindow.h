#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include "score.h"

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();
    //Object
    Score ss;

private slots:
    void on_close_clicked();

    void on_retry_clicked();

private:
    Ui::ResultWindow *ui;

};

#endif // RESULTWINDOW_H
