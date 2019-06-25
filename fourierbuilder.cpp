#include "fourierbuilder.hpp"

#include "coefficientwidget.hpp"

#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

FourierBuilder::FourierBuilder(QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout;

    m_layout->addWidget(createButton(tr("Load"), &FourierBuilder::onLoadClicked));
    m_layout->addWidget(createButton(tr("Reset"), &FourierBuilder::reset));

    auto* fourier_widget = new QGroupBox(tr("Coefficients"));
    auto* fourier_layout = new QHBoxLayout;

    m_fourier_x_layout = new QVBoxLayout;
    m_fourier_x_layout->setAlignment(Qt::AlignTop);
    auto* b = new QPushButton("+");
    connect(b, &QPushButton::clicked, this, &FourierBuilder::addXCoefficient);
    m_fourier_x_layout->addWidget(b);
    m_fourier_x_layout->addWidget(new QLabel(tr("x(t) = ")));
    fourier_layout->addLayout(m_fourier_x_layout);

    m_fourier_y_layout = new QVBoxLayout;
    m_fourier_y_layout->setAlignment(Qt::AlignTop);
    b = new QPushButton("+");
    connect(b, &QPushButton::clicked, this, &FourierBuilder::addYCoefficient);
    m_fourier_y_layout->addWidget(b);
    m_fourier_y_layout->addWidget(new QLabel(tr("y(t) = ")));
    fourier_layout->addLayout(m_fourier_y_layout);

    fourier_widget->setLayout(fourier_layout);
    m_layout->addWidget(fourier_widget, 1);

    setLayout(m_layout);
    reset();
}

void FourierBuilder::reset()
{
    load({});
}

void FourierBuilder::load(Fourier values)
{
    emit updated(values);
}

template <class T> QPushButton* FourierBuilder::createButton(const QString& label, T callback)
{
    auto* button = new QPushButton(label);
    connect(button, &QPushButton::clicked, this, callback);
    return button;
}

void FourierBuilder::addXCoefficient()
{
    m_fourier_x_layout->addWidget(new CoefficientWidget);
}

void FourierBuilder::addYCoefficient()
{
    m_fourier_y_layout->addWidget(new CoefficientWidget);
}

void FourierBuilder::onLoadClicked()
{
}
