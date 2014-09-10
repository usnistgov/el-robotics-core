#ifndef CUSTOMCONTROLS_H
#define CUSTOMCONTROLS_H

#include <QSlider>
#include <QLineEdit>
#include <QDoubleValidator>

/** 
  \addtogroup controlGUI
  @{
*/

/**
  \class JointSlider customcontrols.h
  \brief Derivation of QSlider used to set a joint target value
*/
class JointSlider : public QSlider
{
  Q_OBJECT
public:
  double precision;
  int jointIndex;
  JointSlider(double _precision, QWidget *parent=0);
  ~JointSlider(){}
  void setJoint(double value);
public Q_SLOTS:
  void syncToText();
  void sendUpdate();
Q_SIGNALS:
  void updateJoint(int, double);
};
/**
  \class JointEdit customcontrols.h
  \brief Derivation of QLineEdit used to set a joint target value
*/
class JointEdit : public QLineEdit
{
  Q_OBJECT
public:
  JointEdit(QWidget *parent=0);
  ~JointEdit();
  void setLimits(double low, double high);
  void setJoint(double value);
  int jointIndex;
private:
  QDoubleValidator *validator;
public Q_SLOTS:
  void syncToSlider();
  void sendUpdate();
Q_SIGNALS:
  void updateJoint(int, double);
};

/** @} */

#endif
