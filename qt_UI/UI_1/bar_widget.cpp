#include "bar_widget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QLinearGradient>

bar_widget::bar_widget(QWidget* parent) : QWidget(parent) , m_maxValue(100), m_spacing(15)
{
    m_values << 20 << 50 << 80 << 40 << 95;
}

void bar_widget::setValues(const QVector<int>& values)
{
    m_values = values;
    update();
}

void bar_widget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (m_values.isEmpty()) return;

    int w = this->width();
    int h = this->height();

    int totalSpacing = m_spacing * (m_values.size() + 1);
    int barWidth = (w - totalSpacing) / m_values.size();

    if (barWidth <= 0) return;

    QLinearGradient gradient(0, h, 0, 0);
    gradient.setColorAt(0.0, QColor(46, 204, 113));  //green yellow red
    gradient.setColorAt(0.5, QColor(241, 196, 15));
    gradient.setColorAt(1.0, QColor(231, 76, 60));

    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < m_values.size(); ++i) {
        int value = m_values[i];

        if (value > m_maxValue) value = m_maxValue;
        if (value < 0) value = 0;

        int barHeight = static_cast<int>((static_cast<double>(value) / m_maxValue) * h);

        int x = m_spacing + i * (barWidth + m_spacing);
        int y = h - barHeight;

        QRect barRect(x, y, barWidth, barHeight);
        painter.drawRoundedRect(barRect, 5, 5);
    }
}

void bar_widget::setMaxValue(int max){
    m_maxValue = max;
    update();
}

void bar_widget::setValue(int index, int value){
    if(index >= 0 && index < m_values.size()){
        m_values[index] = value;
        update();
    }
}
