//outputing a ppm file
//a way to see the image by storing it into a file?

#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream> //input & output stream


int main() {

    //Image -- VER 1
    //int image_width = 256;
    //int image_height = 256;

    //rendered image set up -- VER 2
    auto aspect_ratio = 16.0/9.0; //ideal ratio, may not be the actual one
    int image_width = 400;

    //Calculate the image height, and ensure that it's at least 1
    int image_height = int(image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; //ternary operator
    //this is equivalent to:
        //if (image_height < 1) {
        //image_height = 1;
        //} else {
        //image_height = image_height;
        //}

    //Viewport widths less than one are ok since they are real valued
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);

















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