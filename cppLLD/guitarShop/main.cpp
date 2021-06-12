#include <iostream>
using namespace std;

class Shop {
    public:
        
        void getValByRef(char* ptr, int len) {
            for(int i=0;i<len;i++) {
                ptr[i] = name[i];
            }
        }

        char* getValDynamic() {
            char* ptr = NULL;
            ptr = new char[5];
            getValByRef(ptr, 5);
            return ptr;
        }
    private:
        char name[5] = "abcd";
};

int main() {
    Shop shop;
    cout << "my shop" << endl;
    // cout << "shop name: " << shop.getVal() << endl;
    char ptr[5];
    shop.getValByRef(ptr, 5);
    ptr[2] = 'f';
    cout << "shop name: " << ptr << endl;
    cout << "shop name: " << shop.getValDynamic() << endl;
    // cout << "shop name: " << shop.name << endl;
    return 0;
}