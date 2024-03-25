#include <iostream>
#include <cstdlib>

using namespace std;

#include "Image_Class.h"

int main()
{
    string image1;
    cout << "Pls enter the name of the first image: ";
    cin >> image1;

    string image2;
    cout << "Pls enter the name of the second image: ";
    cin >> image2;

    Image fimage(image1);
    Image simage(image2);
    Image newimage(simage.width, simage.height); 

    for (int i = 0; i < fimage.width; ++i)
    {
        for (int j = 0; j < fimage.height; ++j)
        {
            unsigned int blue_avg, green_avg, red_avg;
            blue_avg = green_avg = red_avg = 0;
            for (int k = 0; k < 3; ++k)
            {
                
            }
            blue_avg = fimage(i, j, 2) + simage(i, j, 2);
            green_avg = fimage(i, j, 1) + simage(i, j, 1);
            red_avg = fimage(i, j, 0) + simage(i, j, 0);

            newimage(i, j, 0) = red_avg / 2;
            newimage(i, j, 1) = green_avg / 2;
            newimage(i, j, 2) = blue_avg / 2;
        }
    }
    string imagename;
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imagename;

    newimage.saveImage(imagename);
    system(imagename.c_str());




    return 0;
}
 
