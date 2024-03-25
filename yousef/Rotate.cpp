#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    char choice;
    cout << "Please enter colored image name to rotate its colours: ";
    cin >> filename;
    Image image(filename);
    Image rotatedImage_90(image.height, image.width);
    Image rotatedImage_180(image.width, image.height);
    Image rotatedImage_270(image.height, image.width);
    cout << "How many degree you want to rotate? " <<endl;
    cout << "A) 90 degree " << endl;
    cout << "B) 180 degree " << endl;
    cout << "C) 270 degree " << endl;
    cin >> choice;
    if (choice == 'A' || choice == 'a' )
    {
    for (int i = 0; i < image.width; ++i) 
    {
        for (int j = 0; j < image.height; ++j) 
        {
            for(int k = 0; k < 3; ++k) 
            {
                rotatedImage_90(j,(image.width-1)-i,k) = image(i,j,k);
            }
        }
    }
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    rotatedImage_90.saveImage(filename);
    }
    else if (choice == 'b' || choice == 'B')
    {
    for (int i = 0; i < image.width; ++i) 
    {
        for (int j = 0; j < image.height; ++j) 
        {
            for(int k = 0; k < 3; ++k) 
            {
                rotatedImage_180((image.width-1)-i,(image.height-1)-j,k) = image(i,j,k);
                
            }
        }
    }
    
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    rotatedImage_180.saveImage(filename);

    }
    else if (choice == 'C' || choice == 'c')
    {
            for (int i = 0; i < image.width; ++i) 
            {
                for (int j = 0; j < image.height; ++j) 
                {
                    for(int k = 0; k < 3; ++k) 
                    {
                        rotatedImage_270((image.height-1)-j,i,k) = image(i,j,k);
                    }
                }
            }
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    rotatedImage_270.saveImage(filename);
    }
    


    return 0;
}
