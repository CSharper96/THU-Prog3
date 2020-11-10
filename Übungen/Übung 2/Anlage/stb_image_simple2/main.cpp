#include <iostream>
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int, char**) {
    const char* fn = "../blume2.png"; // read image...
    int c,w,h;
    stbi_uc* idata = stbi_load(fn, &w, &h, &c, 1);
    assert(idata);
    stbi_uc* odata = reinterpret_cast<stbi_uc*>(stbi__malloc(w*h));
    std::cout << fn << ":" << w << "x" << h << "\n";

    int b = 3; // draw border...
    for (int y=0;y<h;y++) {
        for (int x=0;x<w;x++) {
            int index = x+y*w;
            if (x==b || y==b || x==w-b-1 || y==h-b-1) {
                odata[index] = 255*(((x+y)/6)%2);
            }
            else {
                odata[index] = idata[index];
            }
        }
    }
    // save result...
    stbi_write_png("output.png", w, h, 1, odata, w);
    stbi_image_free(idata);
    stbi_image_free(odata);
}
