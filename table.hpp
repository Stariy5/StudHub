#include <cstddef>
#include <iostream>
#include <cassert>
#include <limits>

template<typename Key, typename Data>
class Table;

template<typename Key, typename Data>
struct KeySpace
{
    Key key;
    Data data;
};

template<typename Key, typename Data>
class TableIterator
{
public:
    typedef ptrdiff_t difference_type;

    typedef Data value_type;

    typedef Data *pointer;

    typedef Data &reference;

    typedef std::random_access_iterator_tag iterator_category;

    TableIterator() noexcept;

    TableIterator(const TableIterator<Key, Data> &o) noexcept;

    TableIterator<Key, Data> &operator=(const TableIterator<Key, Data> &o) noexcept;

    reference operator*() const noexcept;

    pointer operator->() const noexcept;

    size_t index();

    bool operator==(const TableIterator<Key, Data> &other) const noexcept;

    bool operator!=(const TableIterator<Key, Data> &other) const noexcept;

    bool operator<(const TableIterator<Key, Data> &other) const noexcept;

    bool operator>(const TableIterator<Key, Data> &other) const noexcept;

    bool operator<=(const TableIterator<Key, Data> &other) const noexcept;

    bool operator>=(const TableIterator<Key, Data> &other) const noexcept;

    reference operator[](int index);

    TableIterator &operator++() noexcept;

    TableIterator operator++(int) noexcept;

    TableIterator &operator--() noexcept;

    TableIterator operator--(int) noexcept;

    TableIterator operator+(int n) const noexcept;

    TableIterator operator-(int n) const noexcept;

    ptrdiff_t operator-(const TableIterator<Key, Data> &other) const noexcept;

    TableIterator &operator+=(ptrdiff_t n);

private:
    typedef KeySpace<Key, Data> *ks_ptr_t;

    ks_ptr_t ks_; // пара на которую указывает итератор

    explicit TableIterator(ks_ptr_t pair);

    friend Table<Key, Data>;

};


template<typename Key, typename Data>
TableIterator<Key, Data>::TableIterator(TableIterator::ks_ptr_t pair) : ks_(pair)
{
}

template<typename Key, typename Data>
TableIterator<Key, Data>::TableIterator() noexcept : ks_(nullptr)
{
}

template<typename Key, typename Data>
TableIterator<Key, Data>::TableIterator(const TableIterator<Key, Data> &o) noexcept
: ks_(o.ks_)
{
}

template<typename Key, typename Data>
TableIterator<Key, Data> &
TableIterator<Key, Data>::operator=(const TableIterator<Key, Data> &o) noexcept
{
    if(this != &o)
    { ks_ = o.ks_; }
    return *this;
}

template<typename Key, typename Data>
TableIterator<Key, Data>::reference &TableIterator<Key, Data>::operator*() const noexcept
{
    return ks_->data;
}

template<typename Key, typename Data>
TableIterator<Key, Data>::pointer TableIterator<Key, Data>::operator->() const noexcept
{
    return &ks_->data;
}

