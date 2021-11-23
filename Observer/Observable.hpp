//
// Created by oleh.slabak on 11/23/2021.
//

#ifndef OBSERVER_OBSERVABLE_HPP
#define OBSERVER_OBSERVABLE_HPP
#include <vector>
#include <string>
#include <mutex>

template<typename> struct Observer;
template<typename T>
struct Observable {
    std::vector<Observer<T>*> observers;
    typedef std::recursive_mutex mutex_t;
    mutex_t mtx;
public:
    void notify(T &source, const std::string &filed_name)
    {
        std::scoped_lock<mutex_t> lock{mtx};
        for (auto observer : observers)
            if (observer)
                observer->field_changed(source, filed_name);


    }

    void subscribe(Observer<T> &observer)
    {
        std::scoped_lock<mutex_t> lock{mtx};
        observers.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer)
    {
        /*auto it = std::find(begin(observers), end(observers), &observer);
        if (it != end(observers))
            *it = nullptr;*/
        //-- device or resource busy: device or resource busy in case of mutex. Change to recursive
        std::scoped_lock<mutex_t> lock{mtx};
        observers.erase(
                remove(observers.begin(), observers.end(), &observer),
                observers.end() );
    }


};


#endif //OBSERVER_OBSERVABLE_HPP
