#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Please enter colored image name to invert its colours: ";
    cin >> filename;
    Image image(filename);

    for (int i = 0; i < image.width; ++i) 
    {
        for (int j = 0; j < image.height; ++j) 
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i,j,k) = 255-image(i,j,k);
            }
        }
    }

    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "; 
    cin >> filename;
    image.saveImage(filename);

    return 0;



}