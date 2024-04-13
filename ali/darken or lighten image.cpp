#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#include "Image_Class.h"

int main()
{
	string filename;
	cout << "Pls enter colored image name to turn to gray scale: ";
	cin >> filename;

	Image image(filename);

	string choice;
	cout << "please enter what you want to do: \n";
	cout << "A) make the image darker by 50%\n";
	cout << "B) make the image lighter by 50%\n";
	cin >> choice;

	if (choice == "a" || choice == "A")
	{
		for (int i = 0; i < image.width; ++i)
		{
			for (int j = 0; j < image.height; ++j)
			{

				for (int k = 0; k < 3; ++k)
				{
					image(i, j, k) = image(i, j, k) / 2;
				}
			}
		}
	}

	else if (choice == "b" || choice == "B")
	{
		for (int i = 0; i < image.width; ++i)
		{
			for (int j = 0; j < image.height; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					int newValue = static_cast<int>(image(i, j, k) * 1.5);
					newValue = std::min(newValue, 255); 
					image(i, j, k) = static_cast<unsigned char>(newValue);

					

				}

			}
		}
	}

	cout << "Pls enter image name to store new image\n";
	cout << "and specify extension .jpg, .bmp, .png, .tga: ";

	cin >> filename;
	image.saveImage(filename);
	// Output the grayscale image after saving it....
	system(filename.c_str());

}