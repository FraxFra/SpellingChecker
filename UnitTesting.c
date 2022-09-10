#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "EditDistance.h"

void test_edit_distance()
{
        assert(1 == edit_distance("casa", "cassa"));
        assert(1 == edit_distance("casa", "cassa"));
        assert(2 == edit_distance("vinaio", "vino"));
        assert(4 == edit_distance("tassa", "passato"));
        assert(0 == edit_distance("pioppo", "pioppo"));
        assert(0 == edit_distance(" ", " "));
}

void test_edit_distance_dyn()
{
        assert(1 == edit_distance_dyn("casa", "cassa"));
        assert(1 == edit_distance_dyn("casa", "cassa"));
        assert(2 == edit_distance_dyn("vinaio", "vino"));
        assert(4 == edit_distance_dyn("tassa", "passato"));
        assert(0 == edit_distance_dyn("pioppo", "pioppo"));
        assert(0 == edit_distance_dyn(" ", " "));
}

int main(int argc, char** argv)
{
        test_edit_distance();
        test_edit_distance_dyn();
        printf("All tests are passed!");
}
