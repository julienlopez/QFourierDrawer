#include "mainwindow.hpp"

#include "fourierbuilder.hpp"
#include "fourierdrawer.hpp"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    auto* w = new QWidget;
    auto* hl = new QHBoxLayout;

    auto* builder = new FourierBuilder;
    builder->setFixedWidth(200);
    hl->addWidget(builder);

    auto* drawer = new FourierDrawer;
    drawer->setMinimumSize(800, 600);
    hl->addWidget(drawer);

    w->setLayout(hl);
    setCentralWidget(w);

    connect(builder, &FourierBuilder::updated, drawer, &FourierDrawer::setValues);
    builder->reset();
}
