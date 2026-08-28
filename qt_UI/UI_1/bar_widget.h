#ifndef BAR_WIDGET_H
#define BAR_WIDGET_H

#include <QObject>
#include <QWidget>

class bar_widget:public QWidget
{
    Q_OBJECT
public:
    bar_widget(QWidget* parent = nullptr);
    void setValues(const QVector<int>& values);
    void setValue(int index, int value);
    void setMaxValue(int max);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<int> m_values;
    int m_maxValue;
    int m_spacing;
};

#endif // BAR_WIDGET_H
