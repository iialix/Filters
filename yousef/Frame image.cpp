#include <iostream>
#include <cstdlib>
using namespace std;

#include "Image_Class.h"

int main() {
    string filename;
    cout << "Please enter  image name to put frame in it: ";
    cin >> filename;
    Image image(filename);
    char choose;
    
    
    while (true)
    {
        char choose;
        cout << " Please choose what you want "<< endl;
        cout << " 1) Simple frame " <<endl ;
        cout << " 2) Fancy frame " <<endl;
        cout << "Enter (1/2): ";
        cin >> choose;
        
        if (choose == '1' )
        { 
            for (int i = 0; i < image.width; ++i)
            {
                for (int j = 0; j < image.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        if(i < 10 || i > image.width - 11 )
                        {
                            image (i,j,0) = 0;
                            image (i,j,1) = 0;
                            image (i,j,2) = 220;
                        }
                        else if (j < 10 || j > image.height - 11)
                        {
                            image (i,j,0) = 0;
                            image (i,j,1) = 0;
                            image (i,j,2) = 220;
                        }
                    }
                }
            }
          break;  
        }
        else if (choose == '2' )
        {
            for (int i = 0; i < image.width; ++i)
            {
                for (int j = 0; j < image.height; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        if (i < 10 || i > image.width - 11 )
                        {
                            image (i,j,0) = 0;
                            image (i,j,1) = 0;
                            image (i,j,2) = 220;
                        }
                        else if ((i < 30 && i > 9) || (i > image.width - 31 && i < image.width - 10 ))
                        {
                            if((j < 30 && j > 9) || (j > image.height - 31 && j < image.height - 10))
                            {
                                image (i,j,0) = 255;
                                image (i,j,1) = 255;
                                image (i,j,2) = 255;
                            }    
                        
                        }
                        if ((i < 17 && i > 9) || (i > image.width - 18 && i < image.width - 10 ))
                        {
                            if(j > 9 && j < image.height - 10)
                            {
                                image (i,j,0) = 255;
                                image (i,j,1) = 255;
                                image (i,j,2) = 255;
                            }    
                        
                        }
                        if ((j < 17 && j > 9) || (j > image.height - 18 && j < image.height - 10) )
                        {
                            if (i > 9 && i < image.width -10 )
                            {
                                image (i,j,0) = 255;
                                image (i,j,1) = 255;
                                image (i,j,2) = 255;
                            }
                        }

                        if (j < 10 || j > image.height - 11)
                        {
                            image (i,j,0) = 0;
                            image (i,j,1) = 0;
                            image (i,j,2) = 220;
                        }
                        if ((i > 45 && i < 50) && ((j < 50 && j > 9) || (j > image.height - 51 && j < image.height - 10)))
                        {
                            image (i,j,0) = 255;
                            image (i,j,1) = 255;
                            image (i,j,2) = 255;
                        }
                        if ((i < image.width - 41 && i > image.width - 46) && ((j < 50 && j > 9) || (j > image.height - 51 && j < image.height - 10)))
                        {
                            image (i,j,0) = 255;
                            image (i,j,1) = 255;
                            image (i,j,2) = 255;
                        }
                        if ((j > 45 && j < 50) && ((i < 50 && i > 9) || (i > image.width - 45 && i < image.width - 9)))
                        {
                            image (i,j,0) = 255;
                            image (i,j,1) = 255;
                            image (i,j,2) = 255;
                        }
                        if ((j < image.height - 50 && j > image.height - 55) && ((i < 50 && i > 9) || (i > image.width - 45 && i < image.width - 10)))
                        {
                            image (i,j,0) = 255;
                            image (i,j,1) = 255;
                            image (i,j,2) = 255;
                        }
                    }
                }
            }
        break;  
        }
        else
        {
            cout << "Invalid input"<< endl;
        }
    }
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    system(filename.c_str());
    image.saveImage(filename);
    return 0;



}
