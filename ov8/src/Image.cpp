#import "Image.h"


// Image-class implementations
Image::Image(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;
	this->data = new unsigned char [height*width*3];
}

Image::~Image() {
	delete[] this->data;
}

unsigned int Image::GetWidth() const {
	return this->height;
}

unsigned int Image::GetHeight() const {
	return this->width;
}

unsigned char * Image::GetData() {
	return this->data;
}

const unsigned char * Image::GetData() const {
	return this->data;
}

void Image::SetColor(unsigned int x, unsigned int y, const Color &color) {
	this->data[y*GetWidth()*3 + x*3 + 0] = color.red;
	this->data[y*GetWidth()*3 + x*3 + 1] = color.green;
	this->data[y*GetWidth()*3 + x*3 + 2] = color.blue;
}

Color Image::GetColor(unsigned int x, unsigned y) const{
	return new Color(
			this->data[y*GetWidth()*3 + x*3 + 0],
			this->data[y*GetWidth()*3 + x*3 + 1],
			this->data[y*GetWidth()*3 + x*3 + 2]);
}

void Image::Fill(const Color &color) {
	for(unsigned int y = 0; y < GetHeight(); ++y) {
		for(unsigned int x = 0; x < GetWidth(); ++x) {
			SetColor(x,y,color);
		}
	}
}
