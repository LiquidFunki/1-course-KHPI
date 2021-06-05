#ifndef LAB16_LIST_H
#define LAB16_LIST_H

#include "Book.h"



template<typename T>
class List{
    vector<T*> books;
public:
    List() = default;
    List(List &copy) = default;

    virtual ~List(){
        while (!books.empty()){
            books.pop_back();
        }
        books.clear();
        books.shrink_to_fit();
    }


    typedef typename std::vector<T*>::iterator iter;

    iter begin(){
        return books.begin();
    }

    iter end(){
        return books.end();
    }


    void addItem( T* item){
        this->books.push_back(item);
    }

    vector<T*> getBook (){
        return this->books;
    }

    void ShowAll(){
        for(T &elem : books){
            cout << elem.get() << endl;
        }
    }


};

#endif //LAB16_LIST_H