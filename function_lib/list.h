#pragma once
#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <iostream>

using namespace std;

template <class T>
class ListElem
{
protected:
    T data;
    ListElem<T>* next;
    ListElem<T>* prev;
public:
    ListElem(T _data);
    ~ListElem();
    T GetData();
    ListElem<T>* GetNext();
    ListElem<T>* GetPrev();

    void SetData(T _data);
    void SetNext(ListElem<T>* _next);
    void SetPrev(ListElem<T>* _prev);
    template <class T>
    friend ostream& operator<< (ostream& ostr, const ListElem<T>& A);
    template <class T>
    friend istream& operator >> (istream& istr, ListElem<T>& A);


};



template<class T>
inline ostream& operator<<(ostream& ostr, const ListElem<T>& A)
{
    ostr << A.data;
    return ostr;
}

template<class T>
inline istream& operator>>(istream& istr, ListElem<T>& A)
{
    istr >> A.data;
}
template<class T>
inline void ListElem<T>::SetData(T _data)
{
    data = _data;
}

template<class T>
inline void ListElem<T>::SetNext(ListElem* _next)
{
    next = _next;

}

template<class T>
inline void ListElem<T>::SetPrev(ListElem* _prev)
{
    prev = _prev;
}

template<class T>
inline ListElem<T>::ListElem(T _data)
{
    data = _data;
    next = nullptr;
    prev = nullptr;
}

template<class T>
inline ListElem<T>::~ListElem()
{
    next = nullptr;
    prev = nullptr;
}

template<class T>
inline T ListElem<T>::GetData()
{
    return data;
}

template<class T>
inline ListElem<T>* ListElem<T>::GetNext()
{
    return next;
}

template<class T>
inline ListElem<T>* ListElem<T>::GetPrev()
{
    return prev;
}









template <class T>
class List
{
protected:
    ListElem<T>* root;
    ListElem<T>* end;
    int count;
public:

    List();
    ~List();
    List(List<T>& other);

    void Ins(ListElem<T>* d, T elem);
    void InsFirst(T elem);
    void InsLast(T elem);

    List<T>& operator =(List<T>& other);

    ListElem<T>* GetFirst();
    ListElem<T>* GetLast();
    ListElem<T>* GetMiddle(T elem);

    bool IsEmpty() const;

    void DelFirst();
    void DelLast();
    void Del(ListElem<T>* d);

    template <class T>
    friend ostream& operator<< (ostream& ostr, const List<T>& A);
    template <class T>
    friend istream& operator >> (istream& istr, List<T>& A);

    int GetCount();
    void DelList();
    void DelListCir();

    bool Rotate();
    void Circle(int n);
    bool Rabbit();

};




template <class T>
ostream& operator<< (ostream& ostr, const List<T>& A)
{
    ListElem<T>* i = A.root;
    while (i != nullptr)
    {
        ostr << *i << "->";
        i = i->GetNext();
        if (i == nullptr)
            ostr << "NULL" << endl;
    }
    return ostr;
}

template <class T>
istream& operator >> (istream& istr, List<T>& A)
{

    int count;
    istr >> count;
    for (int i = 0; i < count; i++)
    {
        T d;
        istr >> d;
        A.InsLast(d);
    }
    return istr;
}


template <class T>
List<T>::List()
{
    root = nullptr;
    count = 0;
    end = nullptr;
}

template <class T>
List<T>::List(List<T>& other)
{
    this->root = nullptr;
    this->end = nullptr;
    this->count = other.count;
    int c = count;
    ListElem<T>* i = other.root;
    if (i != nullptr)
    {
        this->InsFirst(i->GetData());
        i = i->GetNext();
        c--;
    }

    while (c != 0)
    {
        this->InsLast(i->GetData());
        i = i->GetNext();
        c--;
    }
}
template<class T>
inline void List<T>::Ins(ListElem<T>* d, T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    tmp->SetNext(d->GetNext());
    tmp->SetPrev(d);
    d->GetNext()->SetPrev(tmp);
    count++;
}
template<class T>
inline void List<T>::InsFirst(T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    tmp->SetPrev(0);

    tmp->SetNext(root);
    if (root == nullptr)
        end = tmp;
    root = tmp;
    count++;
}
template<class T>
inline void List<T>::InsLast(T elem)
{
    ListElem<T>* tmp = new ListElem<T>(elem);
    if ((end == root) && (root != nullptr))
        root->SetNext(tmp);
    if (end != nullptr)
        end->SetNext(tmp);
    tmp->SetPrev(end);
    tmp->SetNext(nullptr);
    end = tmp;
    count++;
}
template <class T>
List<T>::~List()
{
    if(end->GetNext()==nullptr)
    this->DelList();
    else
        this->DelListCir();

}

