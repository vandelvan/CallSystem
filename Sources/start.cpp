#include "Headers/start.h"
#include "ui_start.h"
#include <QtDebug>
#include "Headers/callSystemMenu.h"

using namespace std;

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    ui->wrong->setVisible(false);
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{
    //toma el valor de el input del usuario
    string code = this->ui->lineEdit->text().toStdString();
    if(code == "215661399")
    {
        this->menu.show();
        this->close();
    }
    else
        //Si no es correcto muestra un dialogo
        this->ui->wrong->setVisible(true);

}

void Start::on_lineEdit_returnPressed()
{
    //Al presionar enter va al metodo que cliquea el boton
    this->on_pushButton_clicked();
}
