#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point2 {
	int x;
	int y;
};

void print_point2(struct Point2 p)
{
	printf("Point 2: (%d, %d)\n", p.x, p.y);
}

void print_point(struct Point p) {
    printf("Point: (%d, %d)\n", p.x, p.y);
}

int main() {
    // Using a compound literal to create a temporary Point object
    print_point((struct Point){10, 20});

    print_point2((struct Point2){5, 4});
    
    return 0;
}
