#pragma once

#include <QWidget>

class CoefficientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CoefficientWidget(QWidget* parent = nullptr);

    virtual ~CoefficientWidget() = default;
};
