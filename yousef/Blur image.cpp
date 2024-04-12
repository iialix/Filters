#include <iostream>
#include <cstdlib>
using namespace std;

#include "Image_Class.h"

int main() {
    string filename;
    cout << "Please enter colored image name to blur : ";
    cin >> filename;
    Image image(filename);
    Image blured_image (image.width,image.height);

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        blured_image(i, j, k) = (image(i+1 ,j , k) + image(i ,j+1 , k) + image(i+1 ,j+1, k) + image(i,j,k))/4;   
                    }
                    else if (j == image.height-1)
                    {
                        blured_image(i, j, k) = (image(i+1 ,j , k) + image(i ,j-1 , k) + image(i+1 ,j-1, k) + image(i,j,k))/4;
                    }
                    else
                    {
                        blured_image(i, j, k) = ( image(i ,j-1 , k)   + image(i+1 ,j , k) + image(i ,j+1 , k) + image (i+1 ,j-1 ,k) + image (i+1 ,j+1 ,k) + image(i,j,k))/6;
                    }
                }
                else if (i == image.width-1)
                {
                    if (j == 0)
                    {
                        blured_image(i, j, k) = (image(i-1 ,j , k) + image(i ,j+1 , k) + image(i-1 ,j+1, k) + image(i,j,k))/4;
                    }
                    else if (j == image.height-1)
                    {
                        blured_image(i, j, k) = (image(i-1 ,j , k) + image(i ,j-1 , k) + image(i-1 ,j-1, k) +image(i,j,k))/4;
                    }
                    else
                    {
                        blured_image(i, j, k) = ( image(i ,j-1 , k)   + image(i-1 ,j , k) + image(i ,j+1 , k) + image (i-1 ,j-1 ,k) + image (i-1 ,j+1 ,k) + image(i,j,k))/6;
                    }                
                }
                else if (j == 0)
                {
                   blured_image(i, j, k) = (image (i+1, j, k) + image (i-1, j, k) + image (i-1, j+1, k) + image (i, j+1, k) + image (i+1, j+1, k) + image(i,j,k))/6;
                }
                else if (j == image.height-1)
                {
                    blured_image(i ,j ,k) = (image (i+1, j, k) + image (i-1, j, k) + image (i-1, j-1, k) + image (i, j-1, k) + image (i+1, j-1, k) + image(i,j,k))/6;
                }
                else if(i < 2 || j < 2)
                {
                    blured_image(i ,j ,k) = (image(i+1, j, k) + image(i, j+1, k) + image(i+1, j+1, k) + image(i-1, j, k) + image(i, j-1, k) + image(i-1, j+1, k) + image(i+1, j-1, k) + image(i-1, j-1, k) + image(i,j,k) )/9;
                }
                else if (i >= 2 && j >= 2 && i < image.width - 2 && j < image.height - 2)
                {
                    blured_image(i ,j ,k) = (image(i+1, j, k) + image(i, j+1, k) + image(i+1, j+1, k) + image(i-1, j, k) + image(i, j-1, k) + image(i-1, j+1, k) + image(i+1, j-1, k) + image(i-1, j-1, k) + image(i,j,k) + image(i+2,j,k) + image(i,j+2,k) + image(i,j-2,k) + image(i-2,j,k) + image(i-2,j+1,k) + image(i+2,j+1,k) + image(i-1,j+2,k) + image(i-2,j+2,k) + image(i+1,j+2,k) + image(i+2,j+2,k) + image(i+2,j-1,k) + image(i-2,j-1,k) + image(i-1,j-2,k) + image(i-2,j-2,k) + image(i+1,j-2,k) + image(i+2,j-2,k))/25;
                }
            }
        }
    }

    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    blured_image.saveImage(filename);
    system(filename.c_str());
    return 0;



}
