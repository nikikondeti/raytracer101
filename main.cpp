//outputing a ppm file
//a way to see the image by storing it into a file?

#include "color.h"
#include "vec3.h"
#include <iostream> //input & output stream

int main() {

    //Image
    int image_width = 256;
    int image_height = 256;

    //Render

    std:: cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j=0; j < image_height; j++) { //picks a row
        std:: clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std:: flush; //progress indicator
        for (int i = 0; i < image_width; i++) { //picks a pixel in that row

           // auto r = double(i) / (image_width-1);
          //  auto g = double(j) / (image_height-1);
           // auto b = 0.0;

          //  int ir = int(255.99 * r);
           // int ig = int(255.99 * g);
           // int ib = int(255.99 * b);

            //std:: cout << ir << ' ' << ig << ' ' << ib << '\n';


            //CAN REPLACE ALL THIS COMMENTED OUT STUFF WITH THE NEW FUNCTIONS FROM THE HEADER FILES
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std:: cout, pixel_color);
        }
    }

    std:: clog << "\rDone.                  \n";
}