    #include<iostream>
    #include<string.h>
    using namespace std;

    class ShallowHero{
        public:
        char *name;

        void print(){
            cout<<"Name: "<<this->name<<endl;
        }

        void setName(char name[]){
           this->name=name;
        }
        ~ShallowHero(){
            cout<<"Destructor called "<<endl;
        }
    };

    class DeepHero{
        public:
        char *name;

        void print(){
            cout<<"Name: "<<this->name<<endl;   
        }

        DeepHero() : name(nullptr) {};
        DeepHero(DeepHero& temp){
            char *ch= new char[strlen(temp.name)+1];
            strcpy(ch, temp.name);
            this->name=ch;
        }

        void setName(char name[]){
            this->name=name;
        }
    };

    int main(){
        ShallowHero shallow1;
        cout<<"Shallow Copy"<<endl;
        char name[8] = "Shallow";
        shallow1.setName(name);
        shallow1.print();

        ShallowHero shallow2(shallow1);
        shallow2.print();

        shallow1.name[0] = 'M';
        shallow1.print();
        shallow2.print();

        DeepHero deep1;
        cout<<"Deep Copy"<<endl;
        char name1[8] = "Shallow";
        deep1.setName(name1);
        deep1.print();

        DeepHero deep2(deep1);
        deep2.print();

        deep1.name[0] = 'M';
        deep1.print();
        deep2.print();
    }