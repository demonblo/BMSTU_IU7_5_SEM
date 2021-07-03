#ifndef LAB7_PROG_CELL_H
#define LAB7_PROG_CELL_H


template<class TKey, class TVal>
class Cell {
private:
    TKey key;
    TVal value;
public:
    Cell(TKey& key, TVal& val);
    TKey getKey() const;
    TVal getVal() const;
};

template<class TKey, class TVal>
Cell<TKey, TVal>::Cell(TKey& key, TVal& val) : key(key), value(val) { ; }

template<class TKey, class TVal>
TKey Cell<TKey, TVal>::getKey() const { return key; }

template<class TKey, class TVal>
TVal Cell<TKey, TVal>::getVal() const { return value; }

#endif //LAB7_PROG_CELL_H