template<typename Key, typename Data>
size_t TableIterator<Key, Data>::index()
{
    return static_cast<size_t>(this->ks_ - ks_);
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator==(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ == other.ks_;
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator!=(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ != other.ks_;
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator<(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ < other.ks_;
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator>(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ > other.ks_;
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator<=(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ <= other.ks_;
}

template<typename Key, typename Data>
bool TableIterator<Key, Data>::operator>=(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ >= other.ks_;
}

template<typename Key, typename Data>
TableIterator<Key, Data>::reference TableIterator<Key, Data>::operator[](int index)
{
    return (ks_ + index)->data;
}

template<typename Key, typename Data>
TableIterator<Key, Data> &TableIterator<Key, Data>::operator++() noexcept
{
    ++ks_;
    return *this;
}

template<typename Key, typename Data>
TableIterator<Key, Data> TableIterator<Key, Data>::operator++(int) noexcept
{
    TableIterator res(ks_);
    ++ks_;
    return res;
}

template<typename Key, typename Data>
TableIterator<Key, Data> &TableIterator<Key, Data>::operator--() noexcept
{
    --ks_;
    return *this;
}

template<typename Key, typename Data>
TableIterator<Key, Data> TableIterator<Key, Data>::operator--(int) noexcept
{
    TableIterator res(ks_);
    --ks_;
    return res;
}

template<typename Key, typename Data>
TableIterator<Key, Data> TableIterator<Key, Data>::operator+(int n) const noexcept
{
    return TableIterator(ks_ + n);
}

template<typename Key, typename Data>
TableIterator<Key, Data> TableIterator<Key, Data>::operator-(int n) const noexcept
{
    return TableIterator(ks_ - n);
}

template<typename Key, typename Data>
ptrdiff_t
TableIterator<Key, Data>::operator-(const TableIterator<Key, Data> &other) const noexcept
{
    return ks_ - other.ks_;
}

template<typename Key, typename Data>
TableIterator<Key, Data> &TableIterator<Key, Data>::operator+=(ptrdiff_t n)
{
    ks_ += n;
    return *this;
}

template<typename Key, typename Data>
class Table
{
private:
    typedef KeySpace<Key, Data> ks_t;
    size_t size_;
    size_t capacity_;
    ks_t *ks_; // таблица должна иметь в себе все пр-во сущ-их ключей, а итератор только один элемент из пр-ва на который он указывает



public:
    typedef TableIterator<Key, Data> iterator;

//    typedef TableIterator<Key, Data, true> const_iterator;

    Table() noexcept;

    Table(const Table &other)
    requires std::copy_constructible<Data>;

    Table(Table &&other) noexcept;

    ~Table();

    iterator begin() const noexcept
    {
        return iterator(&ks_[0]);
    };

    iterator end() const noexcept
    {
        return iterator(&ks_[size_]);
    };

//    const_iterator cbegin() noexcept;
//
//    const_iterator cend() noexcept;

    Data &operator[](size_t i);

    const Data &operator[](size_t i) const;


//    iterator insert(const_iterator p, const Data &d)
//    requires std::copy_constructible<Data>;

    iterator find_elem(const Key &key);

    void remove_elem(const Key &key);

    void show_table();

    void push_back(const Key &key, const Data &data);

    [[nodiscard]] size_t get_size() const;

//    friend void StudHub::show_all_department_group(Table<size_t, IStudyingGroup> &table, size_t department);
};

template<typename Key, typename Data>
Table<Key, Data>::~Table()
{
    delete[] ks_;
}

template<typename Key, typename Data>
size_t Table<Key, Data>::get_size() const
{
    return size_;
}

template<typename Key, typename Data>
void Table<Key, Data>::remove_elem(const Key &key)
{
    iterator it = find_elem(key);
    if (it == this->end()) std::cout << "This group does not exist :(" << std::endl;

    else
    {
        for (size_t i = it.index(); i < size_; ++i)
        {
            std::cout << "Number of iteration - " << i << std::endl;
            ks_[i] = ks_[i + 1];
        }
        --size_;
    }
}

template<typename Key, typename Data>
void Table<Key, Data>::show_table()
{
    if (size_ == 0) std::cout << "No one group here" << std::endl;

    for (size_t i = 0; i < size_; ++i)
    {
        std::cout << "Group " << i + 1 << "information: " << std::endl;
        ks_[i].data.show_info();
    }
}

template<typename Key, typename Data>
Table<Key, Data>::iterator Table<Key, Data>::find_elem(const Key &key)
{
    for (size_t i = 0; i < size_; ++i)
    {
        if(ks_[i].key == key)
        {
            return iterator(&ks_[i]);
        }
    }
    return end();
}

template<typename Key, typename Data>
Table<Key, Data>::Table() noexcept:
        size_(0),
        capacity_(1),
        ks_(new ks_t [capacity_])
{
}

template<typename Key, typename Data>
Table<Key, Data>::Table(const Table &other)
requires std::copy_constructible<Data> :
        size_(other.size_),
        capacity_(other.capacity_),
        ks_(new ks_t [other.size_])
{
    for (size_t i = 0; i < size_; ++i)
    {
        ks_[i] = other.ks_[i];
    }
}

template<typename Key, typename Data>
Table<Key, Data>::Table(Table<Key, Data> &&other) noexcept :
        size_(other.size_),
        capacity_(other.capacity_),
        ks_(other.ks_)
{
    other.size_ = 0;
    other.capacity_ = 0;
    other.ks_ = nullptr;
}

template<typename Key, typename Data>
Data &Table<Key, Data>::operator[](size_t i)
{
    return ks_[i].data;
}

template<typename Key, typename Data>
const Data &Table<Key, Data>::operator[](size_t i) const
{
    return ks_[i].data;
}

template<typename Key, typename Data>
void Table<Key, Data>::push_back(const Key &key, const Data &data)
{
    iterator it = find_elem(key);
    if (it != end()) throw std::logic_error("Group with same index already exists");

    if (size_ == capacity_)
    {
        size_t new_capacity;
        if (capacity_ == 0)
        {
            new_capacity = 1;
        } else
        {
            new_capacity = capacity_ * 2;
        }
        auto *tmp = new ks_t [new_capacity];
        for (size_t i = 0; i < size_; ++i)
        {
            tmp[i] = ks_[i];
        }
        delete[] ks_;
        ks_ = tmp;
        capacity_ = new_capacity;
    }
    ks_[size_].key = key;
    ks_[size_].data = data;
    size_++;
}

