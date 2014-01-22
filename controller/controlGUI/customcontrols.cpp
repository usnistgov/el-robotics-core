#include "controlGUI/customcontrols.h"
#include <iostream>
#include <cmath>

JointEdit::JointEdit(QWidget *parent) : QLineEdit(parent)
{
  validator = new QDoubleValidator;
  setValidator(validator);
  QObject::connect(this, SIGNAL(editingFinished()), this, SLOT(sendUpdate()));
}
JointEdit::~JointEdit()
{
  delete validator;
}
void JointEdit::sendUpdate()
{
  double jtValue = text().toDouble();
  Q_EMIT updateJoint(jointIndex, jtValue);
}
void JointEdit::setLimits(double low, double high)
{
  validator->setRange(low, high, -1);
}
void JointEdit::syncToSlider()
{
  JointSlider *slider = dynamic_cast<JointSlider*>(sender());
  if(slider != NULL)
  {
    QString text = QString("%2").arg((double)slider->value() * slider->precision);
    setText(text);
  }
}
void JointEdit::setJoint(double value)
{
  QString text = QString("%2").arg(value);
  setText(text);
}
JointSlider::JointSlider(double _precision, QWidget *parent):
    QSlider(Qt::Horizontal, parent),
    precision(_precision)
{
  QObject::connect(this, SIGNAL(sliderMoved(int)), this, SLOT(sendUpdate()));
}
void JointSlider::syncToText()
{
  JointEdit *edit = dynamic_cast<JointEdit*>(sender());
  if(edit != NULL)
  {
    double jtValue = edit->text().toDouble();
    setValue ((int) round(jtValue / precision));
  }
}
void JointSlider::setJoint(double value)
{
  setValue ((int) round(value/ precision));
}
void JointSlider::sendUpdate()
{
  double jtValue = value() * precision;
  Q_EMIT updateJoint(jointIndex, jtValue);
}
