void flip_image()
{
    cout << "A) Horizontal flip\n";
    cout << "B) vertical flip\n";
    cout << "pls enter a choice (A/B): ";
    char choice;
    cin >> choice;

    if (toupper(choice) == 'A')
    {
        string filename;
        cout << "Pls enter the image name to flip horizontally: ";
        cin >> filename;

        Image image(filename);
        // Looping over all rows....
        for (int i = 0; i < image.width / 2; ++i)
        {
            // Looping over all pixels in a row....
            for (int j = 0; j < image.height; ++j)
            {
                for (int k = 0; k < 3; k++)
                {
                    int tmp = image(i, j, k);
                    image(i, j, k) = image(image.width - i, j, k);
                    image(image.width - i, j, k) = tmp;
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
    else if (toupper(choice) == 'B')
    {
        string filename;
        cout << "Pls enter the image name to flip vertically: ";
        cin >> filename;

        Image image(filename);
        // Looping over all rows....
        for (int i = 0; i < image.width; ++i)
        {
            // Looping over all pixels in a row....
            for (int j = 0; j < image.height / 2; ++j)
            {
                for (int k = 0; k < 3; k++)
                {
                    int tmp = image(i, j, k);
                    image(i, j, k) = image(i, image.height - j, k);
                    image(i, image.height - j, k) = tmp;
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
}
