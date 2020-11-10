#include <iostream>
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Image
{
private:
    int c, w, h;
    stbi_uc *data;

    // TODO
public:
    //Die Klasse Image soll einen Konstruktor anbieten, um ein PNG Bild als Grauwertbild zu laden.
    Image(const char *filename)
    {
        data = stbi_load(filename, &w, &h, &c, 1); 
        std::cout << filename << ":" << w << "x" << h << " with channels: " << c << "\n";
    }

    //Die Klasse Image soll einen Konstruktor anbieten, um Grauwertbild einer bestimmten Groesse anzulegen.
    Image(const int &width, const int &height)
    {
        h = height;
        w = width;
        c = 3;
        data = reinterpret_cast<stbi_uc *>(stbi__malloc(w * h));
        std::cout << "out:" << w << "x" << h << " with channels: " << c << "\n";
    }

    void write_png(const char *image)
    {
        stbi_write_png(image, w, h, c, data, 1);
    }

    //Die Klasse soll im Destruktor angelegten Speicher wieder freigeben.
    ~Image()
    {
        stbi_image_free(data);
    }

    //Ein Image Objekt soll es erlauben, die Bildgr”áe abzufragen ("getWidth", "getHeight").
    int getHeight() const { return h; }
    int getWidth() const { return w; }

    //Ein Image Objekt soll eine effiziente Zugriffsfunktion "get" anbieten (zero-overhead durch
    //Funktionsaufruf), um Grauwerte an einer bestimmten Koordinate auszulesen.
    inline int get(int x, int y) const
    {
        //if data exists on this position
        int pos = y*(w)+(x);
        return data[pos];
    }

    //Ein Image Objekt soll eine effiziente Zugriffsfunktion "set" anbieten (zero-overhead durch
    //Funktionsaufruf), um einen Grauwert an einer bestimmten Koordinate zu setzen.
    inline void set(int &x, int &y, int value)
    {

        int pos = 0;
        // for (int i = 0; i < y; i++)
        // {
        //     for (int k = 0; k < x-1; k++)
        //     {
        //         pos++;
        //     }
        // }
        

        pos = y*(w)+(x);
        data[pos] = value;
    }
};

/** 
 * @brief simple "draw border" example. 
 * @param inp: input image (read only)
 * @param b: border position
 * @param d: dash size
 * @param out: output image (must have same size as input image)
 */
void border(const Image &inp, int b, int d, Image &out)
{
    assert(inp.getWidth() == out.getWidth());
    assert(inp.getHeight() == out.getHeight());
    for (int y = 0; y < inp.getHeight(); y++)
    {
        for (int x = 0; x < inp.getWidth(); x++)
        {
            if (x == b || y == b || x == inp.getWidth() - b - 1 || y == inp.getHeight() - b - 1)
            {
                out.set(x, y, 255 * (((x + y) / d) % 2));
            }
            else
            {
                out.set(x, y, inp.get(x, y));
            }
        }
    }
}

/** 
 * @brief trivial box filter implementation.
 * @param inp: input image (read only)
 * @param b: blur size
 * @param out: output image (must have same size as input image)
 */
void blur(const Image &inp, int b, Image &out)
{
    assert(inp.getWidth() == out.getWidth());
    assert(inp.getHeight() == out.getHeight());
    for (int y = 0; y < inp.getHeight(); y++)
    {
        for (int x = 0; x < inp.getWidth(); x++)
        {
            int x1 = x - b / 2;
            int x2 = x1 + b;
            int y1 = y - b / 2;
            int y2 = y1 + b;
            if (x1 < 0)
                x1 = 0;
            if (y1 < 0)
                y1 = 0;
            if (x2 >= inp.getWidth())
                x2 = inp.getWidth();
            if (y2 >= inp.getHeight())
                y2 = inp.getHeight();
            int sum = 0;
            int total = 0;
            for (int yy = y1; yy < y2; yy++)
            {
                for (int xx = x1; xx < x2; xx++)
                {
                    sum += inp.get(xx, yy);
                    total++;
                }
            }
            out.set(x, y, sum / total);
        }
    }
}

int main(int, char **)
{
    Image inp{"../blume2.png"};
    Image out{inp.getWidth(), inp.getHeight()};
    std::cout << out.getWidth() << "x" << out.getHeight();
    border(inp, 5, 1, out);
    out.write_png("../output_border_01.png");
    border(inp, 5, 6, out);
    out.write_png("../output_border_06.png");
    border(inp, 5, 24, out);
    out.write_png("../output_border_24.png");
    blur(inp, 5, out);
    out.write_png("../output_blur_05.png");
    blur(inp, 15, out);
    out.write_png("../output_blur_15.png");
}
