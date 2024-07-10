#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Crear el objeto TokenStorage con el nombre de archivo "tokens.txt"
    tokenStorage = new TokenStorage("tokens.txt");

    // Inicializar el modelo de la lista
    model = new QStringListModel(this);

    // Configurar QListView para usar el modelo
    ui->tokenListView->setModel(model);

    // Conectar el botón con el slot
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::on_loadButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
    delete tokenStorage;
}

void MainWindow::on_loadButton_clicked() {
    // Cargar y mostrar los tokens
    std::vector<Token> tokens = tokenStorage->loadTokens();
    QStringList list;
    for (const auto& token : tokens) {
        list.append(QString::fromStdString(token.getValue()));
    }
    model->setStringList(list);
}
