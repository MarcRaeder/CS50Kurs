#include "helpers.h"
#include "math.h"

void copy_gets_image(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }

    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }

    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }

        for (int k = 0; k < height; k++)
        {
            for (int l = 0; l < width; l++)
            {
                int totalRed, totalGreen, totalBlue;
                totalRed = totalGreen = totalBlue = 0;
                float counter = 0.00;

                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        int currentX = i + x;
                        int currentY = l + y;

                        if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                        {
                            continue;
                        }

                        totalRed += image[currentX][currentY].rgbtRed;
                        totalGreen += image[currentX][currentY].rgbtGreen;
                        totalBlue += image[currentX][currentY].rgbtBlue;

                        counter++;
                    }

                    copy[i][l].rgbtRed = round(totalRed / counter);
                    copy[i][l].rgbtGreen = round(totalGreen / counter);
                    copy[i][l].rgbtBlue = round(totalBlue / counter);
                }
            }
        }
    }
    copy_gets_image(height, width, image, copy);

    return;
}

void copy_gets_image(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }

    return;
}
