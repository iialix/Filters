#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <omp.h> // OpenMP for parallelization

using namespace std;

#include "Image_Class.h"

int main() {
    string filename;
    cout << "Please enter the image name to resize: ";
    cin >> filename;

    Image image(filename);

    int height, width;
    cout << "Please enter the new height: ";
    cin >> height;
    cout << "Please enter the new width: ";
    cin >> width;

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

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;

    newimage.saveImage(filename);
    system(filename.c_str());

    return 0;
}

