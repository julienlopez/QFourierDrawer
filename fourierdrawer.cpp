#include "fourierdrawer.hpp"

FourierDrawer::FourierDrawer(QWidget *parent) : QWidget(parent) {}

void FourierDrawer::setValues(Fourier values) {
  m_values = std::move(values);
  update();
}
