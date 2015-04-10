#include "finishdialog.h"
#include "ui_finishdialog.h"

FinnishDialog::FinnishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinnishDialog)
{
    ui->setupUi(this);
}

FinnishDialog::~FinnishDialog()
{
    delete ui;
}


void FinnishDialog::setResults(QString results)
{
    ui->results->setText(results);
}


void FinnishDialog::setPseudo(QString pseudo)
{
    ui->pseudo->setText(pseudo);
}

QString FinnishDialog::getPseudo()
{
    return ui->pseudo->text().trimmed();

}
