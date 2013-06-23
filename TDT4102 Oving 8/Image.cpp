
#include <iostream>
#include "Image.h"

Image::Image(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    this->data = new unsigned char[width * height * 3];
}

Image::~Image() {
    delete[] data;
}

unsigned int Image::GetWidth() const {
    return this->width;
}

unsigned int Image::GetHeight() const {
    return this->height;

}

unsigned char* Image::GetData() {
    return data;
}

const unsigned char* Image::GetData() const {
    return data;
}

void Image::SetColor(unsigned int x, unsigned int y, const Color &color) {
    int i=(y*width*3)+(x*3);
    data[i]=color.red;
    data[i+1]=color.green;
    data[i+2]=color.blue;
}
Color Image::GetColor(unsigned int x, unsigned int y) const {
    Color c;
    int i=(y*width*3)+(x*3);
    c.red=data[i];
    c.green=data[i+1];
    c.blue=data[i+2];
    return c;
}
void Image::Fill(const Color &color){
    for(int i=0; i<(width * height * 3); i+=3){
        data[i]=color.red;
        data[i+1]=color.green;
        data[i+2]=color.blue;
    }
}