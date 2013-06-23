#include <vector>
#include "Canvas.h"
#include "Image.h"
#include "Shape.h"
#include <vector>

using namespace std;
void Canvas::AddShape(Shape* shape){
    this->vect.push_back(shape);
}
void Canvas::RasterizeTo(Image& img){
    for(int i=0; i<vect.size(); i++){
        vect[i]->Draw(img);
    }
}