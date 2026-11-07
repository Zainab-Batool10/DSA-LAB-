#include <iostream>
#include <string>
using namespace std;
//n products, product has name, code, price
//input, print all input
// free memory

class products{
    string name;
    int code;
    int price;
    public:
        //products(): name("Noname"), code(63299){}
        void setter(string n, int c, int p){
            name = n;
            code = c;
            price = p;
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Code: "<<code<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<endl;
        }
};

int main(){
    int n;
    cout<<"Enter number of products: "<<endl;
    cin>>n;
    products* Products = new products[n];
    for(int i = 0; i<n; i++){
        string name;
        int code;
        int price;
        cout<<"Enter name, code and price of product "<<i+1<<": "<<endl;
        cin>>name>>code>>price;
        Products[i].setter(name,code,price);


    }
    cout<<"\nProduct List:\n";
    for(int i = 0; i<n;i++){
        Products[i].display();
    }
    delete[] Products;


    return 0;
}
