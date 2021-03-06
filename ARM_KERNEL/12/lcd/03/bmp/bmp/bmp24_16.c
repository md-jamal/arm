#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/mman.h>

#define DEVNAME "/dev/fb0"

typedef unsigned int u32;
typedef unsigned short u16;

struct bmp_pixel_t {
    unsigned char b;
    unsigned char g;
    unsigned char r;
};

struct fb_pixel_t {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
};

int main(int argc, char *argv[])
{
    int fd, fb;
    char magic[2];
    int w, h;
    int i, j;
    short bpp;
    int offset;
    struct bmp_pixel_t p;
    struct fb_pixel_t *map;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s bmpfile\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    read(fd, magic, 2);
    if (memcmp(magic, "BM", 2))
    {
        fprintf(stderr, "unkown format.\n");
        return -1;
    }

    lseek(fd, 10, SEEK_SET);
    read(fd, &offset, sizeof(int));

    lseek(fd, 18, SEEK_SET);
    read(fd, &w, sizeof(int));
    read(fd, &h, sizeof(int));

    lseek(fd, 28, SEEK_SET);
    read(fd, &bpp, sizeof(short));

    printf("[%s] %d x %d x %d\n", argv[1], w, h, bpp);

    struct fb_pixel_t white = { 0xff, 0xff, 0xff, 0xff };

    lseek(fd, offset, SEEK_SET);


	int fdo = open("./bmp16", O_TRUNC | O_CREAT | O_RDWR , 0777);
	if( fdo == -1 ) {
		printf("error.\n");
		return -1;
	}

	u16 bmp16;
    for (i = h-1; i >= 0; --i)
    {
		lseek( fdo, i * w * 2, 0 );
        for (j = 0; j < w; ++j)
        {
            read(fd, &p, sizeof(p));

			bmp16 = 0;
			bmp16 = p.b >> 3;
			bmp16 |= (p.g>>2) << 5;
			bmp16 |= (p.r>>3) << 11;

			write( fdo, &bmp16, 2 );
        }
    }

	close( fdo );

    return 0;
}
