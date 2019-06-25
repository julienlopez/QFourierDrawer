#ifndef FOURIERDRAWER_HPP
#define FOURIERDRAWER_HPP

#include "fourier.hpp"

#include <QWidget>

class FourierDrawer : public QWidget {
  Q_OBJECT
public:
  explicit FourierDrawer(QWidget *parent = nullptr);

  virtual ~FourierDrawer() = default;

signals:

public slots:
  void setValues(Fourier values);

private:
  Fourier m_values;
};

#endif // FOURIERDRAWER_HPP
