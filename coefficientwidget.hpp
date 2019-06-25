#pragma once

#include "fourier.hpp"

#include <QWidget>

class QLineEdit;

class CoefficientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CoefficientWidget(const QString& label, QWidget* parent = nullptr);

    virtual ~CoefficientWidget() = default;

    Fourier::Node value() const;

signals:
    void edited();

private:
    QLineEdit* m_coefficient;
    QLineEdit* m_frequency;
    QLineEdit* m_phase;

    QLineEdit* createLineEdit();
};
