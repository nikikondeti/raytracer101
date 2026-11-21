//outputing a ppm file
//a way to see the image by storing it into a file?

#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream> //input & output stream
color ray_color(const ray& r) {
    return color(0,0,0); //set to always return black for now
}

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
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = point3(0,0,0);

    //Don't really understand how to create scene rays?
    //Calculate the vectors across the horizontal and down the vertical viewport edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    //Calculate the horizontal and vertical delta vectors from pixel to pixel
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height

    //Calculate the location of the upper left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel100_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    

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
           //auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            //std:: cout << ir << ' ' << ig << ' ' << ib << '\n';

            //CAN REPLACE ALL THIS COMMENTED OUT STUFF WITH THE NEW FUNCTIONS FROM THE HEADER FILES
            auto pixel_center = pixel100_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std:: cout, pixel_color);
        }
    }

    std:: clog << "\rDone.                  \n";


   

}