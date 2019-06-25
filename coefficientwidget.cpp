#include "coefficientwidget.hpp"

#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>

CoefficientWidget::CoefficientWidget(const QString& label, QWidget* parent)
    : QWidget(parent)
{
    m_coefficient = createLineEdit();
    m_frequency = createLineEdit();
    m_phase = createLineEdit();

    auto* lay = new QHBoxLayout;
    lay->setSpacing(1);
    lay->addWidget(m_coefficient);
    lay->addWidget(new QLabel(label + "("));
    lay->addWidget(m_frequency);
    lay->addWidget(new QLabel("t + "));
    lay->addWidget(m_phase);
    lay->addWidget(new QLabel(")"));
    setLayout(lay);
}

Fourier::Node CoefficientWidget::value() const
{
    return {m_coefficient->text().toDouble(), m_frequency->text().toDouble(), m_phase->text().toDouble()};
}

QLineEdit* CoefficientWidget::createLineEdit()
{
    auto* res = new QLineEdit;
    auto* valid = new QIntValidator(res);
    res->setValidator(valid);
    res->setText("0");
    connect(res, &QLineEdit::textEdited, this, &CoefficientWidget::edited);
    return res;
}
