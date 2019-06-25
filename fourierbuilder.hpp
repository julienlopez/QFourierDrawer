#ifndef FOURIERBUILDER_HPP
#define FOURIERBUILDER_HPP

#include "fourier.hpp"

#include <QWidget>

class QGroupBox;
class QPushButton;
class QVBoxLayout;

class FourierBuilder : public QWidget
{
    Q_OBJECT
public:
    explicit FourierBuilder(QWidget *parent = nullptr);

    virtual ~FourierBuilder() = default;

signals:
    void updated(Fourier values);

public slots:
    void reset();

    void load(Fourier values);

private:
    QVBoxLayout* m_layout;

    // TODO keep both?
    QGroupBox* m_fourier_widget;
    QVBoxLayout* m_fourier_layout;

    template<class T>
    QPushButton* createButton(const QString& label, T callback);

    void onLoadClicked();
};

#endif // FOURIERBUILDER_HPP
