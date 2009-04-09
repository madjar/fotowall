/****************************
* Auteur :Tanguy Arnaud
* Date : 2008
*
* Copyright (C) 2008 TANGUY Arnaud
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 ******************************/

#include "CPixmap.h"
#include "GlowEffectDialog.h"
#include <QImage>

CPixmap::CPixmap() : m_isNVG(false), m_isBlackAndWhite(false) {
}

CPixmap::CPixmap(const QString &fileName) : QPixmap(fileName), m_filePath(fileName), m_isNVG(false), m_isBlackAndWhite(false)
{
}

CPixmap::CPixmap(const QPixmap &pixmap): QPixmap(pixmap){
}

void CPixmap::save(QDataStream & data) const
{
    // Save current effects
    data << m_effects;
}
bool CPixmap::restore(QDataStream & data)
{
    // Restore effects
    m_effects.clear();
    data >> m_effects;
    foreach (int effect, m_effects) {
        if( effect == NVG) 
            toNVG();
        else if ( effect == BlackAndWhite)
            toBlackAndWhite();
        else if (effect == InvertColors)
            invertColors();
    }
    return true;
}

void CPixmap::toNVG() {
    m_effects.push_back(NVG);
    QImage img = this->toImage();
    QImage dest(img.size(), img.format());
    QColor pixel;
    for(int x=0; x<img.width();x++) {
        for (int y=0; y<img.height(); y++) {
            pixel = img.pixel(x, y);
            unsigned int average = (pixel.green()+ pixel.red() + pixel.blue()) / 3;
            pixel.setGreen(average);
            pixel.setBlue(average);
            pixel.setRed(average);
            dest.setPixel(x,y,pixel.rgb());
        }
    }
    m_isNVG = true;
    updateImage(dest);
}

    void CPixmap::invertColors() {
        if(m_effects.contains(InvertColors))
            m_effects.removeOne(InvertColors);
        else
            m_effects.push_back(InvertColors);
        QImage img = this->toImage();
        img.invertPixels();
        updateImage(img);
    }

void CPixmap::flipH() {
    QImage img = this->toImage();
    QImage dest(img.size(), img.format());
    QRgb pixel;
    int width = img.width() -1;
    for(int x=0; x<width;x++) {
        for (int y=0; y<img.height(); y++) {
            pixel = img.pixel(x,y);
            dest.setPixel(width - x,y,pixel);
        }
    }
    updateImage(dest);
}
void CPixmap::flipV() {
    QImage img = this->toImage();
    QImage dest(img.size(), img.format());
    QRgb pixel;
    int height = img.height() -1;
    for(int x=0; x<img.width() ;x++) {
        for (int y=0; y<height; y++) {
            pixel = img.pixel(x,y);
            dest.setPixel(x, height - y,pixel);
        }
    }
    updateImage(dest);
}

void CPixmap::toBlackAndWhite() {
    m_effects.push_back(BlackAndWhite);
    QImage img = this->toImage();
    QImage dest(img.size(), img.format());
    QColor pixel;
    for(int x=0; x<img.width();x++) {
        for (int y=0; y<img.height(); y++) {
            pixel = img.pixel(x, y);
            unsigned int average = (pixel.green()+ pixel.red() + pixel.blue()) / 3;
            if(average > 127)
                average = 255;
            else
                average = 0;
            pixel.setGreen(average);
            pixel.setBlue(average);
            pixel.setRed(average);
            dest.setPixel(x,y,pixel.rgb());
        }
    }
    m_isBlackAndWhite = true;
    updateImage(dest);
}

void CPixmap::glowEffect() {
    GlowEffectDialog effect(this);
    effect.exec();
}

void CPixmap::noEffects() {
    //Reload the image to remove the effects
    if( !m_filePath.isEmpty() ) {
        load(m_filePath);
        m_effects.clear();
    }
}

void CPixmap::luminosity(int value) {
    QImage img = this->toImage();
    QImage dest(img.size(), img.format());
    QColor pixel;
    for(int x=0; x<img.width();x++) {
        for (int y=0; y<img.height(); y++) {
            pixel = img.pixel(x, y);
            int green = pixel.green() + value;
            int red = pixel.red() + value;
            int blue = pixel.blue() + value;
            if(green > 255) green = 255;
            else if(green < 0) green = 0;
            if(red > 255) red = 255;
            else if(red < 0) red = 0;
            if(blue > 255) blue = 255;
            else if(blue <0) blue = 0;

            pixel.setGreen(green);
            pixel.setBlue(blue);
            pixel.setRed(red);
            dest.setPixel(x,y,pixel.rgb());
        }
    }
    updateImage(dest);
}

void CPixmap::updateImage(QImage &newImage) {
    QString tmpFilePath = m_filePath;
    QList<int> effects = m_effects;
    *this = fromImage(newImage);
    m_filePath = tmpFilePath;
    m_effects = effects;
}
