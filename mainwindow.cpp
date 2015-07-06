#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir("/dev");
    pro = new QProcess(this);
    connect(pro, SIGNAL(readyReadStandardOutput()), this, SLOT(onReadStdin()));

    flist = dir.entryList(QDir::System);
    QRegularExpression re("sd");
    foreach(QString name, flist) {
        if(re.match(name).hasMatch()) {
            ui->comboBox->addItem(name);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toolButton_clicked()
{
    fname = QFileDialog::getOpenFileName(this, tr("Select file"), "/");
    ui->lineEdit->setText(fname);
}

void MainWindow::onReadStdin()
{
    output.append(pro->readAllStandardOutput());
    ui->textEdit->append(output);
    ui->textEdit->verticalScrollBar()->setSliderPosition(ui->textEdit->verticalScrollBar()->maximum());
}

void MainWindow::on_commandLinkButton_clicked()
{
    bin = "qrc:/dd";
    inputFile = ui->lineEdit->text();
    outputFile = ui->comboBox->currentText();
    inputFile = "if=" + inputFile;
    outputFile = "of=" + outputFile;
    args << inputFile << outputFile << "bs=4M";
    pro->start(bin, args);
}
