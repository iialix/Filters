void crop_image()
{
    string filename;
    cout << "Please enter the image name you want to crop: ";
    cin >> filename;
    Image image(filename);

    int x, y, w, h;
    cout << "pls enter x: ";
    cin >> x;

    cout << "pls enter y: ";
    cin >> y;

    cout << "pls enter W: ";
    cin >> w;

    cout << "pls enter H: ";
    cin >> h;

    Image cropped_img(w, h);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cropped_img(i, j, k) = image(x + i, y + j, k);
            }
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    cropped_img.saveImage(filename);
    system(filename.c_str());
}