template <class T>
List<T>& List<T>::operator =(List<T>& other)
{

    if (this == &other)
        return (*this);
    this->DelList();

    count = other.count;
    ListElem<T>* i = other.root;
    if (i != nullptr)
    {
        this->InsFirst(i->GetData());
        i = i->GetNext();
    }

    while (i != nullptr)
    {
        this->InsLast(i->GetData());
        i = i->GetNext();
    }
}

template<class T>
inline ListElem<T>* List<T>::GetFirst()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    return root;
}

template<class T>
inline ListElem<T>* List<T>::GetLast()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    return end;
}

template<class T>
inline ListElem<T>* List<T>::GetMiddle(T elem)
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        while (i != nullptr)
        {
            if (i->GetData() == elem)
            {
                break;
            }
            i = i->GetNext();

        }

        if (i == nullptr)
            throw logic_error("not_found");
        else
            return i;
    }
}


template <class T>
int List<T>::GetCount()
{
    return count;
}

template<class T>
inline void List<T>::DelList()
{
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* k = nullptr;
        while (i != nullptr)
        {
            k = i;
            i = i->GetNext();
            delete k;
        }

        this->root = nullptr;
        this->end = nullptr;
        count = 0;
    }
}

template<class T>
inline void List<T>::DelListCir()
{

    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;
        ListElem<T>* k = nullptr;
        if(root->GetNext()!=0)
        while (count != 0)
        {
            k = i;
            i = i->GetNext();
            delete k;
            count--;
        }
        this->root = nullptr;
        this->end = nullptr;
        count = 0;
    }
}



template<class T>
inline void List<T>::Circle(int n)
{
    if((n<0)||(n>=(*this).GetCount()))
        throw logic_error("invalid number of element");
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    ListElem<T>* i = (*this).root;
    ListElem<T>* j = (*this).root;
    int k = 0;
    while(j->GetNext()!=nullptr)
    {
        if (k == n)

            i = j;


        j = j->GetNext();
        k++;
    }
    j->SetNext(i);
}

template<class T>
inline bool List<T>::Rabbit()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if (root->GetNext()==nullptr)
        return false;
    ListElem<T>* i = (*this).root;
    ListElem<T>* j = (*this).root;
    i = i->GetNext();
    j = j->GetNext();
    if(j->GetNext()!=nullptr)
    j = j->GetNext();
    while ((j->GetNext()!=nullptr)&&(i!=j))
    {
        i = i->GetNext();
        j = j->GetNext();
        if (j->GetNext() != nullptr)
            j = j->GetNext();
    }
    if (i == j)
        return true;
    if (j->GetNext() == nullptr)
        return false;
}

template<class T>
inline bool List<T>::Rotate()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if ((*this).root->GetNext() == nullptr)
        return false;
    if (this->root != nullptr)
    {
        ListElem<T>* i = (*this).root;

        ListElem<T>* j = (*this).root->GetNext();
        i->SetNext(nullptr);
        i->SetPrev(j);
        while ((j->GetNext() != nullptr) && (j->GetNext() != (*this).root))
        {
            i = j;
            j = j->GetNext();
            i->SetNext(i->GetPrev());
            i->SetPrev(j);


        }
        if (j->GetNext() == nullptr)
        {
            return false;
        }

        if (j->GetPrev() == (*this).root)
        {

            return 1;
        }

    }

}

template<class T>
inline bool List<T>::IsEmpty() const
{
    return (count == 0);
}

template<class T>
inline void List<T>::DelFirst()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    ListElem<T>* tmp = root;
    root = root->GetNext();
    count--;
    delete tmp;
}

template<class T>
inline void List<T>::DelLast()
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    ListElem<T>* tmp = end;
    end = end->GetPrev();
    end->SetNext(nullptr);
    count--;
    delete tmp;
}

template<class T>
inline void List<T>::Del(ListElem<T>* d)
{
    if ((*this).IsEmpty())
        throw logic_error("list_is_empty");
    if (d->GetPrev() != nullptr)
        d->GetPrev()->SetNext(d->GetNext());
    if (d->GetNext() != nullptr)
        d->GetNext()->SetPrev(d->GetPrev());
    count--;
    delete d;
}
#endif  // INCLUDE_ADD_H_