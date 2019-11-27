// box.cpp - box

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/09/05

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#include "box.hpp"
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>

template<typename Iter>
void
list_elements(Iter begin, Iter end)
{
    size_t perline{6};
    size_t count{};
    while (begin != end) {
        std::cout << *begin++;
        if (++count % perline == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

int
main(void)
{
    std::forward_list<Box> boxes;
    std::copy(std::istream_iterator<Box>(std::cin),
              std::istream_iterator<Box>(), std::front_inserter(boxes));

    boxes.sort();
    std::cout << "\nAfter sorting the sequence is:\n";
    std::copy(std::begin(boxes), std::end(boxes),
              std::ostream_iterator<Box>(std::cout, " "));
    std::cout << std::endl;

    std::forward_list<Box> more_boxes{Box{3, 3, 3}, Box{5, 5, 5}, Box{4, 4, 4},
                                      Box{2, 2, 2}};
    boxes.insert_after(boxes.before_begin(), std::begin(more_boxes),
                       std::end(more_boxes));
    std::cout << "After inserting more boxes the sequence is:\n";
    list_elements(std::begin(boxes), std::end(boxes));

    boxes.sort();
    std::cout << std::endl;
    std::cout << "The sorted sequence is now:\n";
    list_elements(std::begin(boxes), std::end(boxes));

    more_boxes.sort();
    boxes.merge(more_boxes);
    std::cout << "After merging more_boxes the sequence is:\n";
    list_elements(std::begin(boxes), std::end(boxes));

    boxes.unique();
    std::cout << "After removing successive duplicates the sequence is:\n";
    list_elements(std::begin(boxes), std::end(boxes));

    const double max_v{30.0};
    boxes.remove_if([max_v](const Box &box) { return box.volume() < max_v; });
    std::cout << "After removing those with volume less than 30 the sorted "
                 "sequence is:\n";
    list_elements(std::begin(boxes), std::end(boxes));
    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o box box.cpp -g "
// End:
