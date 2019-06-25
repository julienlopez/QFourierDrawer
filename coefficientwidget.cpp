#include "coefficientwidget.hpp"

#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>

CoefficientWidget::CoefficientWidget(const QString& label, QWidget* parent)
    : QWidget(parent)
{
    auto* lay = new QHBoxLayout;

    m_coefficient = createLineEdit();
    m_frequency = createLineEdit();
    m_phase = createLineEdit();

    lay->addWidget(m_coefficient);
    lay->addWidget(new QLabel(label + "("));
    lay->addWidget(m_frequency);
    lay->addWidget(new QLabel("t + "));
    lay->addWidget(m_phase);
    lay->addWidget(new QLabel(")"));
    setLayout(lay);
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
