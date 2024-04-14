#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Image_Class.h"

using namespace std;

int main()
{
    string image1;
cout << "Pls enter the name of the first image: ";
cin >> image1;

string image2;
cout << "Pls enter the name of the second image: ";
cin >> image2;

// Create Image objects for both images....
Image fimage(image1);


int width, height;
width = fimage.width;
height = fimage.height;
Image image(file);

    Image newimage(width, height);

    float wratio, hratio;
    wratio = image.width / static_cast<float>(width);
    hratio = image.height / static_cast<float>(height);

    // Parallelize the resizing process using OpenMP
#pragma omp parallel for collapse(2)
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int x = round(i * wratio);
            int y = round(j * hratio);

            // Ensure the calculated indices are within bounds
            x = max(0, min(image.width - 1, x));
            y = max(0, min(image.height - 1, y));

            for (int k = 0; k < 3; ++k) {
                newimage(i, j, k) = image(x, y, k);
            }
        }
    }

Image simage = newimage;


// Create a new image to store the merged result....
Image newimage(width, height);

// Merge pixels of both images within the overlapping region....
for (int i = 0; i < width; ++i)
{
    for (int j = 0; j < height; ++j)
    {
        unsigned int blue_avg, green_avg, red_avg;
        blue_avg = green_avg = red_avg = 0;

        // Calculate average of RGB values from both images....
        for (int k = 0; k < 3; ++k)
        {
            blue_avg = fimage(i, j, 2) + simage(i, j, 2);
            green_avg = fimage(i, j, 1) + simage(i, j, 1);
            red_avg = fimage(i, j, 0) + simage(i, j, 0);
        }

        // Set new pixel values....
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
}
 
