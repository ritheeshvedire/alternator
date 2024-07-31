#include <iostream>

template <typename C1, typename C2>
class alternator {
public:
    using value_type = C1::value_type;

    alternator(const C1& c1, const C2& c2)
        : container1(c1), container2(c2) {}

    enum class CONTAINER { _1, _2 };

    class iterator {
    public:

        // cuurrent value to be returned depends on whether first container is empty

        iterator(C1::const_iterator it1, C1::const_iterator end1,
                C2::const_iterator it2, C2::const_iterator end2, CONTAINER turn)
            : iter1(it1), iter1_end(end1), iter2(it2), iter2_end(end2), current_turn(turn) {

            if (current_turn == CONTAINER::_1 && iter1 != iter1_end) {
                current_value = *iter1;
            } else if (current_turn == CONTAINER::_2 && iter2 != iter2_end) {
                current_value = *iter2;
            }
        }

        // ++ operator moves the iterators of containers in alternate fashion
        iterator& operator++() {
            switch (current_turn) {
                case CONTAINER::_1:
                    if (iter1 != iter1_end) {
                        ++iter1;
                    }
                    if (iter2 != iter2_end) {
                        current_value = *iter2;
                    }
                    current_turn = CONTAINER::_2;
                    break;

                case CONTAINER::_2:
                    if (iter2 != iter2_end) {
                        ++iter2;
                    }
                    if (iter1 != iter1_end) {
                        current_value = *iter1;
                    }
                    current_turn = CONTAINER::_1;
                    break;
            }
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return iter1 != other.iter1 || iter2 != other.iter2;
        }

        value_type operator*() const {
            return current_value;
        }

    private:
        C1::const_iterator iter1;
        C1::const_iterator iter1_end;
        C2::const_iterator iter2;
        C2::const_iterator iter2_end;

        CONTAINER current_turn;
        value_type current_value;
    };

    iterator begin() const {
        return iterator(container1.begin(), container1.end(), container2.begin(), container2.end(), CONTAINER::_1);
    }

    iterator end() const {
        return iterator(container1.end(), container1.end(), container2.end(), container2.end(), CONTAINER::_1);
    }

private:
    const C1& container1;
    const C2& container2;
};
