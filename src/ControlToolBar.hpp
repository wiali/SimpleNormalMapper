// This file is part of Simple Normal Mapper.
// Copyright (c) 2013 Simple Normal Mapper developers.
//
// Simple Normal Mapper is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Simple Normal Mapper is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Simple Normal Mapper. If not, see <http://www.gnu.org/licenses/>.

#ifndef CONTROLTOOLBAR_HPP
#define CONTROLTOOLBAR_HPP

#include <QToolBar>
#include <QTimer>

class RenderPreview;

class QCheckBox;
class QPushButton;
class QSlider;

class ControlToolBar : public QToolBar
{
    Q_OBJECT

public:
    ControlToolBar(RenderPreview * renderPreview, QWidget * parent = nullptr);
    ~ControlToolBar();

public slots:

    void enableControls();

private slots:

    void changeRadius(int radius);

    void changePreview(bool preview);

    void changeAmplitude(int amplitude);

signals:

    void renderButtonClicked();

    void amplitudeChanged(float amplitude);

    void radiusChanged(float radius);

private:

    void initToolbar();

    void updateRadiusToolTip();
    void updateAmplitudeToolTip();

    float m_currentAmplitude;
    float m_currentRadius;

    QCheckBox     * m_previewCheckBox;
    QSlider       * m_radiusSlider;
    QSlider       * m_amplitudeSlider;
    QPushButton   * m_renderButton;
    RenderPreview * m_renderPreview;
    QTimer          m_renderTimer;
};

#endif // CONTROLTOOLBAR_HPP
