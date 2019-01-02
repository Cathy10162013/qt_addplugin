#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!loadPlugin()) {
        QMessageBox::information(this, "Error", "Could not load the plugin");
    }
}

bool MainWindow::loadPlugin()
{
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            addInterface = qobject_cast<AddInterface *>(plugin);
            if (addInterface)
                return true;
        }
    }

    return false;
}

void MainWindow::on_pushButton_2_clicked()
{
    int a = ui->lineEdit->text().toInt();
    int b = ui->lineEdit_2->text().toInt();
    int c = addInterface->add(a,b);
    ui->lineEdit_3->setText(QString::number(c,10));
}
