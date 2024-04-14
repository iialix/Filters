void edge_detection()
{
    string filename;
    cout << "Pls enter the image name to detect edges: ";
    cin >> filename;

    Image image(filename);

    // Looping over all rows....
    for (int i = 0; i < image.width; ++i)
    {
        // Looping over all pixels in a row....
        for (int j = 0; j < image.height; ++j)
        {
            unsigned  int avg = 0;

            for (int k = 0; k < 3; ++k)
            {
                // Calculate sum of all channels....
                avg += image(i, j, k);
            }
            // Divide sum by 3 to get average....
            avg /= 3;

            // If average is closer to black make it black....
            if (avg < 128)
            {
                image(i, j, 0) = 0;
                image(i, j, 1) = 0;
                image(i, j, 2) = 0;
            }
            // If average is closer to white make it white....
            else
            {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }
    Image copied(image.width, image.height);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                copied(i, j, k) = image(i, j, k);
            }
        }
    }

    bool previous = false;
    bool next = false;
    bool down = false;
    bool up = false;

    for (int i = 1; i < image.width - 1; i++)
    {
        for (int j = 1; j < image.height - 1; j++)
        {
            if (copied(i + 1, j, 0) == 0) next = true;
            else next = false;

            if (copied(i - 1, j, 0) == 0) previous = true;
            else previous = false;

            if (copied(i , j + 1, 0) == 0) up = true;
            else up = false;

            if (copied(i, j - 1, 0) == 0) down = true;
            else down = false;

            if (!(copied(i,j, 0) == 0 && (previous == false || next == false || up == false || down == false)))
            {
                for (int k = 0; k < 3; k++)
                {
                    image(i, j, k) = 255;
                }
            }
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    // Open image after saving it....
    system(filename.c_str());
}
