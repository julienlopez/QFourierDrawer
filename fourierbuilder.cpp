#include "fourierbuilder.hpp"

#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

FourierBuilder::FourierBuilder(QWidget *parent) : QWidget(parent)
{
    m_layout = new QVBoxLayout;


    m_layout->addWidget(createButton(tr("Load"), &FourierBuilder::onLoadClicked));
    m_layout->addWidget(createButton(tr("Reset"), &FourierBuilder::reset));

    m_fourier_layout = new QVBoxLayout;
    m_fourier_widget = new QGroupBox(tr("Coefficients"));
    m_fourier_widget->setLayout(m_fourier_layout);
    m_layout->addWidget(m_fourier_widget, 1);

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

template<class T>
QPushButton* FourierBuilder::createButton(const QString& label, T callback)
{
    auto* button = new QPushButton(label);
    connect(button, &QPushButton::clicked, this, callback);
    return button;
}

void FourierBuilder::onLoadClicked()
{

}
