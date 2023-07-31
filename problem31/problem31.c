#include <stdio.h>

int main() {
    int count = 0;

    for (int one = 0; one <= 200; one++) {
        for (int two = 0; two <= 100; two++) {
            for (int five = 0; five <= 40; five++) {
                for (int ten = 0; ten <= 20; ten++) {
                    for (int twenty = 0; twenty <= 10; twenty++) {
                        for (int fifty = 0; fifty <= 4; fifty++) {
                            for (int one_pound = 0; one_pound <= 2; one_pound++) {
                                for (int two_pound = 0; two_pound <= 1; two_pound++) {
                                    if ((one * 1) + (two * 2) + (five * 5) + (ten * 10) + (twenty * 20)
                                        + (fifty * 50) + (one_pound * 100) + (two_pound * 200) == 200) {
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
