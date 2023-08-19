#include<iostream>

template<class T>
class shared_ptr;

template<class T>
  class shared_ptr
    {
    private:
        T* pObj;
        T value;

        static int count; 
        int ownCount = 0;
         static shared_ptr<T>* helper;   
    public:
        void reset()
        {
            (*helper).ownCount--;
            (*helper).pObj = nullptr;
            if (ownCount == 0)
            {
                delete pObj;
            }
            else if (count == 1)
            {
                pObj = nullptr;
                count = 0;
            }
            else {
                count--;
                pObj = NULL;
            }
            
        }


    public:
        ~shared_ptr() {
            if (ownCount == 0){
                std::cout << "I havent a friend\n";
                delete pObj;
      
            }
            else if (count == 1&&ownCount>=1)
            {
                pObj = nullptr;
                count--;
                std::cout << "I had a friend\n";
            }
            else  {
                pObj = NULL;
                std::cout << "I had a friend but i leave them\n";
                count--;
            }
        }

        shared_ptr()
        {

        }
    public:
        bool can = false;
        shared_ptr& operator=(shared_ptr<T>& myObj) {
            if (myObj.pObj != helper.pObj&&helper.ownCount>0)
            {
                helper.ownCount--;
            }  
            count++;
            return myObj;                  
        }
        void swap(const shared_ptr<T> &myObj)
        {
            if (ownCount == 0)
            {
                delete pObj;
                pObj = myObj.pObj;
            }

            else if (count == 1 && ownCount >= 1)
            {
                pObj = nullptr;
                count = 0;
                pObj = myObj.pObj;

            }

            else {
                pObj = NULL;
                count--;
                pObj - myObj.pObj;
            }
            helper.ownCount = myObj.ownCount;
            helper.pObj = myObj.pObj;
            
        }
    public:
        shared_ptr(T myObj) {
            value = myObj;
            pObj = &value;
        }
    public:
        shared_ptr(shared_ptr<T> &myObj) {
            helper = &myObj;
            pObj = myObj.pObj;
            (*helper).ownCount++;
            count++;
        }

        T get()
        {
          
            return (*pObj);
        }
    public:
        void set(T value)
        {
            (*helper).ownCount = 0;
            (*helper).pObj = nullptr;
            helper = nullptr;
            if (ownCount == 0)
            {
                delete pObj;
            }
            else if (count == 1)
            {
                pObj = nullptr;
                count = 0;
            }
            else {
                count--;
                pObj = NULL;
            }
            pObj = &value;
        }

        public:
         int operator[](int index)
        {
            pObj += index;
            return (*pObj);
        }
         public:
        bool operator==(const shared_ptr<T> &ref)
        {
            if (ref.pObj == pObj)
            {
                return true;
            }
            else {
                return false;
            }
        }     
  };



template<typename T>
int shared_ptr<T>::count = 0;





